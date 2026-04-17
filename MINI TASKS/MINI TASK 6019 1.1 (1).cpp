##include <iostream>
#include <iomanip>
#include <string>
using namespace std;
int main() {
 string customer, membership;
 string billDate, billTime;
 int n;
 cout << uppercase;
 cout << "============ SMART BILLING SYSTEM ============\n";
cout << "\nEnter Customer Name: ";
 getline(cin, customer);
cout << "Enter Membership (GOLD/SILVER/NONE): ";
 getline(cin, membership);
 cout << "Enter Bill Date (DD/MM/YYYY): ";
 getline(cin, billDate);
cout << "Enter Bill Time (HH:MM:SS): ";
 getline(cin, billTime);
 cout << "Enter number of items: ";
 cin >> n;
 cin.ignore(); 
 string item[20];
int qty[20];
 double price[20];
 double total[20];
 double subtotal = 0;
 for(int i = 0; i < n; i++) {
 cout << "\nItem " << i+1 << " Name: ";
 getline(cin, item[i])
 cout << "Quantity: ";
 cin >> qty[i];
 cout << "Price: ";
 cin >> price[i];
 cin.ignore(); 
 total[i] = qty[i] * price[i];
 subtotal += total[i];
 }
 double discount = 0;
 if(subtotal > 1000) {
 discount = subtotal * 0.10;
 }
 double membershipDiscount = 0;
 if(membership == "GOLD") {
 membershipDiscount = subtotal * 0.15;
 }
 else if(membership == "SILVER") {
 membershipDiscount = subtotal * 0.08;
}
double totalDiscount = discount + membershipDiscount;
double gst = (subtotal - totalDiscount) * 0.05;
 double grandTotal = subtotal - totalDiscount + gst;
 cout << fixed << setprecision(2);
 cout << "\n";
 cout << setfill('=') << setw(70) << "=" << endl;
 cout << setfill(' ');
cout << "DATE : " << billDate << endl;
 cout << "TIME : " << billTime << endl;
 cout << "CUSTOMER : " << customer << endl;
 cout << "MEMBERSHIP : " << membership << endl;
 cout << setfill('=') << setw(70) << "=" << endl;
 cout << setfill(' ');
cout << left << setw(20) << "Item"
 << setw(10) << "Qty"
 << setw(12) << "Price"
 << setw(12) << "Total" << endl;
 cout << setfill('-') << setw(70) << "-" << endl;
 cout << setfill(' ');
 for(int i = 0; i < n; i++) {
 cout << left << setw(20) << item[i]
<< setw(10) << qty[i]
 << setw(12) << price[i]
 << setw(12) << total[i] << endl;
 }
 cout << setfill('-') << setw(70) << "-" << endl;
 cout << setfill(' ');
 cout << right << setw(50) << "Subtotal: << setw(10) << subtotal << endl;
 cout << right << setw(50) << "Regular Discount: " << setw(10) << discount << endl;
 cout << right << setw(50) << "Membership Discount: << setw(10) << membershipDiscount << endl;
cout << right << setw(50) << "Total Discount: " << setw(10) << totalDiscount << endl;
 cout << right << setw(50) << "GST (5%): " << setw(10) << gst << endl;
cout << right << setw(50) << "Grand Total: "<< setw(10) << grandTotal << endl;
cout << setfill('=') << setw(70) << "=" << endl;
 cout << "\nTHANK YOU, " << customer << "! VISIT AGAIN.\n";
return 0;
}
