import serial
import time

# Configuration
SERIAL_PORT = 'COM4'  # Replace with your Arduino's Serial port
BAUD_RATE = 9600
OUTPUT_FILE = 'C:/Users/M/Documents/PlatformIO/Projects/Sound/sound_data.txt'
DURATION = 60  # Time duration to capture data in seconds

def main():
    # Open Serial port
    ser = serial.Serial(SERIAL_PORT, BAUD_RATE, timeout=1)
    
    # Give some time for the Serial connection to establish
    time.sleep(2)
    
    # Open file for writing
    with open(OUTPUT_FILE, 'w') as file:
        start_time = time.time()
        while True:
            # Read line from Serial port
            line = ser.readline().decode('utf-8').strip()
            if line:
                print(line)
                file.write(f"{line}\n")
            
            # Check if 60 seconds have passed
            if time.time() - start_time >= DURATION:
                print(f"Data collection complete. Data saved to {OUTPUT_FILE}")
                break
    
    # Close Serial port
    ser.close()

if __name__ == "__main__":
    main()
