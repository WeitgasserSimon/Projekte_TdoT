import customtkinter as ctk

class Task:
    def __init__(self):
        self.title = ""
        self.description = ""
        self.due_date = ""
        self.is_completed = False

class TodoList(Task):
    def __init__(self):
        super().__init__()
        self.liste = []

    def createtodo(self, title: str, description: str, due_date: str):
        new_task = Task()
        new_task.title = title
        new_task.description = description
        new_task.due_date = due_date
        new_task.is_completed = False
        return new_task

    def addtodo(self, entry_title: str, entry_description: str, entry_due_date: str) -> list:
        new_task = self.createtodo(entry_title, entry_description, entry_due_date)
        self.liste.append(new_task)
        return self.liste

    def showtodos(self):
        new_window = ctk.CTkToplevel(root)
        new_window.title("To-Do-List")
        new_window.geometry("800x600")

        label = ctk.CTkLabel(new_window, text="To-Do-List")
        label.grid(row=0, column=0, padx=10, pady=10)

        row = 1
        for task in self.liste:
            label_title = ctk.CTkLabel(new_window, text=task.title)
            label_title.grid(row=row, column=0, padx=10, pady=10)
            label_description = ctk.CTkLabel(new_window, text=task.description)
            label_description.grid(row=row, column=1, padx=10, pady=10)
            label_due_date = ctk.CTkLabel(new_window, text=task.due_date)
            label_due_date.grid(row=row, column=2, padx=10, pady=10)
            label_is_completed = ctk.CTkLabel(new_window, text=str(task.is_completed))
            label_is_completed.grid(row=row, column=3, padx=10, pady=10)
            row += 1

        

if __name__ == "__main__":
    root = ctk.CTk()
    root.title("Tasks")
    root.geometry("800x600")

    todo_list = TodoList()

    # GUI-Elemente außerhalb der Klasse definieren
    label_title = ctk.CTkLabel(root, text="Title")
    label_title.grid(row=0, column=0, padx=10, pady=10)
    entry_title = ctk.CTkEntry(root, width=50)
    entry_title.grid(row=0, column=1, padx=10, pady=10)

    label_description = ctk.CTkLabel(root, text="Description")
    label_description.grid(row=1, column=0, padx=10, pady=10)
    entry_description = ctk.CTkEntry(root, width=50)
    entry_description.grid(row=1, column=1, padx=10, pady=10)

    label_due_date = ctk.CTkLabel(root, text="Due Date")
    label_due_date.grid(row=2, column=0, padx=10, pady=10)
    entry_due_date = ctk.CTkEntry(root, width=50)
    entry_due_date.grid(row=2, column=1, padx=10, pady=10)

    button_add = ctk.CTkButton(root, text="Add Task", command=lambda: todo_list.addtodo(entry_title.get(), entry_description.get(), entry_due_date.get()))
    button_add.grid(row=3, column=1, padx=10, pady=10)

    button_show = ctk.CTkButton(root, text="Show Task", command=todo_list.showtodos)
    button_show.grid(row=3, column=2, padx=10, pady=10)

    root.mainloop()
