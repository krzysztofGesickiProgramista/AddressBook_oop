#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>

using namespace std;

class Contact {
    int id, userID;
    string name, surname, phoneNumber, email, address;

    public:
        void setId(int newId);
        void setUserID(int newUserID);
        void setName(string newName);
        void setSurname(string newSurname);
        void setPhoneNumber(string newPhoneNumber);
        void setEmail(string newEmail);
        void setAddress(string newAddress);

        int getId();
        int getUserID();
        string getName();
        string getSurname();
        string getPhoneNumber();
        string getEmail();
        string getAddress();
};

#endif // CONTACT_H
