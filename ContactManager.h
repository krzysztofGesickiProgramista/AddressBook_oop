#ifndef CONTACTMANAGER_H
#define CONTACTMANAGER_H

#include <iostream>

#include "Contact.h"
#include "AddressesFile.h"

using namespace std;


class ContactManager {
    vector <Contact> contacts;
    AddressesFile addressesFile;

public:
    void addNewContact(int currentUserId);                // dodaj nowego adresata
    Contact getNewContact(int currentUserId);             // pobierz dane nowego adresata
    int getNewContactId();                                // pobierz id ostatniego adresata
    //void loadAddressesTextFile();                       // wczytaj adresatow z pliku do wektora
};

#endif // CONTACTMANAGER_H
