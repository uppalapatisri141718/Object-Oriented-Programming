#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>
#include <algorithm>
using namespace std;

const float GST = 0.05;
const float CREDIT_SURCHARGE = 0.02;

// ---------------- UTIL ----------------
void line() {
    cout << "==================================================\n";
}
void subline() {
    cout << "--------------------------------------------------\n";
}
void showHeader() {
    line();
    cout << setw(30) << right << "TABLE MANAGEMENT SYSTEM" << endl;
    line();
}

// ---------------- ENUMS ----------------
enum Status { PENDING, PREPARING, READY, SERVED };
enum Payment { CASH = 1, DEBIT, CREDIT, UPI };
enum Membership { REGULAR, SILVER, GOLD };

// ---------------- MENU ITEM ----------------
class MenuItem {
public:
    int id;
    string name;
    float price;
    MenuItem(int i, string n, float p) : id(i), name(n), price(p) {}
};

// ---------------- ORDER ----------------
class Order {
public:
    vector<MenuItem> items;
    Status status;

    Order() { status = PENDING; }

    void add(MenuItem m, int qty) {
        for (int i = 0; i < qty; i++)
            items.push_back(m);
    }

    float total() {
        float t = 0;
        for (auto &i : items) t += i.price;
        return t;
    }

    void showStatus() {
        string s[] = {"Pending", "Preparing", "Ready", "Served"};
        cout << s[status] << endl;
    }

    void updateStatus() {
        if (status < SERVED)
            status = (Status)(status + 1);
    }

    void clear() {
        items.clear();
        status = PENDING;
    }
};

// ---------------- TABLE ----------------
class Table {
public:
    int no, cap;
    bool occupied, cleaning, isPrivate;
    string customerName;
    string phone;
    Membership membership;
    Order order;

    Table(int n, int c, bool p=false) {
        no = n; cap = c; isPrivate = p;
        occupied = cleaning = false;
        membership = REGULAR;
    }
};

// ---------------- RESTAURANT ----------------
class Restaurant {
    vector<MenuItem> menu;
    vector<Table> tables;
    queue<int> waitQ;

public:
    Restaurant() {
        tables = {
            Table(1,4), Table(2,4),
            Table(3,6), Table(4,6),
            Table(5,8), Table(6,8),
            Table(7,15,true), Table(8,15,true),
            Table(9,2,true), Table(10,2,true)
        };

        menu = {
            MenuItem(1,"Burger",120),
            MenuItem(2,"Pizza",250),
            MenuItem(3,"Pasta",180),
            MenuItem(4,"French Fries",100),
            MenuItem(5,"Sandwich",90),
            MenuItem(6,"Paneer Butter Masala",220),
            MenuItem(7,"Dal Tadka",150),
            MenuItem(8,"Veg Biryani",200),
            MenuItem(9,"Butter Naan",40),
            MenuItem(10,"Jeera Rice",130),
            MenuItem(11,"Coke",50),
            MenuItem(12,"Cold Coffee",120),
            MenuItem(13,"Lassi",80),
            MenuItem(14,"Mineral Water",30),
            MenuItem(15,"Ice Cream",90),
            MenuItem(16,"Gulab Jamun",70),
            MenuItem(17,"Brownie",110)
        };
    }

    void showMenu() {
        line();
        cout << setw(5) << left << "ID"
             << setw(25) << left << "Item"
             << setw(10) << right << "Price" << endl;
        subline();
        for (auto &m : menu)
            cout << setw(5) << left << m.id
                 << setw(25) << left << m.name
                 << setw(10) << right << m.price << endl;
    }

    vector<int> findTablesForGroup(int p) {
        int bestTable = -1;
        int minExtra = 1e9;

        for (auto &t : tables) {
            if (!t.occupied && !t.cleaning && t.cap >= p) {
                int extra = t.cap - p;
                if (extra < minExtra) {
                    minExtra = extra;
                    bestTable = t.no;
                }
            }
        }

        if (bestTable != -1)
            return {bestTable};

        return {};
    }

    void showTables() {
        line();
        cout << setw(10) << left << "Table"
             << setw(10) << left << "Capacity"
             << setw(15) << left << "Status"
             << setw(20) << left << "Customer" << endl;
        subline();
        for (auto &t : tables) {
            string status = t.cleaning ? "Cleaning" : t.occupied ? "Occupied" : "Free";
            if(t.isPrivate) status += " (Private)";
            cout << setw(10) << left << t.no
                 << setw(10) << left << t.cap
                 << setw(15) << left << status
                 << setw(20) << left << (t.occupied ? t.customerName : "") << endl;
        }
    }

    void takeOrder() {
        int p;
        cout << "People: "; cin >> p;
        vector<int> tnos = findTablesForGroup(p);

        if (tnos.empty()) {
            waitQ.push(p);
            cout << "No single table available, added to waiting queue\n";
            return;
        }

        Table &t = tables[tnos[0] - 1];
        t.occupied = true;

        cout << "\n=== Table Assigned: " << t.no << " ===\n\n";

        cin.ignore();
        cout << "Customer Name: "; getline(cin, t.customerName);
        cout << "Phone Number: "; getline(cin, t.phone);

        int mem;
        cout << "Select membership: 0.Regular 1.Silver 2.Gold: ";
        cin >> mem;

        if(mem==1) t.membership = SILVER;
        else if(mem==2) t.membership = GOLD;
        else t.membership = REGULAR;

        int n;
        showMenu();
        cout << "How many different items to order? "; cin >> n;

        for(int i=0;i<n;i++){
            int ch, qty;
            cout << "Item ID: "; cin >> ch;
            if(ch < 1 || ch > menu.size()){ cout << "Invalid item\n"; i--; continue;}
            cout << "Quantity: "; cin >> qty;
            t.order.add(menu[ch-1], qty);
        }

        cout << "\nOrder placed successfully at Table " << t.no << "!\n";
    }

    void addToExistingOrder() {
        int tno;
        cout << "Enter Table No: "; cin >> tno;

        if (tno < 1 || tno > tables.size() || !tables[tno-1].occupied) {
            cout << "Invalid table or no active order!\n";
            return;
        }

        Table &t = tables[tno - 1];
        int n;
        showMenu();
        cout << "How many different items to add? "; cin >> n;

        for(int i=0;i<n;i++){
            int ch, qty;
            cout << "Item ID: "; cin >> ch;
            if(ch < 1 || ch > menu.size()){ cout << "Invalid item\n"; i--; continue;}
            cout << "Quantity: "; cin >> qty;
            t.order.add(menu[ch-1], qty);
        }

        cout << "Additional items added successfully!\n";
    }

    void showAllStatus() {
        line();
        cout << "LIVE ORDER STATUS\n";
        subline();
        for (auto &t : tables) {
            if (t.occupied && !t.order.items.empty()) {
                cout << "Table " << t.no << " (" << t.customerName << "): ";
                t.order.showStatus();
            }
        }
        line();
    }

    void updateOrderStatus() {
        int tno;
        cout << "Enter Table No: ";
        cin >> tno;

        if (tno < 1 || tno > tables.size()) {
            return;
        }

        tables[tno - 1].order.updateStatus();

        cout << "Updated Status: ";
        tables[tno - 1].order.showStatus();
    }

    void generateBill() {
        int tno;
        cout << "Table no: "; cin >> tno;

        if (tno < 1 || tno > tables.size() || !tables[tno-1].occupied) {
            cout << "Invalid table or no active order!\n";
            return;
        }

        Table &t = tables[tno - 1];
        float sub = t.order.total();
        float gst = sub * GST;
        float total = sub + gst;

        float discount = 0;
        if(t.membership==REGULAR) discount = total*0.03;
        else if(t.membership==SILVER) discount = total*0.10;
        else if(t.membership==GOLD) discount = total*0.15;

        total = total - discount;

        int pay;
        cout << "1.Cash 2.Debit 3.Credit 4.UPI: "; cin >> pay;
        if (pay == CREDIT) total += total * CREDIT_SURCHARGE;

        cout << fixed << setprecision(2);
        line();

        cout << setw(30) << left << "Customer: " << t.customerName << endl;
        cout << setw(30) << left << "Phone: " << t.phone << endl;
        cout << setw(30) << left << "Table No: " << t.no << endl;

        subline();

        cout << setw(25) << left << "Item"
             << setw(5) << right << "Qty"
             << setw(10) << right << "Price"
             << setw(10) << right << "Total" << endl;

        subline();

        vector<MenuItem> temp = t.order.items;
        while(!temp.empty()){
            string n = temp[0].name;
            int c = count_if(temp.begin(), temp.end(), [&](MenuItem &m){ return m.name==n; });
            float price = temp[0].price;

            cout << setw(25) << left << n
                 << setw(5) << right << c
                 << setw(10) << right << price
                 << setw(10) << right << c*price << endl;

            temp.erase(remove_if(temp.begin(), temp.end(),
                [&](MenuItem &m){ return m.name==n; }), temp.end());
        }

        subline();

        cout << setw(40) << left << "Subtotal:" << setw(10) << right << sub << endl;
        if(discount>0)
            cout << setw(40) << left << "Membership Discount:" << setw(10) << right << discount << endl;
        cout << setw(40) << left << "GST:" << setw(10) << right << gst << endl;
        cout << setw(40) << left << "TOTAL:" << setw(10) << right << total << endl;

        line();

        t.order.clear();
        t.occupied = false;
        t.cleaning = true;
        t.customerName = "";
        t.phone = "";
        t.membership = REGULAR;

        cout << "Table marked for cleaning\n";
    }

    void cleanTable() {
        int t;
        cout << "Clean table: "; cin >> t;
        if (t<1 || t>tables.size()) {
            cout << "Invalid table\n";
            return;
        }
        tables[t-1].cleaning = false;
        cout << "Table ready\n";
    }

    void run() {
        showHeader();
        int ch;
        while(1){
            cout << "\n1.Tables\n2.Order\n3.Live Status\n4.Update Status\n5.Add to Existing Order\n6.Bill\n7.Clean\n8.Exit\n";
            cout << "Choice: "; cin >> ch;

            switch(ch){
                case 1: showTables(); break;
                case 2: takeOrder(); break;
                case 3: showAllStatus(); break;
                case 4: updateOrderStatus(); break;
                case 5: addToExistingOrder(); break;
                case 6: generateBill(); break;
                case 7: cleanTable(); break;
                case 8: return;
                default: cout << "Invalid choice\n";
            }
        }
    }
};

// ---------------- MAIN ----------------
int main(){
    Restaurant r;
    r.run();
}
