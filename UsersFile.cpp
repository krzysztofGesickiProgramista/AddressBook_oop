#include "UsersFile.h"

void UsersFile::saveUsersToFile(vector <User> users) {
    fstream textFile;
    int temporaryPosition = users.back().getId() - 1;               // -1 bo odwoluje sie do id a potrzebuje pozycje (id numerowane od 1 a pozycja od 0)
    textFile.open(usersFileName.c_str(), ios::out|ios::app);
    if (textFile.good() == false) {
        cout << "Nie udalo sie otworzyc pliku z Uzytkownikami!";
        Sleep(2000);
        exit(0);
    }
    textFile << users[temporaryPosition].getId() << "|";
    textFile << users[temporaryPosition].getName() << "|";
    textFile << users[temporaryPosition].getPassword() << "|" << endl;
    textFile.close();
    cout << "Uzytkownik dodany! ";
    cout << endl << "(wcisnij enter aby wrocic do menu glownego)" ;
    cin.sync();
    cin.get();
}

vector <User> UsersFile::addUsersFromFile() {
    fstream textFile;
    textFile.open(usersFileName.c_str(), ios::in);
    if (textFile.good() == false) {
        ofstream temp (usersFileName.c_str());
        textFile.open(usersFileName.c_str(), ios::in);
        if (textFile.good() == false) {
            cout << "Nie udalo sie otworzyc pliku z Uzytkownikami!";
            Sleep(2000);
            exit(0);
        }
    }
    vector <User> temporaryUsers;
    User temporaryUser;
    string textLine;
    string idToConvert;
    while (getline(textFile,textLine)) {
        idToConvert = AuxiliaryMethods::explodeStringLine(1, textLine);
        temporaryUser.setId(atoi(idToConvert.c_str()));
        temporaryUser.setName(AuxiliaryMethods::explodeStringLine(2, textLine));
        temporaryUser.setPassword(AuxiliaryMethods::explodeStringLine(3, textLine));
        temporaryUsers.push_back(temporaryUser);
    }
    textFile.close();
    return temporaryUsers;
}

