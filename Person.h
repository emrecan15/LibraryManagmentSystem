#pragma once
#include <string>

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
};
