#ifndef ADDRESSESFILE_H
#define ADDRESSESFILE_H

#include "Contact.h"
#include "AuxiliaryMethods.h"

#include <iostream>
#include <vector>
#include <fstream>
#include <windows.h>

using namespace std;

class AddressesFile {
    const string addressesFileName;
public:
    AddressesFile(string addressesFileName) : addressesFileName(addressesFileName) {};
    void saveContactsToFile(vector <Contact> contacts);             // zapisanie adresatow do pliku tekstowego
    //vector <User> addUsersFromFile();                             // wczytanie adresatow z pliku tekstowego do vectora
};






#endif // ADDRESSESFILE_H
