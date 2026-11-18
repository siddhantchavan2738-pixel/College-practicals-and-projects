# Library Management System

A menu-driven C++ mini project for managing a small library.

## Features
- Add books with unique IDs
- Display all books and their availability
- Search for a book by ID
- Issue an available book
- Return an issued book
- Save book records in `library_books.txt` so they remain after restarting

## Requirements
- C++ compiler supporting C++11 or later

## Compile and run
```bash
g++ Library_Management_System.cpp -o library
./library
```

On Windows:
```bash
g++ Library_Management_System.cpp -o library.exe
library.exe
```

The program creates `library_books.txt` in the working directory when book records are saved.
