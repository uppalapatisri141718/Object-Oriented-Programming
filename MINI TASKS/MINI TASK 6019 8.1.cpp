#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class DataException {
    string msg;
public:
    DataException(string m) {
        msg = m;
    }
    string what() {
        return msg;
    }
}
template <typename T>
T safeDivide(T a, T b) {
    if (b == 0)
        throw DataException("Division by zero!");
    return a / b;
}
template <typename T>
class Square {
public:
    T operator()(T x) {
        return x * x;
    }
};
template <typename T>
class DataProcessor {
    vector<T> data;
    vector<T> backup;
public:
    void addMultiple() {
        T val;
        cout << "Enter values (-1 to stop):\n";
        while (true) {
            cin >> val;
            if (val == -1)
                break;
            if (!cin) {
                cin.clear();
                cin.ignore(1000, '\n');
                throw DataException("Invalid input!");
            }
            backup = data;
            data.push_back(val);
        }
        cout << "Values added successfully\n";
    }
    void display() {
        if (data.empty())
            throw DataException("No data!");
        cout << "\nData: ";
        for (auto x : data)
            cout << x << " ";
        cout << endl;
    }
    void process() {
        if (data.empty())
            throw DataException("No data!");
        cout << "\nProcessed (value / 2):\n";
        for (auto x : data)
            cout << x << " -> " << safeDivide(x, (T)2) << endl;
    }
    void transformData() {
        if (data.empty())
            throw DataException("No data!");
        backup = data;
        transform(data.begin(), data.end(),
                  data.begin(), Square<T>());
        cout << "Data squared\n";
    }
    void filterPositive() {
        if (data.empty())
            throw DataException("No data!");
        backup = data;
        data.erase(remove_if(data.begin(), data.end(),
            [](T x) { return x < 0; }), data.end());
        cout << "Negative values removed\n";
    }
    void sortData(bool asc = true) {
        if (data.empty())
            throw DataException("No data!");
        backup = data;
        if (asc)
            sort(data.begin(), data.end());
        else
            sort(data.begin(), data.end(), greater<T>());
    }
    void statistics() {
        if (data.empty())
            throw DataException("No data!");
        T sum = 0;
        for (auto x : data)
            sum += x;
        cout << "\nSum: " << sum << endl;
        cout << "Average: " << sum / data.size() << endl;
        cout << "Max: "
             << *max_element(data.begin(), data.end()) << endl;
    }
    void undo() {
        data = backup;
        cout << "Undo successful\n";
    }
};
int main() {
    DataProcessor<double> dp;
    int choice;
    cout << "\n====== SAFE DATA PROCESSOR ======\n";
    while (true) {
        cout << "\n1. Add Multiple Data\n";
        cout << "2. Display\n";
        cout << "3. Process\n";
        cout << "4. Transform (Square)\n";
        cout << "5. Filter Positive\n";
        cout << "6. Sort Ascending\n";
        cout << "7. Sort Descending\n";
        cout << "8. Statistics\n";
        cout << "9. Undo\n";
        cout << "10. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        try {
            switch (choice) {
                case 1: dp.addMultiple(); break;
                case 2: dp.display(); break;
                case 3: dp.process(); break;
                case 4: dp.transformData(); break;
                case 5: dp.filterPositive(); break;
                case 6: dp.sortData(true); break;
                case 7: dp.sortData(false); break;
                case 8: dp.statistics(); break;
                case 9: dp.undo(); break;
                case 10:
                    cout << "Program Ended\n";
                    return 0;
                default:
                    throw DataException("Invalid choice!");
            }
        }
        catch (DataException e) {
            cout << "Error: " << e.what() << endl;
        }
        catch (...) {
            cout << "Unknown error occurred!\n";
        }
    }
}
