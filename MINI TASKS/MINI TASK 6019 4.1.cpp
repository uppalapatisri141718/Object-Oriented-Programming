#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
class Point {
public:
 double x, y;
 void input() {
 cin >> x >> y;
 }
 void add(Point p) {
 cout << fixed << setprecision(2);
 cout << "Result: (" << x + p.x << "," << y + p.y << ")\n";
 }
 void subtract(Point p) {
 cout << fixed << setprecision(2);
 cout << "Result: (" << x - p.x << "," << y - p.y << ")\n";
 }
 void dotProduct(Point p) {
 cout << fixed << setprecision(2);
 cout << "Dot Product = " << x*p.x + y*p.y << endl;
 }
 void crossProduct(Point p) {
 cout << fixed << setprecision(2);
 cout << "Cross Product = " << x*p.y - y*p.x << endl;
}
void distance(Point p) {
 cout << fixed << setprecision(2);
 double d = sqrt((p.x-x)*(p.x-x) + (p.y-y)*(p.y-y));
 cout << "Distance = " << d << endl;
 }
 void magnitude() {
 cout << fixed << setprecision(2);
 cout << "Magnitude = " << sqrt(x*x + y*y) << endl;
 }
 void unitVector() {
 cout << fixed << setprecision(2);
 double mag = sqrt(x*x + y*y);
 cout << "Unit Vector = (" << x/mag << "," << y/mag << ")\n";
 }
 void scalarMultiply(double s) {
 cout << fixed << setprecision(2);
 cout << "Result: (" << s*x << "," << s*y << ")\n";
 }
 void angleBetween(Point p) {
 cout << fixed << setprecision(2);
 double dot = x*p.x + y*p.y;
 double m1 = sqrt(x*x + y*y);
 double m2 = sqrt(p.x*p.x + p.y*p.y);
 double ang = acos(dot/(m1*m2)) * 180 / M_PI;
 cout << "Angle = " << ang << " degrees\n";
 }
 void checkPerpendicular(Point p) {
 if(x*p.x + y*p.y == 0)
 cout << "Vectors are Perpendicular\n";
 else
 cout << "Vectors are NOT Perpendicular\n";
}
 void checkParallel(Point p) {
 if(x*p.y - y*p.x == 0)
 cout << "Vectors are Parallel\n";
 else
 cout << "Vectors are NOT Parallel\n";
 }
 void midpoint(Point p) {
 cout << fixed << setprecision(2);
 cout << "Midpoint = (" << (x+p.x)/2 << "," << (y+p.y)/2 << ")\n";
 }
 void normalize() {
 cout << fixed << setprecision(2);
 double mag = sqrt(x*x + y*y);
 cout << "Normalized = (" << x/mag << "," << y/mag << ")\n";
 }
 void rotate(double angle) {
 cout << fixed << setprecision(2);
 double rad = angle * M_PI / 180;
 double rx = x*cos(rad) - y*sin(rad);
 double ry = x*sin(rad) + y*cos(rad);
 cout << "Rotated = (" << rx << "," << ry << ")\n";
 }
};
int main() {
 int choice;
 Point p1, p2;
 double scalar, angle;
 do {
 cout << "\n---- 2D Toolkit ----\n";
 cout << "1. Add\n";
cout << "2. Subtract\n";
 cout << "3. Dot Product\n";
 cout << "4. Cross Product\n";
 cout << "5. Distance\n";
 cout << "6. Magnitude\n";
 cout << "7. Unit\n";
 cout << "8. Scalar Multiplication\n";
 cout << "9. Angle Between\n";
 cout << "10. Check Perpendicular\n";
 cout << "11. Check Parallel\n";
 cout << "12. Midpoint\n";
 cout << "13. Normalize\n";
 cout << "14. Rotate\n";
 cout << "0. Exit\n";
 cout << "Enter choice: ";
 cin >> choice;
 if(choice>=1 && choice<=5 || choice==9 || choice==10 || choice==11 || choice==12){
 cout<<"Enter first point (x y): ";
 p1.input();
 cout<<"Enter second point (x y): ";
 p2.input();
 }
 switch(choice){
 case 1: p1.add(p2); break;
 case 2: p1.subtract(p2); break;
 case 3: p1.dotProduct(p2); break;
 case 4: p1.crossProduct(p2); break;
 case 5: p1.distance(p2); break;
 case 6: p1.input(); p1.magnitude(); break;
 case 7: p1.input(); p1.unitVector(); break;
 case 8:
p1.input();
 cout<<"Enter scalar: ";
 cin>>scalar;
 p1.scalarMultiply(scalar);
 break;
 case 9: p1.angleBetween(p2); break;
 case 10: p1.checkPerpendicular(p2); break;
 case 11: p1.checkParallel(p2); break;
 case 12: p1.midpoint(p2); break;
 case 13: p1.input(); p1.normalize(); break;
 case 14:
 p1.input();
 cout<<"Enter angle: ";
 cin>>angle;
 p1.rotate(angle);
 break;
 }
 } while(choice!=0);
 return 0;
}
