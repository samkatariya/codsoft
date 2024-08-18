#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

// Structure to represent a Book
struct Book {
    string title;
    string author;
    string isbn;
    bool available;

    Book(const string& title, const string& author, const string& isbn, bool available = true)
        : title(title), author(author), isbn(isbn), available(available) {}
};

// Structure to represent a Borrower
struct Borrower {
    string name;
    vector<Book*> borrowedBooks;  // Store pointers to borrowed books
};

// Function to add a book to the library
void addBook(vector<Book>& books) {
    string title, author, isbn;
    cout << "Enter book title: ";
    getline(cin, title);
    cout << "Enter author name: ";
    getline(cin, author);
    cout << "Enter ISBN: ";
    getline(cin, isbn);
    books.emplace_back(title, author, isbn);
    cout << "Book added: " << title << endl;
}

// Function to search for books
vector<const Book*> searchBooks(const vector<Book>& books) {
    string query;
    cout << "Enter search query (title, author, ISBN): ";
    getline(cin, query);
    vector<const Book*> results;
    for (const auto& book : books) {
        if (book.title.find(query) != string::npos || book.author.find(query) != string::npos || book.isbn.find(query) != string::npos) {
            results.push_back(&book);
        }
    }
    return results;
}

// Function to check out a book
void checkoutBook(vector<Book>& books, Borrower& borrower) {
    string isbn;
    cout << "Enter ISBN of the book to check out: ";
    getline(cin, isbn);
    for (auto& book : books) {
        if (book.isbn == isbn && book.available) {
            book.available = false;
            borrower.borrowedBooks.push_back(&book);
            cout << "Checked out: " << book.title << endl;
            return;
        }
    }
    cout << "Book not found or unavailable." << endl;
}

// Function to return a book
void returnBook(Borrower& borrower) {
    string isbn;
    cout << "Enter ISBN of the book to return: ";
    getline(cin, isbn);
    for (auto it = borrower.borrowedBooks.begin(); it != borrower.borrowedBooks.end(); ++it) {
        if ((*it)->isbn == isbn) {
            (*it)->available = true;
            borrower.borrowedBooks.erase(it);
            cout << "Returned: " << (*it)->title << endl;
            return;
        }
    }
    cout << "Book not found in borrower's records." << endl;
}

// Function to calculate fine for overdue books
int calculateFine(int daysOverdue) {
    return daysOverdue > 0 ? daysOverdue * 0.25 : 0; // Fine rate: $0.25 per day
}

// Function to simulate getting the number of days overdue
int getDaysOverdue(const time_t& dueDate) {
    return static_cast<int>(difftime(time(0), dueDate) / (60 * 60 * 24)); // Convert seconds to days
}

int main() {
    vector<Book> books;
    Borrower borrower = {"Samyak Katariya", {}};

    while (true) {
        cout << "Library Management System" << endl;
        cout << "1. Add Book" << endl;
        cout << "2. Search Books" << endl;
        cout << "3. Check Out Book" << endl;
        cout << "4. Return Book" << endl;
        cout << "5. Exit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Ignore newline character

        switch (choice) {
            case 1:
                addBook(books);
                break;
            case 2:
                {
                    vector<const Book*> searchResults = searchBooks(books);
                    cout << "Search Results:" << endl;
                    for (const auto& book : searchResults) {
                        cout << "Title: " << book->title << ", Author: " << book->author << ", ISBN: " << book->isbn << endl;
                    }
                }
                break;
            case 3:
                checkoutBook(books, borrower);
                break;
            case 4:
                returnBook(borrower);
                break;
            case 5:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }

        cout << endl;
    }
}