#pragma once
#include <string>
#include "Person.h"

using namespace std;

class Student : public Person {
private:
	string department;
public:

	Student(int id, const string& name, const string& surname,const string& department);

	
	string getDepartment() const;

	void displayStudent() const;
	string getDepartmentCode() const;      
	void printIDCard() const;              
	string createUsername() const;         
	void printProfileSummary() const;
	
};