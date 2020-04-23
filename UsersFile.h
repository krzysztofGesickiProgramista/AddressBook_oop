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
    void saveUsersToFile(vector <User> users);                           // zapisanie uzytkownikow do pliku tekstowego
    vector <User> addUsersFromFile();                                    // wczytanie uzytkownikow z pliku tekstowego do vectora
};

#endif // USERSFILE_H
