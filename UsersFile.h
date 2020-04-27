#ifndef USERSFILE_H
#define USERSFILE_H

#include "User.h"
#include "AuxiliaryMethods.h"

#include <iostream>
#include <vector>
#include <fstream>
#include <windows.h>

using namespace std;

class UsersFile {
    const string usersFileName;
public:
    UsersFile(string usersFileName) : usersFileName(usersFileName) {};   // konstruktor nadaje nazwe pliku z uzytkownikami
    void saveLastUserToFile(vector <User> users);                        // zapisanie ostatniego uzytkownika do pliku tekstowego
    vector <User> addUsersFromFile();                                    // wczytanie uzytkownikow z pliku tekstowego do vectora
    void saveUsersToFile(vector <User> users);                           // zapisanie wszystkich uzytkownikow do pliku tekstowego
};

#endif // USERSFILE_H
