#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;
class Employee {
protected:
 string name;
 int id;
 double basicSalary;
public:
 Employee(string n, int i, double salary) {
 name = n;
 id = i;
 basicSalary = salary;
 }
 virtual double calculateSalary() {
 return basicSalary;
 }
 virtual string getRole() {
 return "Employee";
 }
 virtual void displaySalary() {
 cout << left << setw(15) << name
 << setw(10) << id
 << setw(15) << getRole()
 << right << setw(10) << fixed << setprecision(2)
<< calculateSalary() << endl;
 }
};
class Manager : public Employee {
private:
 double bonus, allowance;
public:
 Manager(string n, int i, double s, double b, double a)
 : Employee(n, i, s) {
 bonus = b;
 allowance = a;
 }
 double calculateSalary() override {
 return basicSalary + bonus + allowance;
 }
 string getRole() override {
 return "Manager";
 }
};
class Developer : public Employee {
private:
 double overtime, projectIncentive;
public:
 Developer(string n, int i, double s, double ot, double pi)
 : Employee(n, i, s) {
 overtime = ot;
 projectIncentive = pi;
 }
 double calculateSalary() override {
return basicSalary + overtime + projectIncentive;
 }
 string getRole() override {
 return "Developer";
 }
};
class Intern : public Employee {
private:
 double stipend;
public:
 Intern(string n, int i, double st)
 : Employee(n, i, 0) {
 stipend = st;
 }
 double calculateSalary() override {
 return stipend;
 }
 string getRole() override {
 return "Intern";
 }
};
class HR : public Employee {
private:
 double bonus;
public:
 HR(string n, int i, double s, double b)
 : Employee(n, i, s) {
 bonus = b;
 }
double calculateSalary() override {
 return basicSalary + bonus;
 }
 string getRole() override {
 return "HR";
 }
};
class Salesperson : public Employee {
private:
 double commission;
public:
 Salesperson(string n, int i, double s, double c)
 : Employee(n, i, s) {
 commission = c;
 }
 double calculateSalary() override {
 return basicSalary + commission;
 }
 string getRole() override {
 return "Salesperson";
 }
};
int main() {
 vector<Employee*> employees;
 int choice;
 cout << "=== Employee Payroll System ===" << endl;
 while (true) {
 cout << "\n1.Manager 2.Developer 3.Intern 4.HR 5.Salesperson 6.Exit\n";
cout << "Enter choice: ";
 cin >> choice;
 if (choice == 6) break;
 string name;
 int id;
 double salary, bonus, allowance, overtime, pi, stipend, commission;
 cout << "Enter Name: ";
 cin >> ws;
 getline(cin, name);
 cout << "Enter ID: ";
 cin >> id;
 switch (choice) {
 case 1:
 cout << "Enter Salary, Bonus, Allowance: ";
 cin >> salary >> bonus >> allowance;
 employees.push_back(new Manager(name, id, salary, bonus, allowance));
 break;
 case 2:
 cout << "Enter Salary, Overtime, Incentive: ";
 cin >> salary >> overtime >> pi;
 employees.push_back(new Developer(name, id, salary, overtime, pi));
 break;
 case 3:
 cout << "Enter Stipend: ";
 cin >> stipend;
 employees.push_back(new Intern(name, id, stipend));
 break;
case 4:
 cout << "Enter Salary, Bonus: ";
 cin >> salary >> bonus;
 employees.push_back(new HR(name, id, salary, bonus));
 break;
 case 5:
 cout << "Enter Salary, Commission: ";
 cin >> salary >> commission;
 employees.push_back(new Salesperson(name, id, salary, commission));
 break;
 default:
 cout << "Invalid choice!" << endl;
 }
 }
 cout << "\n--- Payroll ---\n";
 cout << left << setw(15) << "Name"
 << setw(10) << "ID"
 << setw(15) << "Role"
 << right << setw(10) << "Salary" << endl;
 double total = 0;
 for (auto emp : employees) {
 emp->displaySalary();
 total += emp->calculateSalary();
 }
 cout << "Total Payroll: " << total << endl;
 for (auto emp : employees)
 delete emp;
 return 0;
}
