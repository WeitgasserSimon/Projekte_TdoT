import customtkinter as ctk

class ReverseText:
    def __init__(self, root) -> None:
            self.root = root
            self.root.title("Text Reverser")

            self.text_field = ctk.CTkEntry(root, width = 200)
            self.tec_field.pack(pady=20)

            self.button = ctk.CTkButton(root, text="reserve", command=self.reverse_text)
            self.button.pack(pady=20)
        
        def reverse_text(cls)


if __name__ == "__main__":
    root = ctk.CTk()
    app = ReverseText(root)
    root.mainloop()