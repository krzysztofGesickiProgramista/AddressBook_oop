#include "User.h"

// pozniej dorobic walidacje!!!

void User::setId(int newId) {
    id = newId;
}

void User::setName(string newName) {
    name = newName;
}

void User::setPassword(string newPassword) {
    password = newPassword;
}

int User::getId() {
    return id;
}

string User::getName() {
    return name;
}

string User::getPassword() {
    return password;
}
