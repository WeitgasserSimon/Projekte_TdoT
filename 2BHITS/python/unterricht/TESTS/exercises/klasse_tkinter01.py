import tkinter as tk

class MyApp:
    def __init__(self, root):
        self.root = root
        self.root.title("Tkinter Beispiel mit Klasse")

        self.label = tk.Label(root, text="Gib etwas ein:")
        self.label.pack(pady=5)

        self.entry = tk.Entry(root)
        self.entry.pack(pady=5)

        self.button = tk.Button(root, text="Anzeigen", command=self.display_text)
        self.button.pack(pady=5)

        self.output_label = tk.Label(root, text="")
        self.output_label.pack(pady=5)

    def display_text(self):
        entered_text = self.entry.get()
        self.output_label.config(text=entered_text)

if __name__ == "__main__":
    root = tk.Tk()
    app = MyApp(root)
    root.mainloop()
