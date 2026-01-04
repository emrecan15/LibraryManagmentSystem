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



string Person::getFullName() const {
    return name + " " + surname;
}


string Person::getInitials() const {
    string initials = "";
    if (!name.empty()) initials += name[0];
    initials += ".";
    if (!surname.empty()) initials += surname[0];
    initials += ".";
    return initials;
}


bool Person::matchesSearch(string key) const {
    if (name == key || surname == key) {
        return true;
    }
    return false;
}


void Person::printBaseInfo() const {
    cout << "ID: " << id << " | Name: " << getFullName() << endl;
}

bool Person::isValid() const {
    if (id > 0 && !name.empty() && !surname.empty()) {
        return true;
    }
    return false;
}