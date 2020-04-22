#include "UserManager.h"

void UserManager::signIn() {                           // rejestracja uzytkownika
    User temporaryUser = getNewUser();      // dodaj nowego uzytkownika do obiektu
    users.push_back(temporaryUser);         // dodaj obiekt do vectora
    userFile.saveUsersToFile(users);             // dodaj vector z uzytkownikami do pliku tekstowego
}

User UserManager::getNewUser() {                       // pobranie danych nowego uzytkownika
    User givenUser;
    string name, password;
    do {
        cin.ignore();
        cout << "Podaj nazwe uzytkownika: ";
        getline(cin, name);
    }
    while (checkExistingNames(name) == true);
    givenUser.setName(name);                     // wstawienie nazwy do obiektu
    cout << "Podaj haslo: ";
    getline(cin, password);
    givenUser.setPassword(password);             // wstawienie hasla do obiektu
    givenUser.setId(getNewUserId());             // wstawienie id do obiektu
    return givenUser;
}

int UserManager::getNewUserId() {                      // wyciagniecie ostatniego id z vectora
    if (users.empty() == true)
        return 1;
    else
        return users.back().getId() + 1;
}

bool UserManager::checkExistingNames(string name) {    // sprawdzenie czy istnieje juz taka nazwa uzytkownika
    int vectorSize = users.size();
    if (users.empty() == true) return false;
    for (int i=0; i<vectorSize; i++) {
        if (users[i].getName() == name) {
            cout << "Taki uzytkownik istnieje!!!" << endl;
            return true;
        }
    }
    return false;
}

void UserManager::loadUsersTextFile() {                // wczytanie uzytkownikow z pliku do vectora
    users = userFile.addUsersFromFile();
}

