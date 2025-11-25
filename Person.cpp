#include "Person.h"

Person::Person(int id, const string& name, const string& surname): id(id),name(name),surname(surname) {

}

int Person::getId() const {
	return id;
}

string Person::getName() const {
	return name;
}

string Person::getSurname() const {
	return surname;
}