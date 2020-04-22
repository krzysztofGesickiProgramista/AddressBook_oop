#include <iostream>

#include "AddressBook.h"

using namespace std;

int main()
{
    AddressBook addressBook("users.txt");    //tworzymy obiekt addressBook z klasy AddressBook
    //addressBook.signIn();                    //dzialania na obiekcie addressBook, czyli rejestracja itd.
    //addressBook.signIn();                    //dzialania na obiekcie addressBook, czyli rejestracja itd.
    //addressBook.signIn();                    //dzialania na obiekcie addressBook, czyli rejestracja itd.
    addressBook.logIn();                     //dzialania na obiekcie addressBook, czyli logowanie itd.

    return 0;
}
