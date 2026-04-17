#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;
struct Contact {
 int id;
 string name;
 string phone;
 string country;
 bool isEmergency;
 bool isFavorite;
};
vector<Contact> contacts;
void addContact() {
 Contact c;
 c.id = contacts.size() + 1;
 cin.ignore();
 cout << "\nEnter Name: ";
 getline(cin, c.name);
 cout << "Enter Phone: ";
 getline(cin, c.phone);
 for (auto &con : contacts) {
 if (con.phone == c.phone) {
 cout << "Phone number already exists!\n";
 return;
 }
 }
 cout << "Enter Country: ";
 getline(cin, c.country);
cout << "Favorite (1/0): ";
 cin >> c.isFavorite;
 cout << "Emergency (1/0): ";
 cin >> c.isEmergency;
 contacts.push_back(c);
 cout << "Contact Added Successfully!\n";
}
void viewContacts() {
 if (contacts.empty()) {
 cout << "No contacts stored.\n";
 return;
 }
 cout << setfill('=') << setw(70) << "" << endl;
 cout << setfill(' ') << setw(40) << "CONTACT LIST" << endl;
 cout << setfill('=') << setw(70) << "" << endl;
cout << left << setw(5) << "ID"
 << setw(20) << "Name"
 << setw(15) << "Phone"
 << setw(15) << "Country"
 << setw(10) << "Fav"
 << setw(10) << "Emerg" << endl;
 cout << setfill('-') << setw(70) << "" << endl;
 cout << setfill(' ');
 for (auto &c : contacts) {
 cout << left << setw(5) << c.id
 << setw(20) << c.name
 << setw(15) << c.phone
 << setw(15) << c.country
 << setw(10) << (c.isFavorite ? "Yes" : "No")
 << setw(10) << (c.isEmergency ? "Yes" : "No")
<< endl;
 }
}
void searchContact() {
 string keyword;
 bool found = false;
 cin.ignore();
 cout << "\nEnter Name to search: ";
 getline(cin, keyword);
 for (auto &c : contacts) {
 if (c.name.find(keyword) != string::npos) {
 cout << "\n" << setfill('-') << setw(40) << "" << endl;
 cout << "ID: " << c.id << endl;
 cout << "Name: " << c.name << endl;
 cout << "Phone: " << c.phone << endl;
 cout << "Country: " << c.country << endl;
 cout << "Favorite: " << (c.isFavorite ? "Yes" : "No") << endl;
 cout << "Emergency: " << (c.isEmergency ? "Yes" : "No") << endl;
 cout << setfill('-') << setw(40) << "" << endl;
 found = true;
 }
 }
 if (!found)
 cout << "No matching contacts found.\n";
}
void deleteContact() {
 int id;
 bool found = false;
 cout << "\nEnter ID to delete: ";
 cin >> id;
for (auto it = contacts.begin(); it != contacts.end(); ++it) {
 if (it->id == id) {
 contacts.erase(it);
 found = true;
 break;
 }
 }
 if (found)
 cout << "Contact Deleted!\n";
 else
 cout << "Contact Not Found!\n";
}
void updateContact() {
 int id;
 bool found = false;
 cout << "\nEnter ID to update: ";
 cin >> id;
 cin.ignore();
 for (auto &c : contacts) {
 if (c.id == id) {
 cout << "Enter New Name: ";
 getline(cin, c.name);
 cout << "Enter New Phone: ";
 getline(cin, c.phone);
 cout << "Enter Country: ";
 getline(cin, c.country);
 cout << "Favorite (1/0): ";
 cin >> c.isFavorite;
 cout << "Emergency (1/0): ";
 cin >> c.isEmergency;
found = true;
 break;
 }
 }
 if (found)
 cout << "Contact Updated!\n";
 else
 cout << "Contact Not Found!\n";
}
int main() {
 int choice;
 do {
 cout << "\n";
 cout << setfill('=') << setw(50) << "" << endl;
 cout << setfill(' ') << setw(30) << "DIGITAL PHONEBOOK" << endl;
 cout << setfill('=') << setw(50) << "" << endl;
 cout << "1. Add Contact\n";
 cout << "2. View Contacts\n";
 cout << "3. Search Contact\n";
 cout << "4. Delete Contact\n";
 cout << "5. Update Contact\n";
 cout << "6. Exit\n";
 cout << setfill('-') << setw(50) << "" << endl;
 cout << "Enter Choice: ";
 cin >> choice;
 switch(choice) {
 case 1: addContact(); break;
 case 2: viewContacts(); break;
 case 3: searchContact(); break;
 case 4: deleteContact(); break;
case 5: updateContact(); break;
 case 6: cout << "Exiting...\n"; break;
 default: cout << "Invalid Choice!\n";
 }
 } while(choice != 6);
 return 0;
}
