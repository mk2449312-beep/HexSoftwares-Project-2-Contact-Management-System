#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Contact {
    string name;
    string phone;
    string email;
};

// Add a new contact
void addContact() {
    Contact c;

    cout << "\nEnter Name: ";
    cin.ignore();
    getline(cin, c.name);

    cout << "Enter Phone Number: ";
    getline(cin, c.phone);

    cout << "Enter Email: ";
    getline(cin, c.email);

    ofstream file("contacts.txt", ios::app);

    file << c.name << "|" << c.phone << "|" << c.email << endl;
    file.close();

    cout << "\nContact added successfully!\n";
}

// View all contacts
void viewContacts() {
    Contact c;
    ifstream file("contacts.txt");

    cout << "\n******** CONTACT LIST ********\n";

    bool found = false;

    while (getline(file, c.name, '|') &&
           getline(file, c.phone, '|') &&
           getline(file, c.email)) {

        found = true;

        cout << "\nName  : " << c.name;
        cout << "\nPhone : " << c.phone;
        cout << "\nEmail : " << c.email << endl;
    }

    file.close();

    if (!found) {
        cout << "\nNo contacts found.\n";
    }
}

// Search for a contact
void searchContact() {
    string searchName;
    Contact c;
    bool found = false;

    cout << "\nEnter name to search: ";
    cin.ignore();
    getline(cin, searchName);

    ifstream file("contacts.txt");

    while (getline(file, c.name, '|') &&
           getline(file, c.phone, '|') &&
           getline(file, c.email)) {

        if (c.name == searchName) {
            cout << "\nContact Found!";
            cout << "\nName  : " << c.name;
            cout << "\nPhone : " << c.phone;
            cout << "\nEmail : " << c.email << endl;

            found = true;
            break;
        }
    }

    file.close();

    if (!found) {
        cout << "\nContact not found.\n";
    }
}

// Update a contact
void updateContact() {
    string searchName;
    Contact c;
    bool found = false;

    cout << "\nEnter name of contact to update: ";
    cin.ignore();
    getline(cin, searchName);

    ifstream file("contacts.txt");
    ofstream temp("temp.txt");

    while (getline(file, c.name, '|') &&
           getline(file, c.phone, '|') &&
           getline(file, c.email)) {

        if (c.name == searchName) {
            found = true;

            cout << "\nEnter new phone number: ";
            getline(cin, c.phone);

            cout << "Enter new email: ";
            getline(cin, c.email);
        }

        temp << c.name << "|" << c.phone << "|" << c.email << endl;
    }

    file.close();
    temp.close();

    remove("contacts.txt");
    rename("temp.txt", "contacts.txt");

    if (found)
        cout << "\nContact updated successfully!\n";
    else
        cout << "\nContact not found.\n";
}

// Delete a contact
void deleteContact() {
    string searchName;
    Contact c;
    bool found = false;

    cout << "\nEnter name of contact to delete: ";
    cin.ignore();
    getline(cin, searchName);

    ifstream file("contacts.txt");
    ofstream temp("temp.txt");

    while (getline(file, c.name, '|') &&
           getline(file, c.phone, '|') &&
           getline(file, c.email)) {

        if (c.name == searchName) {
            found = true;
            continue;
        }

        temp << c.name << "|" << c.phone << "|" << c.email << endl;
    }

    file.close();
    temp.close();

    remove("contacts.txt");
    rename("temp.txt", "contacts.txt");

    if (found)
        cout << "\nContact deleted successfully!\n";
    else
        cout << "\nContact not found.\n";
}

// Main function
int main() {
    int choice;

    do {
        cout << "\n\n************************************";
        cout << "\n   CONTACT MANAGEMENT SYSTEM";
        cout << "\n************************************";
        cout << "\n1. Add Contact";
        cout << "\n2. View Contacts";
        cout << "\n3. Search Contact";
        cout << "\n4. Update Contact";
        cout << "\n5. Delete Contact";
        cout << "\n6. Exit";
        cout << "\n*************************************";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addContact();
                break;

            case 2:
                viewContacts();
                break;

            case 3:
                searchContact();
                break;

            case 4:
                updateContact();
                break;

            case 5:
                deleteContact();
                break;

            case 6:
                cout << "\nThank you for using Contact Management System!\n";
                break;

            default:
                cout << "\nInvalid choice! Please try again.\n";
        }

    } while (choice != 6);

    return 0;
}
