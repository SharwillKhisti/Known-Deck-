#include <iostream>
using namespace std;

int main() {
    int np, nr;

    // Input number of processes and resources
    cout << "Enter the number of processes (np): ";
    cin >> np;

    cout << "Enter the number of resources (nr): ";
    cin >> nr;

    // Matrices and arrays
    int allocation[np][nr];
    int maxm[np][nr];
    int need[np][nr];
    int available[nr];
    int safeseq[np];
    int finish[np];

    int i, j, k = 0, flag;

    // Initialize finish array
    for (i = 0; i < np; i++) {
        finish[i] = 0;
    }

    // Input Allocation Matrix
    cout << "\nEnter the Allocation Matrix:\n";
    for (i = 0; i < np; i++) {
        for (j = 0; j < nr; j++) {
            cin >> allocation[i][j];
        }
    }

    // Input Max Matrix
    cout << "\nEnter the Max Matrix:\n";
    for (i = 0; i < np; i++) {
        for (j = 0; j < nr; j++) {
            cin >> maxm[i][j];
        }
    }

    // Input Available Resources
    cout << "\nEnter the Available Resources:\n";
    for (j = 0; j < nr; j++) {
        cin >> available[j];
    }

    // Calculate Need Matrix
    cout << "\nCalculating Need Matrix...\n";

    for (i = 0; i < np; i++) {
        for (j = 0; j < nr; j++) {
            need[i][j] = maxm[i][j] - allocation[i][j];
            cout << need[i][j] << " ";
        }
        cout << endl;
    }

    // Find Safe Sequence
    for (i = 0; i < np; i++) {

        flag = 0;

        if (finish[i] == 0) {

            for (j = 0; j < nr; j++) {

                if (need[i][j] > available[j]) {
                    flag = 1;
                    break;
                }
            }

            // Process can execute
            if (flag == 0) {

                finish[i] = 1;
                safeseq[k] = i;
                k++;

                // Release resources
                for (j = 0; j < nr; j++) {
                    available[j] += allocation[i][j];
                }

                // Restart checking from beginning
                i = -1;
            }
        }
    }

    // Check if system is safe
    int isSafe = 1;

    for (i = 0; i < np; i++) {
        if (finish[i] == 0) {
            isSafe = 0;
            break;
        }
    }

    // Output result
    if (isSafe == 1) {

        cout << "\nSystem is in a SAFE STATE.\n";
        cout << "Safe Sequence is: ";

        for (i = 0; i < np; i++) {
            cout << "P" << safeseq[i];

            if (i != np - 1) {
                cout << " -> ";
            }
        }

        cout << endl;

    } else {

        cout << "\nSystem is in a DEADLOCK STATE.\n";
        cout << "Safe sequence not possible.\n";
    }

    return 0;
}