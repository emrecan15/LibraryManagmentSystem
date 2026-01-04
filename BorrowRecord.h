#pragma once
#include <string>
#include <vector>
#include "Student.h"
#include "Book.h"

using namespace std;

class BorrowRecord {
	// friend function
	friend void printStudentBorrowRecords(int studentId, const vector<BorrowRecord>& records);

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

	bool isActive() const;                      
	bool isReturned() const;
	void displayRecord() const;
	bool matchesStudent(int id) const; 
	bool matchesBook(int id) const;

	
};