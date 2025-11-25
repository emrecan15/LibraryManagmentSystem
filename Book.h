#pragma once
#include <string>
using namespace std;

class Book {
private:
	int id;
	string title;
	string author;
	bool isBorrowed;

	int shelfRow;
	int shelfCol; 
public:

	Book(int id, const string& title = "Unknown", const string& author = "Unknown");

	int getId() const;
	string getTitle() const;
	string getAuthor() const;
	bool getStatus() const;

	void displayBook() const;
	void borrowBook();
	void returnBook();

	void setLocation(int row, int col) {
		shelfRow = row;
		shelfCol = col;
	}
	int getRow() const;
	int getCol() const;
};