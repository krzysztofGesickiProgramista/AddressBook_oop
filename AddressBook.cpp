#include "AddressBook.h"

void AddressBook::signIn() {             // rejestracja uzytkownika
    userManager.signIn();
}

int AddressBook::logIn() {
    return userManager.logIn();                // logowanie uzytkownika
}

void AddressBook::start() {
    int choice;
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
        //Sleep (5000);
    }
}

void AddressBook::controlUnLoggedOption(int choice) {
    int currentUserId;
    switch (choice) {
        case LOGIN:
            currentUserId = logIn();
            if (currentUserId != 0) {     // jezeli jest rozne od zera to zalogowany
                logged = true;
                // TODO
                // ustawic ID uzytkownika w UserManager
            }
            break;
        case REGISTER:
            cout << "register";
            break;
        case EXIT:
            cout << "Wylaczasz program";
            Sleep(2000);
            exit(0);
            break;
        default:
            cout << "Wybrano niepoprawna opcje! " << endl;
            break;
    }
}

void AddressBook::controlLoggedOption(int choice) {
    switch (choice) {
        case ADD_CONTACT:
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
            break;
    }
}

