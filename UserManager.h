#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>

#include "User.h"
#include "UsersFile.h"

using namespace std;

class UserManager {

    vector <User> users;

    User getNewUser();                               // pobranie danych nowego uzytkownika
    bool checkExistingNames(string name);            // sprawdzenie czy istnieje juz taka nazwa uzytkownika
    int getNewUserId();                              // pobranie danych nowego uzytkownika
    UsersFile userFile;                              // stworz obiekt klasy UsersFile zeby wykonywac na nim operacje

public:
    UserManager(string usersFileName) : userFile(usersFileName) {};
    void signIn();
    void loadUsersTextFile();                        // wczytaj uzytkownikow z pliku do wektora

    //void logIn();
    //void changePassword();

};

#endif // USERMANAGER_H
