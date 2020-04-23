#ifndef ADDRESSESFILE_H
#define ADDRESSESFILE_H

#include <iostream>
#include <vector>
#include <fstream>
#include <windows.h>

#include "Contact.h"
#include "AuxiliaryMethods.h"

using namespace std;

class AddressesFile {
    string addressesFileName = "addresses.txt";
public:
    void saveContactsToFile(vector <Contact> contacts);             // zapisanie adresatow do pliku tekstowego
    //vector <User> addUsersFromFile();                             // wczytanie adresatow z pliku tekstowego do vectora
};






#endif // ADDRESSESFILE_H
