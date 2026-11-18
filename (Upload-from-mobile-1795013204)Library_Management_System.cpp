// Project: Library Management System
// Language: C++
// Description: A menu-driven library system using classes, vectors,
// file handling, searching, issuing, and returning books.

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <limits>
using namespace std;

class Book
{
public:
    int id;
    string title;
    string author;
    bool issued;

    Book(int bookId = 0, string bookTitle = "", string bookAuthor = "",
         bool isIssued = false)
        : id(bookId), title(bookTitle), author(bookAuthor), issued(isIssued) {}
};

class Library
{
private:
    vector<Book> books;
    const string filename = "library_books.txt";

    int findBookIndex(int bookId) const
    {
        for (int i = 0; i < static_cast<int>(books.size()); i++)
            if (books[i].id == bookId)
                return i;
        return -1;
    }

    void saveToFile() const
    {
        ofstream file(filename);
        for (const Book &book : books)
        {
            file << book.id << '|'
                 << book.title << '|'
                 << book.author << '|'
                 << book.issued << '\n';
        }
    }

    void loadFromFile()
    {
        ifstream file(filename);
        if (!file)
            return;

        string line;
        while (getline(file, line))
        {
            stringstream ss(line);
            string idText, title, author, issuedText;

            if (getline(ss, idText, '|') &&
                getline(ss, title, '|') &&
                getline(ss, author, '|') &&
                getline(ss, issuedText))
            {
                try
                {
                    books.emplace_back(stoi(idText), title, author,
                                        issuedText == "1");
                }
                catch (...)
                {
                    // Skip any invalid record in the data file.
                }
            }
        }
    }

public:
    Library()
    {
        loadFromFile();
    }

    void addBook()
    {
        int id;
        string title, author;

        cout << "Enter book ID: ";
        cin >> id;

        if (findBookIndex(id) != -1)
        {
            cout << "A book with this ID already exists.\n";
            return;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter book title: ";
        getline(cin, title);
        cout << "Enter author name: ";
        getline(cin, author);

        books.emplace_back(id, title, author, false);
        saveToFile();
        cout << "Book added successfully.\n";
    }

    void displayBooks() const
    {
        if (books.empty())
        {
            cout << "No books are available.\n";
            return;
        }

        cout << "\n------ Library Books ------\n";
        cout << "ID\tTitle\t\tAuthor\t\tStatus\n";

        for (const Book &book : books)
        {
            cout << book.id << "\t"
                 << book.title << "\t\t"
                 << book.author << "\t\t"
                 << (book.issued ? "Issued" : "Available") << '\n';
        }
    }

    void searchBook() const
    {
        int id;
        cout << "Enter book ID to search: ";
        cin >> id;

        int index = findBookIndex(id);
        if (index == -1)
        {
            cout << "Book not found.\n";
            return;
        }

        const Book &book = books[index];
        cout << "Book found:\n";
        cout << "ID: " << book.id << '\n';
        cout << "Title: " << book.title << '\n';
        cout << "Author: " << book.author << '\n';
        cout << "Status: " << (book.issued ? "Issued" : "Available") << '\n';
    }

    void issueBook()
    {
        int id;
        cout << "Enter book ID to issue: ";
        cin >> id;

        int index = findBookIndex(id);
        if (index == -1)
        {
            cout << "Book not found.\n";
            return;
        }

        if (books[index].issued)
        {
            cout << "This book is already issued.\n";
            return;
        }

        books[index].issued = true;
        saveToFile();
        cout << "Book issued successfully.\n";
    }

    void returnBook()
    {
        int id;
        cout << "Enter book ID to return: ";
        cin >> id;

        int index = findBookIndex(id);
        if (index == -1)
        {
            cout << "Book not found.\n";
            return;
        }

        if (!books[index].issued)
        {
            cout << "This book was not issued.\n";
            return;
        }

        books[index].issued = false;
        saveToFile();
        cout << "Book returned successfully.\n";
    }
};

int main()
{
    Library library;
    int choice;

    do
    {
        cout << "\n===== LIBRARY MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Book\n";
        cout << "2. Display All Books\n";
        cout << "3. Search Book\n";
        cout << "4. Issue Book\n";
        cout << "5. Return Book\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice))
        {
            cout << "Invalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice)
        {
        case 1:
            library.addBook();
            break;
        case 2:
            library.displayBooks();
            break;
        case 3:
            library.searchBook();
            break;
        case 4:
            library.issueBook();
            break;
        case 5:
            library.returnBook();
            break;
        case 0:
            cout << "Thank you for using the Library Management System.\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);

    return 0;
}
