#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>

#include "User.h"
#include "UsersFile.h"

using namespace std;

class UserManager {
    //string usersFileName = "users.txt";
    //int loggedUserId;
    vector <User> users;

    User getNewUser();                               // pobranie danych nowego uzytkownika
    bool checkExistingNames(string name);            // sprawdzenie czy istnieje juz taka nazwa uzytkownika
    int getNewUserId();                              // pobranie danych nowego uzytkownika
    UsersFile userFile;                              // stworz obiekt klasy UserFile zeby wykonywac na nim operacje

public:
    void signIn();
    void loadUsersTextFile();                        // wczytaj uzytkownikow z pliku do wektora

    //void logIn();
    //void changePassword();

};

#endif // USERMANAGER_H
