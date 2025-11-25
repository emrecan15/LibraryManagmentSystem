#include "BorrowRecord.h"
#include <iostream>
#include <iomanip>

using namespace std;

BorrowRecord::BorrowRecord(const Student& student, const Book& book, const string& date) :student(student), book(book), borrowDate(date), returnDate("") {

}

void BorrowRecord::displayRecord() const{
	/*
	cout << "Student: " << student.getName() << " " << student.getSurname() << " | Department: " << student.getDepartment()
		<< " | Borrowed Book: \"" << book.getTitle() << "\"" << " | Borrow Date : " << borrowDate <<" | Return Date : "<< returnDate << endl;
		*/

	string rDate = returnDate.empty() ? "Not Returned" : returnDate;

	cout << "------------------------------------------------------" << endl;
	cout << " [STUDENT] : " << student.getName() << " " << student.getSurname()
		<< " (" << student.getDepartment() << ")" << endl;
	cout << " [BOOK]   : " << book.getTitle() << endl;
	cout << " [BORROW-DATE]   : " << borrowDate << endl;
	cout << " [RETURN-DATE]   : "<< rDate << endl;
	cout << "------------------------------------------------------" << endl;
}

void BorrowRecord::setReturnDate(const string& date) {
	returnDate = date;
}

string BorrowRecord::getReturnDate() const{
	return returnDate;
}

const Book& BorrowRecord::getBook() const {
	return book;
}

