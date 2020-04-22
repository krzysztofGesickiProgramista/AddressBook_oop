#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

#include <iostream>

#include "UserManager.h"

using namespace std;

class AddressBook {
    UserManager userManager;         // obiekt klasy UserManager do wykonywania operacji
public:
    void signIn();                   // rejestracja uzytkownika
    AddressBook();                   // konstruktor do wczytania uzytkownikow z pliku

};

#endif // ADDRESSBOOK_H
