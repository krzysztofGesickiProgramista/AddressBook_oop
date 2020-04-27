#include "ContactManager.h"

void ContactManager::addNewContact(int currentUserId) {              // dodaj nowego adresata
    Contact temporaryContact = getNewContact(currentUserId);    // dodaj nowy kontakt do obiektu
    contacts.push_back(temporaryContact);                       // dodaj obiekt do vectora
    addressesFile.saveLastContactToFile(contacts);              // dodaj vector z kontaktami do pliku tekstowego
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

void ContactManager::loadAddressesTextFile(int currentUserId) {      // wczytanie uzytkownikow z pliku do vectora
    contacts = addressesFile.addAddressesFromFile(currentUserId);
}

void ContactManager::searchContactByName() {                         // szukaj adresata po imieniu
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

void ContactManager::searchContactBySurname() {                      // szukaj adresata po nazwisku
    string searchFor;
    cout << "Podaj szukana fraze (nazwisko): ";
    cin.ignore();
    getline(cin, searchFor);
    int range = contacts.size();
    for (int i = 0; i < range; i++) {
        if (searchFor == contacts[i].getSurname()) {
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

void ContactManager::showContacts() {                                // pokaz wszystkie kontakty
    cout << "Lista zapisanych kontaktow: " << endl << endl;
    int range = contacts.size();
    for (int i = 0; i < range; i++) {
        cout << "ID kontaktu: " << contacts[i].getId() << endl;
        cout << "Imie: " << contacts[i].getName() << endl;
        cout << "Nazwisko: " << contacts[i].getSurname() << endl;
        cout << "Numer telefonu: " << contacts[i].getPhoneNumber() << endl;
        cout << "Adres e-mail: " << contacts[i].getEmail() << endl;
        cout << "Adres: " << contacts[i].getAddress() << endl;
        cout << endl;
    }
    cout << endl << "(wcisnij enter aby wrocic do menu glownego)";
    cin.sync();
    cin.get();
}

void ContactManager::deleteContact() {                               // usun adresata
    int id;
    int vectorSize = contacts.size();
    system("cls");
    cout << "Podaj ID kontaktu do usuniecia: ";
    while(!(cin >> id))
    {
        cout << "Podano niepoprawny nr ID!";
        cin.clear();
        cin.sync();
        Sleep(2000);
        return;
    }
    char choice;
    while (true) {
        cout << "Na pewno chcesz usunac kontakt o numerze ID: " << id << "? (t/n) ";
        cin >> choice;
        if (choice == 'n') {
            return;
        }
        else if (choice == 't') {
            int position = -1;
            for (int i = 0; i < vectorSize; i++) {
                if (contacts[i].getId() == id) {
                    position = i;
                    break;
                }
            }
            if (position == -1) {
                cout << "Nie ma takiego kontaktu!";
                Sleep(2000);
                return;
            }
            contacts.erase(contacts.begin()+position);
            addressesFile.saveContactsToFile(contacts);
            return;
        } else {
            cout << "Wybierz poprawna opcje!" << endl;
            continue;
        }
    }
}

void ContactManager::editContact() {                                 // edytuj adresata
    int id;
    system("cls");
    cout << "Podaj ID adresata do edycji: ";
    while(!(cin >> id))
    {
        cout << "Podano niepoprawny nr ID!";
        cin.clear();
        cin.sync();
        Sleep(2000);
        return;
    }
    int vectorSize = contacts.size();
    int position = -1;
    for (int i = 0; i < vectorSize; i++) {
        if (contacts[i].getId() == id) {
            position = i;
            break;
        }
    }
    if (position == -1) {
        cout << "Nie ma takiego kontaktu!";
        Sleep(2000);
        return;
    }
    cout << "Edytujesz ponizszy kontakt:" << endl;
    cout << "ID kontaktu: " << contacts[position].getId() << endl;
    cout << "Imie: " << contacts[position].getName() << endl;
    cout << "Nazwisko: " << contacts[position].getSurname() << endl;
    cout << "Numer telefonu: " << contacts[position].getPhoneNumber() << endl;
    cout << "Adres e-mail: " << contacts[position].getEmail() << endl;
    cout << "Adres: " << contacts[position].getAddress() << endl;
    cout << endl;
    cout << "Co chcesz edytowac?" << endl;

    cout << "1-imie" << endl;
    cout << "2-nazwisko" << endl;
    cout << "3-numer telefonu" << endl;
    cout << "4-email" << endl;
    cout << "5-adres" << endl;
    cout << "6-powrot do menu" << endl;

    int choice;
    cin >> choice;
    string newValue;
    switch (choice) {
    case 1:
        cout << "Nowe imie: ";
        cin.ignore();
        getline(cin,newValue);
        contacts[position].setName(newValue);
        addressesFile.saveContactsToFile(contacts);
        cout << "Zapisano zmiany!";
        Sleep(1500);
        break;
    case 2:
        cout << "Nowe nazwisko: ";
        cin.ignore();
        getline(cin,newValue);
        contacts[position].setSurname(newValue);
        addressesFile.saveContactsToFile(contacts);
        cout << "Zapisano zmiany!";
        Sleep(1500);
        break;
    case 3:
        cout << "Nowy numer telefonu: ";
        cin.ignore();
        getline(cin,newValue);
        contacts[position].setPhoneNumber(newValue);
        addressesFile.saveContactsToFile(contacts);
        cout << "Zapisano zmiany!";
        Sleep(1500);
        break;
    case 4:
        cout << "Nowy email: ";
        cin.ignore();
        getline(cin,newValue);
        contacts[position].setEmail(newValue);
        addressesFile.saveContactsToFile(contacts);
        cout << "Zapisano zmiany!";
        Sleep(1500);
        break;
    case 5:
        cout << "Nowy adres: ";
        cin.ignore();
        getline(cin,newValue);
        contacts[position].setAddress(newValue);
        addressesFile.saveContactsToFile(contacts);
        cout << "Zapisano zmiany!";
        Sleep(1500);
        break;
    case 6:
        return;
    default:
        cout << "Nie ma takiej opcji!";
        Sleep(2000);
        return;
    }
}
