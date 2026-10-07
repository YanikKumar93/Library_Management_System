# 📚 Library Management System

A **menu-driven, console-based Library Management System** developed in the **C programming language** as a Software Development Laboratory project.

The system automates basic library operations such as book management, student management, inventory tracking, book issue/return, authentication, and fine management.

---

## 📌 Project Overview

Managing library records manually can be time-consuming and may lead to errors. This project provides a simple computer-based solution for managing common library operations.

The system provides separate access for:

- **Administrator**
- **Student**

All important records are stored using **file handling**, allowing the data to remain available even after the program is closed.

---

## 🎯 Objectives

- Automate the basic day-to-day operations of a library.
- Provide separate access for administrators and students.
- Maintain organised records of books, students, issues, returns, and fines.
- Track total, available, and issued copies of books.
- Calculate and monitor pending fines.
- Store records permanently using file handling.
- Apply fundamental C programming concepts in a practical project.

---

## ⚙️ Main Features

### 🔐 Authentication

- Admin login
- Student login
- Role-based access
- Different menus based on the user's role

### 📖 Book Management

**Administrator can:**
- Add books
- Delete books
- Manage book records
- Manage inventory

**Student can:**
- Search for books
- Issue available books
- Return books

Book records include information such as:

- Book ID
- Title
- Author
- Category
- Number of copies

### 👨‍🎓 Student Management

The system maintains student records including:

- Student ID
- Student name
- Issued books
- Pending fines

The administrator can view student records to track issued books and fines.

### 📦 Inventory Management

The inventory module maintains:

- Total copies
- Available copies
- Issued copies

The values are automatically updated when books are issued or returned.

### 💰 Fine Management

The system:

- Calculates fines for late returns.
- Maintains pending fine records.
- Allows administrators to monitor unpaid fines.
- Allows students to view their own fines.

---

## 🏗️ System Modules

```text
Library Management System
│
├── Authentication
│   ├── Admin Login
│   └── Student Login
│
├── Book Management
│   ├── Add Books
│   ├── Delete Books
│   ├── Search Books
│   ├── Issue Books
│   └── Return Books
│
├── Student Management
│   ├── Student Records
│   └── Issued Books
│
├── Inventory Management
│   ├── Total Copies
│   ├── Available Copies
│   └── Issued Copies
│
└── Fine Management
    ├── Calculate Fine
    ├── Pending Fines
    └── Fine Records
```

---

## 🔄 Application Workflow

```text
        Start
          │
          ▼
    Login Screen
          │
     ┌────┴────┐
     ▼         ▼
   Admin     Student
     │         │
     ▼         ▼
Admin Menu  Student Menu
     │         │
     ├── Books ├── Search Books
     ├── Users ├── Issue Books
     ├── Stock ├── Return Books
     └── Fines └── View Fines
          │
          ▼
      File Storage
          │
          ▼
         Exit
```

---

## 💻 Technologies Used

| Technology | Purpose |
|---|---|
| **C** | Main programming language |
| **File Handling** | Permanent data storage |
| **Structures** | Organising related records |
| **Arrays** | Storing multiple records |
| **Functions** | Modular program design |
| **Control Statements** | Program flow and decision making |

---

## 🧠 C Programming Concepts Used

### Control Flow

The project uses:

- `if`
- `if-else`
- `switch-case`
- `for`
- `while`
- `do-while`

These are used for login verification, menu navigation, searching, checking availability, issuing and returning books, and calculating fines.

### Arrays

Arrays are used to store multiple book and student records while the program is running.

### Structures

Structures are used to group related information for:

- Books
- Students
- Issue records
- Fine records

### Functions

The project is divided into separate functions to keep the program organised and easier to test and modify.

### File Handling

File handling is used to permanently store records.

Functions used include:

```c
fopen()
fclose()
fread()
fwrite()
fprintf()
fscanf()
```

---

## 🖥️ Hardware & Software Requirements

### Hardware

- **Processor:** Intel i3 or above
- **RAM:** 4 GB minimum
- **Storage:** 100 MB free space

### Software

- **Operating System:** Windows / Linux
- **Programming Language:** C
- **Compiler:** GCC / Code::Blocks / Turbo C

---

## 🚀 How to Run

### 1. Clone the Repository

```bash
git clone <repository-url>
```

### 2. Open the Project

Navigate to the project directory:

```bash
cd Library-Management-System
```

### 3. Compile the Program

Using GCC:

```bash
gcc main.c -o library
```

### 4. Run the Program

On Windows:

```bash
library.exe
```

On Linux:

```bash
./library
```

> Replace `main.c` with the actual source filename if your project uses a different filename.

---

## 📂 Suggested Project Structure

```text
Library-Management-System/
│
├── README.md
├── main.c
├── books.dat
├── students.dat
├── issues.dat
├── fines.dat
└── screenshots/
```

The exact file structure may vary depending on the implementation.

---

## 👥 User Roles

### 👨‍💼 Administrator

The administrator can:

- Add books
- Delete books
- Manage inventory
- View student records
- Monitor pending fines

### 👨‍🎓 Student

Students can:

- Log in
- Search for books
- Issue books
- Return books
- View fines

### 🤖 System

The system automatically:

- Maintains book records
- Stores student information
- Updates inventory
- Calculates fines
- Maintains issue and return records

---

## 🔒 Security

The system uses authentication before allowing users to access the application.

Role-based access ensures that students cannot access administrator-only functions such as deleting books or managing inventory.

---

## 📈 Future Scope

The current project is a console-based C application. It can be extended in the future with features such as:

- Graphical User Interface
- Online library access
- Database integration
- Web-based dashboard
- Online book reservations
- Email notifications
- Advanced search and filtering
- Automated fine payment
- Cloud-based record storage

---

## 📋 Project Information

**Project:** Library Management System  
**Type:** Software Development Laboratory Project  
**Language:** C  
**Application:** Console-based  
**Level:** B.Tech First Year  

### Team Members

| Name | Roll Number |
|---|---|
| Yanik Kumar | 2601020023 |
| Ayush Kumar | 2601020018 |
| Arav Singh | 2601020003 |
| Nehal Gupta | 2601020025 |

---

## 📜 Conclusion

The **Library Management System** automates important library operations including book management, student management, inventory tracking, fine calculation, authentication, and issue/return management.

The project demonstrates how fundamental C programming concepts such as **control flow, arrays, structures, functions, and file handling** can be combined to build a practical application.

---

## ⭐ Acknowledgement

This project was developed as part of the **Software Development Laboratory** for **B.Tech Electronics and Communication Engineering (First Year)**.
