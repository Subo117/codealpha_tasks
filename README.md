
# ✅ To - Do List - C++ Console App

A simple **To-Do List Manager** built using **C++**. This console-based application allows users to manage their daily tasks by adding, viewing, and updating task status. Task data is stored in a CSV file for persistence.

---

## 📌 Features

- ➕ Add a new task with a due date and status
- 📋 View all **Pending** tasks
- ✔️ View all **Completed** tasks
- 🔁 Mark a task as **Completed**
- 💾 Stores task data in a `task.csv` file

---

## 📂 Files in This Project

| File         | Description                            |
|--------------|----------------------------------------|
| `main.cpp`   | Main C++ source code                   |
| `task.csv`   | Created automatically to store tasks   |
| `README.md`  | Project overview & instructions        |

---

## 🛠 How to Run

1. **Install a C++ compiler** like `g++` (e.g., via MinGW on Windows).
2. **Compile the program**:
   ```bash
   g++ main.cpp -o TaskManager
   ```
3. **Run the executable**:
   ```bash
   ./TaskManager
   ```

---

## 🧪 Sample Output

```plaintext
-------------- TO - DO LIST --------------
1. Add Tasks
2. Show Pending Tasks
3. Show Completed Tasks
4. Mark Task As Complete
5. Exit
Choose option:
```

---

## 📄 Sample task.csv file

```csv
Buy groceries,2025-06-22,Pending
Complete assignment,2025-06-25,Completed
```

---

