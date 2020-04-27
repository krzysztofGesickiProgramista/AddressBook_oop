#include <iostream>

#include "AddressBook.h"

using namespace std;

int main()
{
    AddressBook addressBook("users.txt", "addresses.txt");       //tworzymy obiekt addressBook z klasy AddressBook
    addressBook.start();

    return 0;
}
