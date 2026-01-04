#include <iostream>
#include <vector>
#include <string>
#include "Book.h"
#include "BorrowRecord.h"
#include "Student.h"


#include <cctype> 

#include <queue>    
#include <utility>  
#include <cstdlib>  
#include <ctime>  
#include <format>

using namespace std;


static int bookIdCounter = 1;
static int studentIdCounter = 3;



// Breadth-First Search (BFS) Algorithm
vector<pair<int, int>> validShelves = {
    {0, 2}, {1, 2}, {2, 2}, {2, 3}, {2, 4}, {4, 4}, {6, 6}, {8, 2}
};

void drawPathToShelf(int targetRow, int targetColumn) {
    const int GRID_SIZE = 10;


    int rowDirectionOffsets[] = { -1, 1, 0, 0 };
    int columnDirectionOffsets[] = { 0, 0, -1, 1 };

    int grid[GRID_SIZE][GRID_SIZE] = {
        {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 1, 0, 1, 1, 1, 0, 0},
        {0, 1, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 1, 1, 1, 1, 1, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
        {1, 1, 1, 0, 0, 1, 0, 1, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0, 1, 0, 1, 0, 0},
        {0, 0, 0, 1, 0, 1, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    bool visitedCells[GRID_SIZE][GRID_SIZE] = { false };
    pair<int, int> parentCell[GRID_SIZE][GRID_SIZE];
    queue<pair<int, int>> coordinatesQueue;

    coordinatesQueue.push({ 0, 0 });
    visitedCells[0][0] = true;
    parentCell[0][0] = { -1, -1 };

    bool pathFound = false;

    while (!coordinatesQueue.empty()) {
        pair<int, int> currentPosition = coordinatesQueue.front();
        coordinatesQueue.pop();

        if (currentPosition.first == targetRow && currentPosition.second == targetColumn) {
            pathFound = true;
            break;
        }

        // check neighbors
        for (int i = 0; i < 4; i++) {
            int nextRow = currentPosition.first + rowDirectionOffsets[i];
            int nextColumn = currentPosition.second + columnDirectionOffsets[i];

            if (nextRow >= 0 && nextRow < GRID_SIZE &&
                nextColumn >= 0 && nextColumn < GRID_SIZE &&
                grid[nextRow][nextColumn] == 0 &&
                !visitedCells[nextRow][nextColumn]) {

                coordinatesQueue.push({ nextRow, nextColumn });
                visitedCells[nextRow][nextColumn] = true;
                parentCell[nextRow][nextColumn] = { currentPosition.first, currentPosition.second };
            }
        }
    }

    if (pathFound) {
        int numberOfSteps = 0;
        pair<int, int> pathTracer = { targetRow, targetColumn };

        // check step size
        while (pathTracer.first != -1) {
            numberOfSteps++;
            pathTracer = parentCell[pathTracer.first][pathTracer.second];
        }

        cout << "Optimal route calculated successfully." << endl;
        cout << "Distance to shelf: " << numberOfSteps - 1 << " steps." << endl;
    }
    else {
        cout << "Error: Path to the shelf could not be found!" << endl;
    }
}

string toLowerCase(string str) {
    for (char& c : str) {
        c = tolower(c); 
    }
    return str;
}


// Selection Sort algorithm
void printSortedBooks(vector<Book> books) {
    int n = books.size();

    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {

            string title1 = toLowerCase(books[j].getTitle());
            string title2 = toLowerCase(books[minIndex].getTitle());

            if (title1 < title2) {
                minIndex = j;
            }

        }

        if (minIndex != i) {
            Book temp = books[i];
            books[i] = books[minIndex];
            books[minIndex] = temp;
        }
    }

    cout << endl << "--- Books (Alphabetical Order) ---" << endl;
    for (const auto& b : books) {
        b.displayBook();
    }
}



void addBook(vector<Book>& books, const string& title, const string& author) {
    Book newBook(bookIdCounter,title,author);
    for (const auto& book : books)
    {
        if (book == newBook)
        {
            cout << "This book already exists: "
                << newBook.getTitle() << " - " << newBook.getAuthor() << endl;
            return;
        }
    }
    int randomIndex = rand() % validShelves.size();
    newBook.setLocation(validShelves[randomIndex].first, validShelves[randomIndex].second);
    books.push_back(newBook);
    cout << "Book added successfully. (ID: " << bookIdCounter << ")" << endl;
    bookIdCounter++;
}

void listBooks(const vector<Book>& books) {
    cout << endl << "--- Books ---" << endl;
    for (const auto& b : books) {
        b.displayBook();
    }
}
void showBorrowedBooks(const vector<Book>& books) {
    cout << endl << "--- Borrowed Books ---" << endl;
    for (const auto& b : books) {
        if (b.getStatus()) {
            b.displayBook();
        }
    }
    cout << endl;
}

void showAvailableBooks(const vector<Book>& books) {
    cout << endl << "--- Available Books ---" << endl;
    for (const auto& b : books) {
        if (!b.getStatus()) {
            b.displayBook();
        }
    }
    cout << endl;
}

Book* findBookById(vector<Book>& books, int id) {
    for (auto& book : books) {
        if (book.getId() == id) {
            return &book;
        }
    }
    return nullptr;
}

void addStudent(vector<Student>& students, const Student& student) {
    students.push_back(student);
}

void listStudents(const vector<Student>& students) {
    cout << endl << "--- Students ---" << endl;
    for (const auto& student : students) {
        student.displayStudent();
    }
}

Student* findStudentById(vector<Student>& students, int id) {
    for (auto& student : students) {
        if (student.getId() == id) {
            return &student;
        }
    }
    return nullptr;
}

Book* searchBook(vector<Book>& books, const string& _title) {
    string title = toLowerCase(_title);

    for (auto& book : books) {
        if (toLowerCase(book.getTitle()) == title) {
            return &book;
        }
    }
    return nullptr;
}

void borrowBook(vector<Student>& students, vector<Book>& books, vector<BorrowRecord>& records, int studentId, int bookId, string date) {
    Student* studentPtr = findStudentById(students, studentId);
    Book* bookPtr = findBookById(books, bookId);

    if (!studentPtr) {
        cout << "Student not found!" << endl;
        return;
    }
    if (!bookPtr) {
        cout << "Book not found!" << endl;
        return;
    }
    if (bookPtr->getStatus()) {
        cout << "Book already borrowed!" << endl;
        return;
    }

    bookPtr->borrowBook();
    records.push_back(BorrowRecord(*studentPtr, *bookPtr, date));
    cout << "Book borrowed successfully!" << endl;
}

void returnBook(vector<Book>& books, vector<BorrowRecord>& records, int bookId, string date) {
    Book* bookPtr = findBookById(books, bookId);

    if (bookPtr && bookPtr->getStatus()) {

        cout << "Generating path to shelf..." << endl;
        drawPathToShelf(bookPtr->getRow(), bookPtr->getCol());

        bookPtr->returnBook();
        cout << "Book returned successfully!" << endl;

        for (auto& record : records) {
            if (record.getBook().getId() == bookId && record.getReturnDate().empty()) {
                record.setReturnDate(date);
                break;
            }
        }
    }
    else {
        cout << "Book not found or already available!" << endl;
    }
}

void listBorrowRecords(const vector<BorrowRecord>& records) {
    cout << "--- Borrow Records ---" << endl;
    for (const auto& record : records) {
        record.displayRecord();
    }
}


int main() {
    srand(time(0));

    vector<Book> books;
    vector<Student> students;
    vector<BorrowRecord> borrowedRecords;

    addBook(books, "The Great Gatsby", "F. Scott Fitzgerald");
    addBook(books, "1984", "George Orwell");
    addBook(books, "The Hobbit", "J.R.R.Tolkien");

    addStudent(students, Student(1, "Emre", "Can", "Computer Engineering"));
    addStudent(students, Student(2, "Mahmut", "Karalioglu", "Computer Engineering"));

    

    int choice;
    do {
        cout << "\n===== LIBRARY MANAGMENT SYSTEM =====\n";
        cout << "1. Add Book\n";
        cout << "2. Add Student\n";
        cout << "3. List Books\n";
        cout << "4. List Students\n";
        cout << "5. Borrow a Book\n";
        cout << "6. Return a Book\n";
        cout << "7. Search Book by Title\n";
        cout << "8. Show Borrow Records\n";
        cout << "9. Sort Books By Title\n";
        cout << "10. Show Student Borrow Records (Using friend function)\n";
        cout << "0. Exit\n";
        cout << "Select: ";
        

        if (!(cin >> choice)) {
            cout << "Please enter a number!" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        cin.ignore();

        if (choice == 1) {
            string bookTitle, bookAuthor;

            cout << "Enter Book Title : ";
            getline(cin, bookTitle);
            cout << "Enter Book Author : ";
            getline(cin, bookAuthor);

           
            addBook(books, bookTitle, bookAuthor);
           // cout << "Book added successfully. (ID: " << bookIdCounter - 1 << ")" << endl;
        }
        else if (choice == 2) {
            string name, surname, department;

            cout << "Enter Student Name : ";
            cin >> name;
            cout << "Enter Student Surname : ";
            cin >> surname;

            cin.ignore();

            cout << "Enter Student Department : ";
            getline(cin, department);

            addStudent(students, Student(studentIdCounter++, name, surname, department));
            cout << "Student added successfully. (ID: " << studentIdCounter - 1 << ")" << endl;
        }
        else if (choice == 3) {
            listBooks(books);
        }
        else if (choice == 4) {
            listStudents(students);
        }
        else if (choice == 5) {
            int sid, bid;
            string date;
            showAvailableBooks(books);
            cout << "Enter Student ID: "; cin >> sid;
            cout << "Enter Book ID: "; cin >> bid;
            time_t now = time(0);

            tm localTime;
            localtime_s(&localTime, &now);

            char buffer[20];
            strftime(buffer, sizeof(buffer), "%Y-%m-%d", &localTime);

            date = buffer;

            borrowBook(students, books, borrowedRecords, sid, bid, date);
        }
        else if (choice == 6) {
            int bid;
            string date;
            showBorrowedBooks(books);
            cout << "Enter Book ID to return: "; cin >> bid;
            time_t now = time(0);

            tm localTime;
            localtime_s(&localTime, &now);

            char buffer[20];
            strftime(buffer, sizeof(buffer), "%Y-%m-%d", &localTime);

            date = buffer;

            returnBook(books, borrowedRecords, bid, date);
        }
        else if (choice == 7) {
            string title;
            cout << "Enter the Book Title : ";
            getline(cin,title);
            
            Book* b = searchBook(books, title);
            if (b)
            {
                b->displayBook();
            }
            else {
                cout << "Book not found!" << endl;
            }
        }
        else if (choice == 8) {
            listBorrowRecords(borrowedRecords);
        }
        else if (choice == 9) {
            printSortedBooks(books);
        }
        else if (choice == 10)
        {
            int id;
            cout << "Enter Student Id : ";
            cin >> id;
            printStudentBorrowRecords(id,borrowedRecords);
        }

    } while (choice != 0);

    cout << "Exiting Library System...\n";
    return 0;
}
