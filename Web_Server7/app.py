# websocket connecting to favoriot
# basic login and interface
# filter data
# display data
from flask import Flask, request, redirect, url_for, render_template
from flask_socketio import SocketIO, emit
import asyncio
import socketio
import threading

USERNAME = "admin"
PASSWORD = "admin"
INTERFACE = False
SESSION = False
FORECAST = False
Apikey = ""
dev_id = ""

# Create a Flask application instance
app = Flask(__name__)
# Set a secret key for Flask (used for session security)
app.config['SECRET_KEY'] = 'XK-FROST01'
# Initialize Flask-SocketIO to add WebSocket support to the Flask app
socketio_flask = SocketIO(app)
# Initialize the async client for the SocketIO connection
sio = socketio.AsyncClient(ssl_verify=False)

# Global list to store the latest 10 data points
data_buffer = []

# Root path
@app.route('/')
def index():
    return redirect(url_for('login'))

# Login page
@app.route('/login', methods=['POST', 'GET'])
def login():
    global SESSION
    error = None
    if request.method == 'POST':
        if valid_login(request.form.get('username', ''), request.form.get('password', '')):
            SESSION = True  # Set session to true upon successful login
            return redirect(url_for('home'))
        else:
            error = 'Invalid username/password'
    return render_template('login.html', error=error)

# Home page
@app.route('/home')
def home():
    global INTERFACE
    print(INTERFACE)
    if SESSION:
        return render_template('home.html', interface=INTERFACE, data_buffer=data_buffer)
    else:
        return redirect(url_for('login'))

# Input page
@app.route('/interface', methods=['GET', 'POST'])
def interface():
    global INTERFACE, dev_id, Apikey
    error = None
    if request.method == 'POST':
        dev_id = request.form.get('ID', '')
        Apikey = request.form.get('APIKEY', '')
        print("Received Apikey: " + Apikey)  # Log the received Apikey
        if dev_id and Apikey:
            INTERFACE = True
            threading.Thread(target=run_websocket_task, daemon=True).start()
            return redirect(url_for('home'))
        else:
            error = 'Both Device Developer ID and API KEY are required'
    return render_template('interface.html', error=error)

@app.route('/forecast', methods=['POST', 'GET'])
def forecast():
    global date_time, FORECAST
    if request.method == 'POST':
        # Get the selected start date from the form
        date_time = request.form.get('startDate')
        print(f"Selected Start Date: {date_time}")  # Log the date selected
        FORECAST = True
        threading.Thread(target=run_websocket_task, daemon=True).start()
        return render_template('forecast.html', data_buffer=data_buffer, date_time=date_time)
    else:
        return render_template('forecast.html', data_buffer=data_buffer, date_time=date_time)


def valid_login(username, password):
    return username == USERNAME and password == PASSWORD

def interface_data(ID, APIKEY):
    global dev_id, Apikey
    dev_id = ID
    Apikey = APIKEY
    return dev_id, Apikey

# Event: Successful connection
@sio.event
async def connect():
    print("Connected to Favoriot WebSocket server")

# Event: Connection error
@sio.event
async def connect_error(data):
    print("Connection failed:", data)

# Event: Disconnection
@sio.event
async def disconnect():
    print("Disconnected from Favoriot WebSocket server")

# Emit a message to push data
async def emit_message():
    global Apikey
    try:
        await sio.emit('v2/streams', {
            'request': 'listen',
            'apikey': Apikey
        })
        print("Data pushed successfully")
    except Exception as e:
        print("Error during push:", e)

async def emit_message1():
    global Apikey, date_time, dev_id
    try:
        # Ensure date_time is in the expected format for the query
        if date_time:
            formatted_date = f"[{date_time} TO NOW]"
        else:
            formatted_date = "[NOW TO NOW]"  # Default to no filter if date is not set

        await sio.emit('v2/streams',{
          'request': "pull",
          'apikey':"your api key",
          'parameters': {
                'created_from_to': formatted_date,
                'device_developer_id': dev_id,
           }
        })
        print("Data pushed successfully with date filter:", formatted_date)
    except Exception as e:
        print("Error during push:", e)


# Listen for incoming data streams (listen request)
@sio.on('v2/streams')
async def listen_stream(data):
    if 'results' in data:
        for result in data['results']:
            if result.get('device_developer_id') == 'Hibiscus_Sense@nuraizatulsyakila01':
                filtered_data = {
                    "temperature": result['data'].get('temperature'),
                    "humidity": result['data'].get('humidity'),
                    "barometer": result['data'].get('barometer'),
                    "altitude": result['data'].get('altitude')
                }
                # Add filtered data to data_buffer
                data_buffer.append(filtered_data)
                # Ensure data_buffer only keeps the latest 10 entries
                if len(data_buffer) > 10:
                    data_buffer.pop(0)
                # Print filtered data to the terminal
                #print("Filtered Data:")
                #print("{:<15} {:<10}".format('Parameter', 'Value'))
                #print("-" * 25)
                #for key, value in filtered_data.items():
                    #print("{:<15} {:<10}".format(key, value))
                socketio_flask.emit('update_data', filtered_data)
        print("\nReceived stream update ", data)
    else:
        print("Unexpected data format:", data)

# WebSocket Task Runner 
def run_websocket_task(): 
    asyncio.run(main())

# Main function to run the WebSocket client
async def main():
    global FORECAST
    try:
        # Connect to Favoriot WebSocket server
        await sio.connect('wss://io.favoriot.com')
        print("WebSocket client connected")
        # Example: Push a message
        if FORECAST ==True:
            await emit_message1()
        else:
            await emit_message()

        # Wait to keep the connection open
        await sio.wait()
    except Exception as e:
        print("Error in WebSocket client:", e)

if __name__ == "__main__":
    socketio_flask.run(app, debug=True, allow_unsafe_werkzeug=True)