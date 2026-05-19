#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 1) Define Data
    size_t np, nf;
    int LA, PA;
    int pagenum, offset, framenum, pagesize;

    // 2) Input
    cout << "Enter number of pages (np): ";
    cin >> np;

    cout << "Enter number of frames (nf): ";
    cin >> nf;

    cout << "Enter page size: ";
    cin >> pagesize;

    vector<int> PageTable(np);

    cout << "\n--- Enter Page Table entries ---\n";

    for (size_t i = 0; i < np; i++) {
        cout << "Enter frame number for Page " << i << ": ";
        cin >> PageTable[i];

        // Validation
        if (PageTable[i] >= static_cast<int>(nf) || PageTable[i] < 0) {
            cout << "[!] Warning: Frame " << PageTable[i]
                 << " is out of bounds (should be 0 to "
                 << (nf - 1) << ").\n";
        }
    }

    cout << "\nEnter Logical Address (LA): ";
    cin >> LA;

    // 3) Address Translation

    // a) Page Number
    pagenum = LA / pagesize;

    // b) Offset
    offset = LA % pagesize;

    // Boundary check
    if (pagenum >= static_cast<int>(np) || pagenum < 0) {
        cout << "\nError: Logical address " << LA
             << " results in Page Number " << pagenum
             << ", which is outside the page table limit (0 to "
             << (np - 1) << ").\n";
        return 1;
    }

    // c) Frame Number
    framenum = PageTable[static_cast<size_t>(pagenum)];

    // d) Physical Address
    PA = (framenum * pagesize) + offset;

    // 4) Output
    cout << "\n--- Address Translation Result ---\n";
    cout << "Logical Address (LA) : " << LA << endl;
    cout << "Page Size            : " << pagesize << endl;
    cout << "Page Number          : " << pagenum << endl;
    cout << "Offset               : " << offset << endl;
    cout << "Frame Number         : " << framenum << endl;
    cout << "Physical Address (PA): " << PA << endl;

    return 0;
}