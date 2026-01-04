#pragma once
#include <string>
#include <iostream>

using namespace std;

class Person {
private:
	int id;
	string name;
	string surname;
public:
	Person(int id,const string& name,const string& surname);
	int getId() const;
	string getName() const;
	string getSurname() const;

	string getFullName() const;         
	string getInitials() const;         
	bool matchesSearch(string key) const; 
	void printBaseInfo() const;
	bool isValid() const;
};
