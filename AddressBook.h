#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

#include <iostream>

#include "UserManager.h"

#include "AuxiliaryMethods.h"

using namespace std;

class AddressBook {
private:
    UserManager userManager;                // obiekt klasy UserManager do wykonywania operacji
    bool logged = false;                    // zmienna do sterowania menu

    enum unLoggedOption{                    // wrzucic to pozniej w oddzielny plik naglowkowy albo klase
    LOGIN = '1',
    REGISTER = '2',
    EXIT = '9'
    };

    enum loggedOption{
    ADD_CONTACT = '1',
    SEARCH_WITH_NAME = '2',
    SEARCH_WITH_SURNAME = '3',
    SHOW_ALL = '4',
    DELETE_CONTACT = '5',
    EDIT_CONTACT = '6',
    CHANGE_PASSWORD = '7',
    SIGN_OUT = '8',
    };

public:
    AddressBook(string usersFileName) : userManager(usersFileName) {     // konstruktor do wczytania uzytkownikow z pliku oraz nadania nazwy pliku
    userManager.loadUsersTextFile();
    }
    void signIn();                                                       // rejestracja uzytkownika
    int logIn();                                                         // logowanie uzytkownika
    void start();                                                        // wystartowanie programu
    void controlUnLoggedOption(char choice);                             // sterowanie menu niezalogowanego uzytkownika
    void controlLoggedOption(char choice);                               // sterowanie menu zalogowanego uzytkownika

};

#endif // ADDRESSBOOK_H
