#include "Student.h"
#include <iostream>

Student::Student(int id, const string& name, const string& surname, const string& department) :Person(id, name, surname), department(department) {

}


string Student::getDepartment() const {
	return department;
}

void Student::displayStudent() const {
	cout << "[" << getId() << "] " << getName() << " " << getSurname() << " " << department << endl;
}