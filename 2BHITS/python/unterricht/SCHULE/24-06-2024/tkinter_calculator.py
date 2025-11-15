import customtkinter as ctk
import math

# Funktionsdefinitionen
def factorial(n):
    if n == 0:
        return 1
    else:
        return n * factorial(n-1)

def evaluate_expression(expression):
    try:
        # Fakultät in den Ausdruck einfügen
        expression = expression.replace('!', 'factorial')
        allowed_names = {
            k: v for k, v in math.__dict__.items() if not k.startswith("__")
        }
        allowed_names.update({
            'abs': abs,
            'round': round,
            'factorial': factorial
        })
        result = eval(expression, {"__builtins__": None}, allowed_names)
        return str(result)
    except Exception as e:
        return "Error"

def button_click(value):
    current_text = entry.get()
    entry.delete(0, ctk.END)
    entry.insert(0, current_text + value)

def clear_entry():
    entry.delete(0, ctk.END)

def calculate_result():
    current_text = entry.get()
    result = evaluate_expression(current_text)
    entry.delete(0, ctk.END)
    entry.insert(0, result)

def create_button(root, text, row, col, width=90, height=75, command=None):
    if text == "=":
        cmd = calculate_result
    elif text == "C":
        cmd = clear_entry
    else:
        cmd = command or (lambda b=text: button_click(b))
    
    btn = ctk.CTkButton(master=root, text=text, command=cmd, width=width, height=height, font=("Arial", 18))
    btn.grid(row=row, column=col, padx=5, pady=5)
    return btn

def main():
    # Erstellen Sie das Hauptfenster
    root = ctk.CTk()
    root.title("Wissenschaftlicher Taschenrechner")
    root.geometry("500x700")

    # Eingabefeld
    global entry
    entry = ctk.CTkEntry(master=root, width=480, height=50, font=("Arial", 24))
    entry.grid(row=0, column=0, columnspan=5, padx=10, pady=10)

    # Schaltflächen-Layout
    buttons = [
        '7', '8', '9', '/', 'sqrt',
        '4', '5', '6', '*', 'pow',
        '1', '2', '3', '-', 'sin',
        '0', '.', '=', '+', 'cos',
        '(', ')', 'C', 'tan', 'log',
        'exp', 'asin', 'acos', 'atan', 'pi',
        'e', 'abs', 'round', '!', 'ln'
    ]

    row_val = 1
    col_val = 0

    for button in buttons:
        create_button(root, button, row_val, col_val)
        
        col_val += 1
        if col_val > 4:
            col_val = 0
            row_val += 1

    # Starten Sie die Hauptschleife
    root.mainloop()

if __name__ == "__main__":
    main()
    