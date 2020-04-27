#include "ContactManager.h"

void ContactManager::addNewContact(int currentUserId) {              // dodaj nowego adresata
    Contact temporaryContact = getNewContact(currentUserId);    // dodaj nowy kontakt do obiektu
    contacts.push_back(temporaryContact);                       // dodaj obiekt do vectora
    addressesFile.saveContactsToFile(contacts);                 // dodaj vector z kontaktami do pliku tekstowego
}

int ContactManager::getNewContactId() {                              // wyciagniecie ostatniego id z vectora
    if (contacts.empty() == true)
        return 1;
    else
        return contacts.back().getId() + 1;
}

Contact ContactManager::getNewContact(int currentUserId) {           // pobranie danych nowego adresata
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

void ContactManager::loadAddressesTextFile(int currentUserId) {       // wczytanie uzytkownikow z pliku do vectora
    contacts = addressesFile.addAddressesFromFile(currentUserId);
}

void ContactManager::searchContactByName() {
    string searchFor;
    cout << "Podaj szukana fraze (imie): ";
    cin.ignore();
    getline(cin, searchFor);
    int range = contacts.size();
    for (int i = 0; i < range; i++) {
        if (searchFor == contacts[i].getName()) {
            cout << "ID kontaktu: " << contacts[i].getId() << endl;
            cout << "Imie: " << contacts[i].getName() << endl;
            cout << "Nazwisko: " << contacts[i].getSurname() << endl;
            cout << "Numer telefonu: " << contacts[i].getPhoneNumber() << endl;
            cout << "Adres e-mail: " << contacts[i].getEmail() << endl;
            cout << "Adres: " << contacts[i].getAddress() << endl;
            cout << endl;
        }
    }
    cout << endl << "(wcisnij enter aby wrocic do menu glownego)";
    cin.sync();
    cin.get();
}
