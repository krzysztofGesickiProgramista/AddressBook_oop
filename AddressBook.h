#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

#include <iostream>

#include "UserManager.h"

using namespace std;

class AddressBook {
    UserManager userManager;                                             // obiekt klasy UserManager do wykonywania operacji
public:
    void signIn();                                                       // rejestracja uzytkownika
    void logIn();                                                        // logowanie uzytkownika
    AddressBook(string usersFileName) : userManager(usersFileName) {     // konstruktor do wczytania uzytkownikow z pliku oraz nadania nazwy pliku
        userManager.loadUsersTextFile();
    }
};

#endif // ADDRESSBOOK_H
