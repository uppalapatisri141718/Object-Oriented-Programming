#include <iostream>
#include <fstream>
using namespace std;
class Student {
private:
 string name;
 int rollNo;
 string course;
 int semester;
 string contact;
 string email;
 float cgpa;
 float attendance;
public:
 Student() {
 name = "";
 rollNo = 0;
 course = "";
 semester = 0;
 contact = "";
 email = "";
 cgpa = 0.0;
 attendance = 0.0;
 }
Student(string n, int r, string c, int sem,
 string con, string em, float g, float att) {
 name = n;
 rollNo = r;
 course = c;
 semester = sem;
 contact = con;
 email = em;
 cgpa = g;
 attendance = att;
 }
 Student(const Student &s) {
 name = s.name;
 rollNo = s.rollNo;
 course = s.course;
 semester = s.semester;
 contact = s.contact;
 email = s.email;
 cgpa = s.cgpa;
 attendance = s.attendance;
 }
 void input() {
 cin.ignore();
 cout << "\nEnter Name: ";
 getline(cin, name);
cout << "Enter Roll No: ";
 cin >> rollNo;
cin.ignore();
 cout << "Enter Course: ";
 getline(cin, course);
 cout << "Enter Semester: ";
 cin >> semester;
 cout << "Enter Contact: ";
 cin >> contact;
 cin.ignore();
 cout << "Enter Email : ";
 getline(cin, email);
 cout << "Enter CGPA: ";
 cin >> cgpa;
cout << "Enter Attendance (%): ";
 cin >> attendance;
 }
 void display() const {
 cout << "\n-----------------------------\n";
 cout << "Name: " << name << endl;
 cout << "Roll No: " << rollNo << endl;
 cout << "Course: " << course << endl;
 cout << "Semester: " << semester << endl;
 cout << "Contact: " << contact << endl;
 cout << "Email: " << email << endl;
 cout << "CGPA: " << cgpa << endl;
 cout << "Attendance: " << attendance << "%";
 if (attendance < 75)
 cout << " (Not Eligible - Low Attendance!)";
cout << endl;
 cout << "-----------------------------\n";
 }
 int getRollNo() const {
 return rollNo;
 }
void update() {
 cout << "\nUpdating details for Roll No: " << rollNo << endl;
 input();
 }
void saveToFile(ofstream &file) {
 file << name << "," << rollNo << "," << course << ","
 << semester << "," << contact << ","
 << email << "," << cgpa << "," << attendance << endl;
 }
 ~Student() {
 // Optional cleanup
 }
};
int main() {
 Student students[100];
 int count = 0;
 int choice, roll, found;
do {
 cout << "\n===== STUDENT PROFILE MANAGER =====\n";
 cout << "1. Add Student\n";
 cout << "2. Display All\n";
 cout << "3. Search by Roll No\n";
cout << "4. Update Student\n";
 cout << "5. Delete Student\n";
 cout << "6. Save to File\n";
 cout << "7. Exit\n";
 cout << "Enter choice: ";
 cin >> choice;
switch(choice) {
 case 1:
 if (count < 100) {
 students[count].input();
 count++;
 } else {
 cout << "Student limit reached!\n";
 }
 break;
 case 2:
 if (count == 0) {
 cout << "No student records found!\n";
 } else {
 for(int i = 0; i < count; i++)
 students[i].display();
 }
 break;
 case 3:
 cout << "Enter Roll No to Search: ";
 cin >> roll;
 found = 0;
 for(int i = 0; i < count; i++) {
if(students[i].getRollNo() == roll) {
 students[i].display();
 found = 1;
 }
 }
 if(!found)
 cout << "Student not found!\n";
 break;
 case 4:
 cout << "Enter Roll No to Update: ";
 cin >> roll;
 found = 0;
 for(int i = 0; i < count; i++) {
 if(students[i].getRollNo() == roll) {
 students[i].update();
 cout << "Record Updated Successfully!\n";
 found = 1;
 }
 }
 if(!found)
 cout << "Student not found!\n";
 break;
 case 5:
 cout << "Enter Roll No to Delete: ";
 cin >> roll;
 found = 0;
 for(int i = 0; i < count; i++) {
 if(students[i].getRollNo() == roll) {
for(int j = i; j < count-1; j++)
 students[j] = students[j+1];
 count--;
 cout << "Record Deleted Successfully!\n";
 found = 1;
 break;
 }
 }
 if(!found)
 cout << "Student not found!\n";
 break;
 case 6: {
 ofstream file("students.txt");
 for(int i = 0; i < count; i++)
 students[i].saveToFile(file);
 file.close();
 cout << "Data Saved to students.txt Successfully!\n";
 break;
 }
case 7:
 cout << "Exiting Program...\n";
 break;
 default:
 cout << "Invalid Choice!\n";
 }
 } while(choice != 7);
return 0;
}
