#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>
using namespace std;
class Shape {
protected:
    static int count;
    int id;
public:
    Shape() { count++; id = count; }
    virtual double area() = 0;
    virtual double perimeter() = 0;
    virtual string getName() = 0;
    virtual void update() = 0;
    void display() {
        cout << left << setw(5) << id
             << setw(12) << getName()
             << right << setw(12) << fixed << setprecision(2) << area()
             << setw(15) << perimeter() << endl;
    }
    int getId() { return id; }
    virtual ~Shape() { count--; }
};
int Shape::count = 0;


class Circle : public Shape {
    double r;
public:
    Circle(double radius) { r = (radius <= 0) ? 1 : radius; }
    double area() { return 3.14 * r * r; }
    double perimeter() { return 2 * 3.14 * r; }
    string getName() { return "Circle"; }
    void update() { cout << "Enter new radius: "; cin >> r; }
};
class Rectangle : public Shape {
    double l, w;
public:
    Rectangle(double L, double W) { l=(L<=0)?1:L; w=(W<=0)?1:W; }
    double area() { return l*w; }
    double perimeter() { return 2*(l+w); }
    string getName() { return "Rectangle"; }
    void update() { cout << "Enter length & width: "; cin >> l >> w; }
};
class Square : public Shape {
    double s;
public:
    Square(double side) { s = (side<=0)?1:side; }
    double area() { return s*s; }
    double perimeter() { return 4*s; }
    string getName() { return "Square"; }
    void update() { cout << "Enter new side: "; cin >> s; }
};
class Triangle : public Shape {
    double a,b,c;
public:
    Triangle(double x,double y,double z) {
        if(x+y>z && x+z>y && y+z>x) { a=x; b=y; c=z; }
        else { a=3; b=4; c=5; }
    }
    double area() { double s=(a+b+c)/2; return sqrt(s*(s-a)*(s-b)*(s-c)); }
    double perimeter() { return a+b+c; }
    string getName() { return "Triangle"; }
    void update() { cout << "Enter new sides: "; cin >> a >> b >> c; }
};
int main() {
    vector<Shape*> shapes;
    int choice;
    cout << "\n======= SHAPE POLYMORPHISM ENGINE =======\n";
    while(true) {
        cout << "\n1.Add 2.Display 3.Total 4.Search\n"
                "5.Update 6.Delete 7.Sort 8.Clear 9.Exit\n";
        cin >> choice;
        if(choice == 9) break;
        switch(choice) {
        case 1: {
            int type; cout << "1.Circle 2.Rectangle 3.Square 4.Triangle: "; cin >> type;
            if(type==1) { double r; cin >> r; shapes.push_back(new Circle(r)); }
            else if(type==2) { double l,w; cin >> l >> w; shapes.push_back(new Rectangle(l,w)); }
            else if(type==3) { double s; cin >> s; shapes.push_back(new Square(s)); }
            else if(type==4) { double a,b,c; cin >> a >> b >> c; shapes.push_back(new Triangle(a,b,c)); }
            break;
        }

        case 2: 
            cout << "\nID   Shape        Area        Perimeter\n";
            cout << "------------------------------------------\n";
            for(auto s:shapes) s->display(); 
            break;
        case 3: {
            double A=0,P=0;
            for(auto s:shapes){ A+=s->area(); P+=s->perimeter(); }
            cout << "Total Area: " << A << "  Total Perimeter: " << P << endl;
            break;
        }
        case 4: {
            int id; cout << "Enter ID to search: "; cin >> id;
            bool found=false;
            for(auto s:shapes) { if(s->getId()==id){ s->display(); found=true; break; } }
            if(!found) cout << "Shape not found!\n";
            break;
        }
        case 5: {
            int id; cout << "Enter ID to update: "; cin >> id;
            bool found=false;
            for(auto s:shapes){ if(s->getId()==id){ s->update(); found=true; break; } }
            if(!found) cout << "Shape not found!\n";
            break;
        }
        case 6: {
            int id; cout << "Enter ID to delete: "; cin >> id;
            for(auto it=shapes.begin(); it!=shapes.end(); ++it){
                if((*it)->getId()==id){ delete *it; shapes.erase(it); break; }
            }
            break;
        }
        case 7: 
            sort(shapes.begin(),shapes.end(),
                 [](Shape* a,Shape* b){ return a->area()<b->area(); });
            cout << "Shapes sorted by area.\n"; break;
        case 8:
            for(auto s:shapes) delete s;
            shapes.clear();
            cout << "All shapes cleared.\n"; break;
        default: cout << "Invalid choice!\n";
        }
    }
    for(auto s:shapes) delete s;
    shapes.clear();
    cout << "Program exited successfully.\n";
    return 0;
}
