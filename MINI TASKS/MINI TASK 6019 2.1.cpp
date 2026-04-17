#include <iostream>
using namespace std;
long long factorial(int);
double power(double, int = 2);
bool isPrime(int);
bool isStrong(int);
bool isPerfect(int);
double add(double, double);
double subtract(double, double);
double multiply(double, double);
double divide(double, double);
int gcd(int, int);
int lcm(int, int);
long long factorial(int n) {
 if (n < 0) return -1;
 if (n == 0 || n == 1)
 return 1;
 return n * factorial(n - 1);
}
double power(double base, int exp) {
 double result = 1;
 for (int i = 0; i < exp; i++)
 result *= base;
 return result;
}
bool isPrime(int n) {
 if (n <= 1) return false;
 for (int i = 2; i * i <= n; i++)
 if (n % i == 0)
 return false;
 return true;
}
bool isStrong(int n) {
 int original = n, sum = 0;
 while (n != 0) {
int digit = n % 10;
 sum += factorial(digit);
 n /= 10;
 }
 return sum == original;
}
bool isPerfect(int n) {
 int sum = 0;
 for (int i = 1; i < n; i++)
 if (n % i == 0)
 sum += i;
 return sum == n;
}
double add(double a, double b) { return a + b; }
double subtract(double a, double b) { return a -b; }
double multiply(double a, double b) { return a * b; }
double divide(double a, double b) {
 if (b == 0) {
cout << "Division by zero not allowed.\n";
 return 0;
 }
 return a / b;
}
int gcd(int a, int b) {
 while (b != 0) {
 int temp = b;
 b = a % b;
 a = temp;
 }
 return a;
}
int lcm(int a, int b) {
 return (a * b) / gcd(a, b);
}
int main() {
 int choice;
 do {
 cout << "\n=================================\n";
 cout << " MATH TOOLKIT LIBRARY\n";
 cout << "=================================\n";
 cout << "1. Addition\n";
 cout << "2. Subtraction\n";
 cout << "3. Multiplication\n";
 cout << "4. Division\n";
 cout << "5. Factorial\n";
 cout << "6. Power\n";
cout << "7. GCD\n";
 cout << "8. LCM\n";
 cout << "9. Number Special Checks\n";
 cout << "0. Exit\n";
 cout << "Enter your choice: ";
 cin >> choice;
 double a, b;
 int n, x, y;
switch (choice) {
 case 1:
 cout << "Enter two numbers: ";
 cin >> a >> b;
 cout << "Result = " << add(a, b) << endl;
 break;
 case 2:
 cout << "Enter two numbers: ";
 cin >> a >> b;
 cout << "Result = " << subtract(a, b) << endl;
 break;
 case 3:
 cout << "Enter two numbers: ";
 cin >> a >> b;
 cout << "Result = " << multiply(a, b) << endl;
 break;
case 4:
 cout << "Enter two numbers: ";
 cin >> a >> b;
 cout << "Result = " << divide(a, b) << endl;
break;
 case 5:
 cout << "Enter number: ";
 cin >> n;
 cout << "Factorial = " << factorial(n) << endl;
 break;
 case 6:
 cout << "Enter base and exponent: ";
 cin >> a >> n;
 cout << "Result = " << power(a, n) << endl;
 break;
 case 7:
 cout << "Enter two numbers: ";
 cin >> x >> y;
 cout << "GCD = " << gcd(x, y) << endl;
 break;
 case 8:
 cout << "Enter two numbers: ";
 cin >> x >> y;
 cout << "LCM = " << lcm(x, y) << endl;
 break;
 case 9:
{
 int subChoice;
 cout << "\n--- Number Special Checks ---\n";
 cout << "1. Prime Check\n";
 cout << "2. Strong Number\n";
 cout << "3. Perfect Number\n";
cout << "Enter choice: ";
 cin >> subChoice;
cout << "Enter number: ";
 cin >> n;
switch (subChoice) {
 case 1:
 cout << (isPrime(n) ? "Prime Number\n" : "Not Prime\n");
 break;
 case 2:
 cout << (isStrong(n) ? "Strong Number\n" : "Not Strong\n");
 break;
 case 3:
 cout << (isPerfect(n) ? "Perfect Number\n" : "Not Perfect\n")
 break;
 default:
 cout << "Invalid choice\n";
 }
 break;
 }
 case 0:
 cout << "Exiting Program...\n";
 break;
 default:
 cout << "Invalid choice!\n";
 }
 } while (choice != 0);
return 0;
}
