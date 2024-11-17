#include <iostream>
using namespace std;

class Television {
    int modelNumber;
    int screenSize;
    double price;

public:
    friend istream& operator>>(istream& input, Television& tv) {
        cout << "Enter model number (4 digits or less): ";
        input >> tv.modelNumber;
        if (tv.modelNumber > 9999) throw "Invalid model number!";

        cout << "Enter screen size in inches (up to 70 inches): ";
        input >> tv.screenSize;
        if (tv.screenSize > 70) throw "Invalid screen size!";

        cout << "Enter price (non-negative, up to 5000 dollars): ";
        input >> tv.price;
        if (tv.price < 0 || tv.price > 5000) throw "Invalid price!";
        
        return input;
    }

    friend ostream& operator<<(ostream& output, const Television& tv) {
        output << "\nModel Number: " << tv.modelNumber
               << "\nScreen Size: " << tv.screenSize << " inches"
               << "\nPrice: $" << tv.price << endl;
        return output;
    }
};

int main() {
    Television tv;
    try {
        cin >> tv;
        cout << tv;
    } catch (const char* msg) {
        cerr << "Error: " << msg << endl;
    }
    return 0;
}