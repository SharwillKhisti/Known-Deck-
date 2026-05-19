#include <iostream>
using namespace std;

int main() {

    // Variables
    int np, nf;
    int LA, PA;
    int pagenum, offset, framenum, pagesize;

    // Input
    cout << "Enter number of pages (np): ";
    cin >> np;

    cout << "Enter number of frames (nf): ";
    cin >> nf;

    cout << "Enter page size: ";
    cin >> pagesize;

    // Page Table Array
    int PageTable[100];

    cout << "\n--- Enter Page Table entries ---\n";

    for (int i = 0; i < np; i++) {

        cout << "Enter frame number for Page "
             << i << ": ";

        cin >> PageTable[i];

        // Validation
        if (PageTable[i] >= nf || PageTable[i] < 0) {

            cout << "[!] Warning: Frame "
                 << PageTable[i]
                 << " is out of bounds (0 to "
                 << nf - 1 << ")\n";
        }
    }

    // Input Logical Address
    cout << "\nEnter Logical Address (LA): ";
    cin >> LA;

    // Step 1: Find Page Number
    pagenum = LA / pagesize;

    // Step 2: Find Offset
    offset = LA % pagesize;

    // Boundary Check
    if (pagenum >= np || pagenum < 0) {

        cout << "\nError: Invalid Page Number "
             << pagenum << endl;

        return 1;
    }

    // Step 3: Find Frame Number
    framenum = PageTable[pagenum];

    // Step 4: Find Physical Address
    PA = (framenum * pagesize) + offset;

    // Output
    cout << "\n--- Address Translation Result ---\n";

    cout << "Logical Address (LA) : "
         << LA << endl;

    cout << "Page Size            : "
         << pagesize << endl;

    cout << "Page Number          : "
         << pagenum << endl;

    cout << "Offset               : "
         << offset << endl;

    cout << "Frame Number         : "
         << framenum << endl;

    cout << "Physical Address(PA) : "
         << PA << endl;

    return 0;
}