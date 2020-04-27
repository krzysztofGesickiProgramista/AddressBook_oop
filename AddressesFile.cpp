#include "AddressesFile.h"

void AddressesFile::saveLastContactToFile(vector <Contact> contacts) {
    int temporaryPosition = contacts.back().getId() - 1;
    fstream textFile;
    textFile.open(addressesFileName.c_str(), ios::out|ios::app);
    if (textFile.good() == false) {
        cout << "Nie udalo sie otworzyc pliku z Kontaktami!";
        Sleep(2000);
        exit(0);
    }
    textFile << contacts[temporaryPosition].getId() << "|";
    textFile << contacts[temporaryPosition].getUserID() << "|";
    textFile << contacts[temporaryPosition].getName() << "|";
    textFile << contacts[temporaryPosition].getSurname() << "|";
    textFile << contacts[temporaryPosition].getPhoneNumber() << "|";
    textFile << contacts[temporaryPosition].getEmail() << "|";
    textFile << contacts[temporaryPosition].getAddress() << "|" << endl;
    textFile.close();

    cout << "Kontakt dodany! ";
    cout << endl << "(wcisnij enter aby wrocic do menu glownego)";
    cin.sync();
    cin.get();
}

vector <Contact> AddressesFile::addAddressesFromFile(int currentUserId) {
    fstream textFile;
    textFile.open(addressesFileName.c_str(), ios::in);
    if (textFile.good() == false) {
        ofstream temp (addressesFileName.c_str());
        textFile.open(addressesFileName.c_str(), ios::in);
        if (textFile.good() == false) {
            cout << "Nie udalo sie otworzyc pliku z Kontaktami!";
            Sleep(2000);
            exit(0);
        }
    }
    string textLine;
    string idToConvert;
    vector <Contact> temporaryContacts;
    Contact temporaryContact;
    while (getline(textFile,textLine)) {
        idToConvert = AuxiliaryMethods::explodeStringLine(1, textLine);
        temporaryContact.setId(atoi(idToConvert.c_str()));
        idToConvert = AuxiliaryMethods::explodeStringLine(2, textLine);
        temporaryContact.setUserID(atoi(idToConvert.c_str()));
        if (temporaryContact.getUserID() == currentUserId)
        {
            temporaryContact.setName(AuxiliaryMethods::explodeStringLine(3, textLine));
            temporaryContact.setSurname(AuxiliaryMethods::explodeStringLine(4, textLine));
            temporaryContact.setPhoneNumber(AuxiliaryMethods::explodeStringLine(5, textLine));
            temporaryContact.setEmail(AuxiliaryMethods::explodeStringLine(6, textLine));
            temporaryContact.setAddress(AuxiliaryMethods::explodeStringLine(7, textLine));
            temporaryContacts.push_back(temporaryContact);
        }
    }
    textFile.close();
    return temporaryContacts;
}

void AddressesFile::saveContactsToFile(vector <Contact> contacts) {
    fstream textFile;
    textFile.open(addressesFileName.c_str(), ios::out);
    if (textFile.good() == false) {
        cout << "Nie udalo sie otworzyc pliku z Kontaktami!";
        Sleep(2000);
        exit(0);
    }
    int range = contacts.size();
    for (int i = 0; i < range; i++) {
        textFile << contacts[i].getId() << "|";
        textFile << contacts[i].getUserID() << "|";
        textFile << contacts[i].getName() << "|";
        textFile << contacts[i].getSurname() << "|";
        textFile << contacts[i].getPhoneNumber() << "|";
        textFile << contacts[i].getEmail() << "|";
        textFile << contacts[i].getAddress() << "|" << endl;
    }
    textFile.close();
}


