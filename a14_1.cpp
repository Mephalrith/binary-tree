#include <iostream>
#include "binarytree.h"

using namespace std;
using namespace hardendavebintree;

int main() {
    binarytree list;
    int num;
    bool found;

    cout << "enter number to insert (negative to quit): ";
    cin >> num;
    while (num >= 0) {
        list.insert(num);
        cout << "enter number to insert (negative to quit): ";
        cin >> num;
    }

    list.print();

    cout << "\nTotal items: " << list.size() << endl;
    cout << "\nTotal Primes: " << list.numPrimes() << endl;

    cout << endl;

    cout << "enter number to find (negative to quit): ";
    cin >> num;
    while (num >= 0) {
        int result = list.find(num, found);
        if (found) {
            cout << "found. The data is " << result << endl;
        } else {
            cout << "not found." << endl;
        }

        cout << "enter number to find (negative to quit): ";
        cin >> num;
    }


    cout << "enter number to delete (negative to quit): ";
    cin >> num;
    while (num >= 0) {
        list.del(num, found);
        if (found) {
            cout << "found. The list is now ";
            list.print();
            cout << endl;
        } else {
            cout << "not found." << endl;
        }

        cout << "enter number to delete (negative to quit): ";
        cin >> num;
    }
}