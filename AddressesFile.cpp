#include "AddressesFile.h"

void AddressesFile::saveContactsToFile(vector <Contact> contacts) {
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
