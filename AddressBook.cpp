#include "AddressBook.h"

void AddressBook::signIn() {             // rejestracja uzytkownika
    userManager.signIn();
}

AddressBook::AddressBook() {             // konstruktor do wczytania uzytkownikow z pliku
    userManager.loadUsersTextFile();
}

//void AddressBook::logIn()
//{
//    userManager.logIn();
//}
