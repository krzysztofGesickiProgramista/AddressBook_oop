#include "Contact.h"

// pozniej dorobic walidacje!!!

void Contact::setId(int newId) {
    id = newId;
}

void Contact::setUserID(int newUserID) {
    userID = newUserID;
}

void Contact::setName(string newName) {
    name = newName;
}

void Contact::setSurname(string newSurname) {
    surname = newSurname;
}

void Contact::setPhoneNumber(string newPhoneNumber) {
    phoneNumber = newPhoneNumber;
}

void Contact::setEmail(string newEmail) {
    email = newEmail;
}

void Contact::setAddress(string newAddress) {
    address = newAddress;
}

int Contact::getId() {
    return id;
}

int Contact::getUserID() {
    return userID;
}

string Contact::getName() {
    return name;
}

string Contact::getSurname() {
    return surname;
}

string Contact::getPhoneNumber() {
    return phoneNumber;
}

string Contact::getEmail() {
    return email;
}

string Contact::getAddress() {
    return address;
}
