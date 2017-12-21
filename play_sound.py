import os
import serial

notes = [523.25, 587.33, 659.26, 698.46, 783.99, 880, 987.77, 1046.5]

def beeping(frequency, duration):
    os.system("beep -f {} -l {}".format(str(frequency), str(duration)))

if __name__ == "__main__":
    ser = serial.Serial("/dev/ttyACM6", 9600)
    delay_time = ser.readline()
    print(delay_time)

    while 1:
        val = ser.readline()
        print(val)
        for i, note in enumerate(notes):
            if int(val) == i:
                print(i)
                beeping(note, delay_time)
#code to make beep sound from laptop with some reading from serial port
