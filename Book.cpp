#include "Book.h"
#include <string>
#include <iostream>

using namespace std;

Book::Book(int id, const string& title, const string& author) : id(id), title(title), author(author), isBorrowed(false), shelfRow(0), shelfCol(0) {

}

int Book::getId() const {
	return id;
}

string Book::getTitle() const {
	return title;
}

string Book::getAuthor() const {
	return author;
}

bool Book::getStatus() const {
	return isBorrowed;
}

void Book::borrowBook() {
	isBorrowed=true;
}

void Book::returnBook() {
	isBorrowed = false;
}

void Book::displayBook() const {
	/*
	cout << "[" << id << "] " << title << " by " << author;
	if (isBorrowed)
		cout << " [Borrowed]";
	cout << endl;
	*/

	cout << "ID: " << id << " | Title: " << title << " | Author: " << author
		<< " | Shelf: [" << shelfRow << "," << shelfCol << "] | Status: "
		<< (isBorrowed ? "Borrowed" : "Available") << endl;
}
int Book::getRow() const {
	return shelfRow;
}
int Book::getCol() const {
	return shelfCol;
}