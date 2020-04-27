#include "AddressBook.h"

void AddressBook::start() {                                  // startowanie programu
    char choice;
    while (true){
        if (logged) {
            AuxiliaryMethods::showMenuLogged();
            cin >> choice;
            controlLoggedOption(choice);
        }
        else {
            AuxiliaryMethods::showMenuUnLogged();
            cin >> choice;
            controlUnLoggedOption(choice);
        }
    }
}

void AddressBook::signIn() {                                 // rejestracja uzytkownika
    userManager.signIn();
}

int AddressBook::logIn() {                                   // logowanie uzytkownika
    return userManager.logIn();
}

void AddressBook::addNewContact(int currenUserId) {          // dodawanie nowego adresata
    contactManager.addNewContact(currenUserId);
}


void AddressBook::controlUnLoggedOption(char choice) {
    switch (choice) {
        case LOGIN:
            currentUserId = logIn();                         // zwraca ID zalogowanego uzytkownika
            if (currentUserId != 0) {                        // jezeli jest rozne od zera to zalogowany
                logged = true;
                // TODO
                // ustawic ID uzytkownika w UserManager
                contactManager.loadAddressesTextFile(currentUserId);    // zaladuj adresatow z pliku
            }
            break;
        case REGISTER:
            signIn();
            break;
        case EXIT:
            cout << "Wylaczasz program";
            Sleep(2000);
            exit(0);
            break;
        default:
            cout << "Wybrano niepoprawna opcje! " << endl;
            Sleep(2000);
            break;
    }
}

void AddressBook::controlLoggedOption(char choice) {
    switch (choice) {
        case ADD_CONTACT:
            addNewContact(currentUserId);
            cout << "ADD_CONTACT";
            break;
        case SEARCH_WITH_NAME:
            cout << "SEARCH_WITH_NAME";
            break;
        case SEARCH_WITH_SURNAME:
            cout << "SEARCH_WITH_SURNAME";
            break;
        case SHOW_ALL:
            cout << "SHOW_ALL";
            break;
        case DELETE_CONTACT:
            cout << "DELETE_CONTACT";
            break;
        case EDIT_CONTACT:
            cout << "EDIT_CONTACT";
            break;
        case CHANGE_PASSWORD:
            cout << "CHANGE_PASSWORD";
            break;
        case SIGN_OUT:
            logged = false;             // wyzerowac id uzytkownika
            cout << "Wylogowales sie";
            Sleep(1000);
            break;
        default:
            cout << "Wybrano niepoprawna opcje! " << endl;
            Sleep(2000);
            break;
    }
}

