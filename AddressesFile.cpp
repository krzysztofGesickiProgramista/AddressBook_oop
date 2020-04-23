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





//int loadAddressesTextFile(vector <Contact> & _contacts, int _loggedUserID) {
//    fstream textFile;
//    string textLine;
//    string idToConvert;
//    textFile.open(addressesFileName.c_str(), ios::in);
//    if (textFile.good() == false) {
//        ofstream temp (addressesFileName.c_str());
//        textFile.open(addressesFileName.c_str(), ios::in);
//        if (textFile.good() == false) {
//            cout << "Nie udalo sie otworzyc pliku z Kontaktami!";
//            Sleep(2000);
//            exit(0);
//        }
//    }
//    _contacts = vector <Contact> ();
//    Contact temporaryContact;
//    int contactsNumber = 0;
//    while (getline(textFile,textLine)) {
//        idToConvert = explodeStringLine(1, textLine);
//        temporaryContact.id = atoi(idToConvert.c_str());
//        idToConvert = explodeStringLine(2, textLine);
//        temporaryContact.userID = atoi(idToConvert.c_str());
//        if (temporaryContact.userID == _loggedUserID)
//        {
//            temporaryContact.name = explodeStringLine(3, textLine);
//            temporaryContact.surname = explodeStringLine(4, textLine);
//            temporaryContact.phoneNumber = explodeStringLine(5, textLine);
//            temporaryContact.email = explodeStringLine(6, textLine);
//            temporaryContact.address = explodeStringLine(7, textLine);
//            contactsNumber++;
//            _contacts.push_back(temporaryContact);
//        }
//    }
//    textFile.close();
//    return contactsNumber;
//}
