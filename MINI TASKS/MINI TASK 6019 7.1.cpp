#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
class Product {
public:
    int id;
    string name;
    int quantity;
    double price;
    void input() {
        cout << "Enter Product ID: ";
        cin >> id;
        cout << "Enter Product Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Quantity: ";
        cin >> quantity;
        cout << "Enter Price: ";
        cin >> price;
    }
    void display() {
        cout << left << setw(8) << id
             << setw(20) << name
             << setw(10) << quantity
             << setw(10) << price << "\n";
    }
};
void addProduct() {
    ofstream file("inventory.txt", ios::app);
    if(!file.is_open()) {
        cout << "Unable to open file!\n";
        return;
    }
    Product p;
    p.input();
    file << p.id << " " << p.name << " " << p.quantity << " " << p.price << "\n";
    file.close();
    cout << "Product added successfully\n";
}
void displayProducts() {
    ifstream file("inventory.txt");
    if(!file.is_open()) {
        cout << "No records found\n";
        return;
    }
    Product p;
    cout << "\nID      Name                Qty       Price\n";
    cout << "------------------------------------------------\n";
    while(file >> p.id >> p.name >> p.quantity >> p.price) {
        p.display();
    }
    file.close();
}

void searchProduct() {
    ifstream file("inventory.txt");
    if(!file.is_open()) {
        cout << "File not found\n";
        return;
    }
    int key;
    cout << "Enter Product ID: ";
    cin >> key;
    Product p;
    bool found = false;
    while(file >> p.id >> p.name >> p.quantity >> p.price) {
        if(p.id == key) {
            cout << "\nProduct Found:\n";
            p.display();
            found = true;
        }
    }
    if(!found) cout << "Product not found\n";
    file.close();
}
void updateProduct() {
    ifstream file("inventory.txt");
    ofstream temp("temp.txt");
    if(!file.is_open() || !temp.is_open()) {
        cout << "File error\n";
        return;
    }

    int key;
    cout << "Enter ID to update: ";
    cin >> key;
    Product p;
    bool found = false;
    while(file >> p.id >> p.name >> p.quantity >> p.price) {
        if(p.id == key) {
            cout << "Enter new details:\n";
            p.input();
            found = true;
        }
        temp << p.id << " " << p.name << " " << p.quantity << " " << p.price << "\n";
    }
    file.close();
    temp.close();
    remove("inventory.txt");
    rename("temp.txt","inventory.txt");
    if(found) cout << "Updated successfully\n";
    else cout << "Product not found\n";
}
void deleteProduct() {
    ifstream file("inventory.txt");
    ofstream temp("temp.txt");
    if(!file.is_open() || !temp.is_open()) {
        cout << "File error\n";
        return;
    }

    int key;
    cout << "Enter ID to delete: ";
    cin >> key;
    Product p;
    bool found = false;
    while(file >> p.id >> p.name >> p.quantity >> p.price) {
        if(p.id != key) {
            temp << p.id << " " << p.name << " " << p.quantity << " " << p.price << "\n";
        } else {
            found = true;
        }
    }
    file.close();
    temp.close();
    remove("inventory.txt");
    rename("temp.txt","inventory.txt");
    if(found) cout << "Deleted successfully\n";
    else cout << "Product not found\n";
}
int main() {
    int choice;
    cout << "\n========== INVENTORY SYSTEM ==========\n";
    while(true) {
        cout << "\n1. Add Product\n";
        cout << "2. Display Products\n";
        cout << "3. Search Product\n";
        cout << "4. Update Product\n";
        cout << "5. Delete Product\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1: addProduct(); break;
            case 2: displayProducts(); break;
            case 3: searchProduct(); break;
            case 4: updateProduct(); break;
            case 5: deleteProduct(); break;
            case 6: return 0;
            default: cout << "Invalid choice\n";
        }
    }
}
