#ifndef USERMANAGER_H
#define USERMANAGER_H

#include "User.h"
#include "UsersFile.h"

#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

class UserManager {

    vector <User> users;
    int loggedUserId;
    User getNewUser();                               // pobranie danych nowego uzytkownika
    bool checkExistingNames(string name);            // sprawdzenie czy istnieje juz taka nazwa uzytkownika
    int getNewUserId();                              // pobranie danych nowego uzytkownika
    UsersFile userFile;                              // stworz obiekt klasy UsersFile zeby wykonywac na nim operacje
    int currentUserId;

public:
    UserManager(string usersFileName) : userFile(usersFileName) {};
    void signIn();                                   // rejestrowanie uzytkownika
    int logIn();                                     // logowanie uzytkownika
    void loadUsersTextFile();                        // wczytaj uzytkownikow z pliku do wektora
    void changePassword(int currentUserId);          // zmiana hasla uzytkownika

};

#endif // USERMANAGER_H
