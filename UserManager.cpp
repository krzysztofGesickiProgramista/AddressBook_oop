#include "UserManager.h"

void UserManager::signIn() {                           // rejestracja uzytkownika
    User temporaryUser = getNewUser();                 // dodaj nowego uzytkownika do obiektu
    users.push_back(temporaryUser);                    // dodaj obiekt do vectora
    userFile.saveLastUserToFile(users);                // dodaj vector z uzytkownikami do pliku tekstowego
}

User UserManager::getNewUser() {                       // pobranie danych nowego uzytkownika
    User givenUser;
    string name, password;
    do {
        cin.ignore();
        cout << "Podaj nazwe nowego uzytkownika: ";
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

int UserManager::logIn() {                             // logowanie uzytkownika
    string name, password;
    int usersNumber = users.size();
    cout << "Podaj nazwe uzytkownika: ";
    cin.ignore();
    getline(cin, name);
    int i = 0;
    while (i < usersNumber) {
        if (users[i].getName() == name) {
            for (int attempt = 0; attempt < 3; attempt++) {
                cout << "Podaj haslo: ";
                getline(cin, password);
                if (users[i].getPassword() == password) {
                    cout << "Zalogowales sie" << endl;
                    Sleep (1000);
                    return users[i].getId();
                }
            }
            cout << "Podales 3 razy bledne haslo. Sprobuj ponownie.";
                 Sleep(3000);
            return 0;
        }
        i++;
    }
    cout << "Nie ma takiego uzytkownika!";
    Sleep(1500);
    return 0;
}

void UserManager::changePassword(int currentUserId) {
    string password;
    cout<<"Podaj nowe haslo: ";
    cin.ignore();
    getline(cin, password);
    int range = users.size();
    for (int i = 0; i < range; i++) {
        if (users[i].getId() == currentUserId) {
            users[i].setPassword(password);
        }
    }
    userFile.saveUsersToFile(users);
}
