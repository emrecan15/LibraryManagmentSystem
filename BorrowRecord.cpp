#include "BorrowRecord.h"
#include <iostream>
#include <iomanip>

using namespace std;


void printStudentBorrowRecords(int studentId, const vector<BorrowRecord>& records) {
	for (const auto& record : records) {
		if (record.student.getId() == studentId) {
			string rDate = record.returnDate.empty() ? "Not Returned" : record.returnDate;

			cout << "------------------------------------------------------" << endl;
			cout << " [STUDENT] : " << record.student.getName() << " " << record.student.getSurname()
				<< " (" << record.student.getDepartment() << ")" << endl;
			cout << " [BOOK]   : " << record.book.getTitle() << endl;
			cout << " [BORROW-DATE]   : " << record.borrowDate << endl;
			cout << " [RETURN-DATE]   : " << rDate << endl;
			cout << "------------------------------------------------------" << endl;
		}
	}
}

BorrowRecord::BorrowRecord(const Student& student, const Book& book, const string& date) :student(student), book(book), borrowDate(date), returnDate("") {

}

void BorrowRecord::displayRecord() const{
	
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

bool BorrowRecord::isActive() const {
	if (returnDate.empty()) {
		return true;
	}
	return false;
}


bool BorrowRecord::isReturned() const {
	if (!returnDate.empty()) {
		return true;
	}
	return false;
}


bool BorrowRecord::matchesStudent(int id) const {
	if (student.getId() == id) {
		return true;
	}
	return false;
}

bool BorrowRecord::matchesBook(int id) const {
	if (book.getId() == id) {
		return true;
	}
	return false;
}
