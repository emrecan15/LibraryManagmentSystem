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


string Student::getDepartmentCode() const {
    string code = "";
    for (int i = 0; i < 4 && i < department.length(); i++) {
        code += toupper(department[i]);
    }
    return code;
}

void Student::printIDCard() const {
    cout << "******************************" << endl;
    cout << "* STUDENT ID CARD       *" << endl;
    cout << "******************************" << endl;
    cout << "* ID:   " << getId() << endl;
    cout << "* Name: " << getFullName() << endl;
    cout << "* Dept: " << getDepartmentCode() << endl;
    cout << "******************************" << endl;
}

string Student::createUsername() const {
    string username = "";
    string name = getName();

    for (char c : name) {
        username += tolower(c);
    }

    username += to_string(getId());
    return username;
}

void Student::printProfileSummary() const {
    cout << getFullName() << " (" << department << ") - #" << getId() << endl;
}