#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

#include "UserManager.h"
#include "ContactManager.h"
#include "AuxiliaryMethods.h"

#include <iostream>

using namespace std;


class AddressBook {
private:
    UserManager userManager;                // obiekt klasy UserManager do wykonywania operacji
    ContactManager contactManager;          // obiekt klasy ContactManager do wykonywania operacji
    bool logged;                            // zmienna do sterowania menu
    int currentUserId;

    enum unLoggedOption{                    // TODO wrzucic to pozniej w oddzielny plik naglowkowy albo klase
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
    AddressBook(string usersFileName, string addressesFileName) : userManager(usersFileName), contactManager(addressesFileName) {     // konstruktor do wczytania uzytkownikow z pliku oraz nadania nazwy pliku
    userManager.loadUsersTextFile();
    //contactManager.loadAddressesTextFile();
    logged = false;
    currentUserId = 0;
    }
    void start();                                                        // wystartowanie programu

    void signIn();                                                       // rejestracja uzytkownika
    int logIn();                                                         // logowanie uzytkownika

    void controlUnLoggedOption(char choice);                             // sterowanie menu niezalogowanego uzytkownika
    void controlLoggedOption(char choice);                               // sterowanie menu zalogowanego uzytkownika

    void addNewContact(int currenUserId);

};

#endif // ADDRESSBOOK_H
