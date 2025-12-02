#pragma once
#include <string>
#include <vector>
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

	void setLocation(int row, int col);
	void setLocation(int index);


	int getRow() const;
	int getCol() const;

	bool operator==(const Book& other) const; 
};