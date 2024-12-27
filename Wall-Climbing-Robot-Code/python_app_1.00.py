import tkinter as tk
import serial


def send_command(command):
    ser.write(command.encode())


def move_up():
    send_command('1')  # Send '1' to move up


def move_down():
    send_command('2')  # Send '2' to move down


def hold():
    send_command('3')  # Send '3' to hold


# Create serial connection to Arduino
ser = serial.Serial('COM5', 9600)  # Replace 'COM3' with the appropriate port

# Create GUI window
window = tk.Tk()
window.title("Arduino Control")

# Create buttons to move up and down
up_button = tk.Button(window, text="Move Up", command=move_up)
up_button.pack()

down_button = tk.Button(window, text="Move Down", command=move_down)
down_button.pack()

hold_button = tk.Button(window, text="hold", command=hold)
hold_button.pack()

# Run the GUI
window.mainloop()
