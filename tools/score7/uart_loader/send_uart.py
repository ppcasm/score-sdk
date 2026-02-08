#!/usr/bin/python3.8

import sys
import serial
from datetime import datetime

SHOW_PRINTF = 1

CHUNK_SIZE = 1

def show_progress(current, total):
    progress = (current / total) * 100
    sys.stdout.write('\rUploading: {0}%'.format(int(progress)))
    sys.stdout.flush()

def main():

    executable = open(sys.argv[2], 'rb').read()
    executable_size = len(executable);
    print(f"Sending {executable_size} bytes...");

    with serial.Serial(sys.argv[1], baudrate=115200, parity='E', stopbits=1, timeout=1) as ser:
        ser.write(executable_size.to_bytes(4, byteorder='little'))
        ser.flush()
        ser.read(1)
        ser.flush()

        start_time = datetime.now()

        for i in range(0, len(executable)+1, CHUNK_SIZE):
            ser.write(executable[i:i + CHUNK_SIZE])
            ser.flush()

            show_progress(i, executable_size)

        print('\nTime elapsed: {0} (hh:mm:ss)'.format(str(datetime.now() - start_time)).split('.')[0])

        if(SHOW_PRINTF):
            while(1):
                ser.flush()
                ser.read(1)
                ser.flush()
                print(ser.readline().strip().decode("utf-8"))

        
if __name__ == "__main__":
     if(len(sys.argv) != 3):
        print('Wrong usage: {0} <PORT> <BINARY>'.format(sys.argv[0]))
        exit()

     main()
