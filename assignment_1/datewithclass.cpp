#include <iostream>
using namespace std;

class Date {
private:
    int day;
    int month;
    int year;

public:
    void initDate() {
        day = 0;
        month = 0;
        year = 0;
    }

    void printDateOnConsole() {
        cout << "Date: " << day << "/" << month << "/" << year << endl;
    }

    void acceptDateFromConsole() {
        cout << "Enter date in DD(Enter) MM(ENTER) YYYY(ENTER) format: ";
        cin >> day >> month >> year;
    }

    bool isLeapYear() {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
            return true;
        else
            return false;
    }
};

int menu() {
    int choice;

    cout << "\nMenu:\n";
    cout << "1. Initialize Date\n";
    cout << "2. Print Date\n";
    cout << "3. Accept Date\n";
    cout << "4. Check Leap Year\n";
    cout << "0. Exit\n";
    cout << "Enter your choice: ";

    cin >> choice;

    if (choice == 0) {
        cout << "Program Exit\n";
    }
    return choice;
}

int main() {
    Date date;
    int choice;

    while ((choice = menu()) != 0) {

        switch (choice) {
        case 1:
            date.initDate();
            cout << "Date created." << endl;
            break;
        case 2:
            date.printDateOnConsole();
            break;
        case 3:
            date.acceptDateFromConsole();
            break;
        case 4:
            if (date.isLeapYear()) {
                cout << "Leap Year" << endl;
            } else {
                cout << "Not a Leap Year!" << endl;
            }
            break;
        default:
            cout << "Invalid choice. Enter again." << endl;
        }
    }

    return 0;
}