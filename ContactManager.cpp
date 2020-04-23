#include "ContactManager.h"

void ContactManager::addNewContact(int currentUserId) {         // dodaj nowego adresata
    Contact temporaryContact = getNewContact(currentUserId);    // dodaj nowy kontakt do obiektu
    contacts.push_back(temporaryContact);                       // dodaj obiekt do vectora
    addressesFile.saveContactsToFile(contacts);                 // dodaj vector z kontaktami do pliku tekstowego
}

int ContactManager::getNewContactId() {                    // wyciagniecie ostatniego id z vectora
    if (contacts.empty() == true)
        return 1;
    else
        return contacts.back().getId() + 1;
}

Contact ContactManager::getNewContact(int currentUserId) {
    Contact givenContact;
    int id = getNewContactId();
    string name, surname, phoneNumber, email, address;

    cin.ignore();
    cout << "Podaj imie: ";
    getline(cin, name);
    cout << endl << "Podaj nazwisko: ";
    getline(cin, surname);
    cout << endl << "Podaj numer telefonu: ";
    getline(cin, phoneNumber);
    cout << endl << "Podaj adres e-mail: ";
    getline(cin, email);
    cout << endl << "Podaj adres: ";
    getline(cin, address);

    givenContact.setId(id);
    givenContact.setUserID(currentUserId);
    givenContact.setName(name);
    givenContact.setSurname(surname);
    givenContact.setPhoneNumber(phoneNumber);
    givenContact.setEmail(email);
    givenContact.setAddress(address);

    return givenContact;
}



//void ContactManager::loadAddressesTextFile() {             // wczytanie uzytkownikow z pliku do vectora
//    contacts = addressesFile.addUsersFromFile();
//}
