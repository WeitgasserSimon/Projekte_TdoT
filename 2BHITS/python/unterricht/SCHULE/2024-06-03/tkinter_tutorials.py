# File: tkinter_tutorial.py
# Author: Your Name
# Date: 2024-06-02
# Brief: A simple tkinter tutorial demonstrating a basic GUI application.

import tkinter as tk
from tkinter import messagebox

# Function to be called when button is clicked
def on_button_click():
    messagebox.showinfo("Information", "Button was clicked!")

# Create the main application window
root = tk.Tk()
root.title("Simple Tkinter Tutorial")

# Create a label widget
label = tk.Label(root, text="Hello, Tkinter!")
label.pack(pady=10)

# Create a button widget
button = tk.Button(root, text="Click Me", command=on_button_click)
button.pack(pady=10)

# Start the main event loop
root.mainloop()
