#ifndef USERSFILE_H
#define USERSFILE_H

#include <iostream>
#include <vector>
#include <fstream>
#include <windows.h>

#include "User.h"
#include "AuxiliaryMethods.h"

using namespace std;

class UsersFile {
    const string usersFileName;
public:
    UsersFile(string USERSFILENAME) : usersFileName(USERSFILENAME) {};   // konstruktor nadaje nazwe pliku z uzytkownikami
    void saveUsersToFile(vector <User> users);                           // zapisanie uzytkownikow do pliku tekstowego
    vector <User> addUsersFromFile();                                    // wczytanie uzytkownikow z pliku tekstowego do vectora
};

#endif // USERSFILE_H
