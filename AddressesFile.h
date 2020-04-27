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
    void saveLastContactToFile(vector <Contact> contacts);          // zapisanie ostatniego adresata do pliku tekstowego
    vector <Contact> addAddressesFromFile(int currentUserId);       // wczytanie adresatow z pliku tekstowego do vectora
    void saveContactsToFile(vector <Contact> contacts);             // zapisanie wszystkich adresatow do pliku tekstowego
};






#endif // ADDRESSESFILE_H
