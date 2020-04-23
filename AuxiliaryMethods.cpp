#include "AuxiliaryMethods.h"

string AuxiliaryMethods::explodeStringLine (int position, string _textLine) {
    string singleObject = "";
    int countPosition = 1;
    int stringSize = _textLine.size();
    for (int i = 0; i < stringSize; i++) {
        if (_textLine[i] == '|') {
            if (countPosition == position) {
                return singleObject;
            } else {
                countPosition++;
                singleObject = "";
            }
        } else
            singleObject += _textLine[i];
    }
    return singleObject;    // to pozniej zmienic
}

void AuxiliaryMethods::showMenuLogged () {
    system("cls");
    cout << "1. Dodaj adresata"  <<  endl;
    cout << "2. Wyszukaj po imieniu"  <<  endl;
    cout << "3. Wyszukaj po nazwisku"  <<  endl;
    cout << "4. Wyswietl wszystkich adresatow"  <<  endl;
    cout << "5. Usun adresata"  <<  endl;
    cout << "6. Edytuj adresata"  <<  endl;
    cout << "7. Zmien haslo"  <<  endl;
    cout << "8. Wyloguj sie"  <<  endl;
    cout << endl;
    cout << "Twoj wybor: ";
}

void AuxiliaryMethods::showMenuUnLogged () {
    system("cls");
    cout << "1. Logowanie"  <<  endl;
    cout << "2. Rejestracja"  <<  endl;
    cout << "9. Zamknij program"  <<  endl;
    cout << endl;
    cout << "Twoj wybor: ";
}

