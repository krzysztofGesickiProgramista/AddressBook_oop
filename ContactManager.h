#ifndef CONTACTMANAGER_H
#define CONTACTMANAGER_H

#include "Contact.h"
#include "AddressesFile.h"

#include <iostream>

using namespace std;

class ContactManager {
    vector <Contact> contacts;
    AddressesFile addressesFile;

public:
    ContactManager(string addressesFileName) : addressesFile(addressesFileName) {}  // konstruktor
    void addNewContact(int currentUserId);                // dodaj nowego adresata
    Contact getNewContact(int currentUserId);             // pobierz dane nowego adresata
    int getNewContactId();                                // pobierz id ostatniego adresata
    void loadAddressesTextFile(int currentUserId);        // wczytaj adresatow z pliku do wektora
    void searchContactByName();                           // szukaj adresata po imieniu
    void searchContactBySurname();                        // szukaj adresata po nazwisku
    void showContacts();                                  // pokaz wszystkie kontakty
    void deleteContact();                                 // usuwanie adresata
    void editContact();                                   // edycja adresata
};

#endif // CONTACTMANAGER_H
