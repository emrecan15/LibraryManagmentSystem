#pragma once
#include <string>
#include "Student.h"
#include "Book.h"

using namespace std;

class BorrowRecord {
private:
	Student student;
	Book book;
	string borrowDate;
	string returnDate;
public:

	BorrowRecord(const Student& student,const Book& book,const string& date);

	void setReturnDate(const string& date);
	string getReturnDate() const;

	const Book& getBook() const;


	void displayRecord() const;
};