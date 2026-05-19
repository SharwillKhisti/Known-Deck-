#include <iostream>
using namespace std;

int main() {
    int nb, np;

    cout << "Enter number of blocks: ";
    cin >> nb;

    cout << "Enter number of processes: ";
    cin >> np;

    int blockSize[100];
    int processSize[100];
    int allocation[100];
    int fragment[100];
    int blockUsed[100];

    // Input block sizes
    cout << "Enter sizes of blocks:\n";
    for (int i = 0; i < nb; i++) {
        cin >> blockSize[i];
        blockUsed[i] = 0;
    }

    // Input process sizes
    cout << "Enter sizes of processes:\n";
    for (int i = 0; i < np; i++) {
        cin >> processSize[i];
        allocation[i] = -1;
        fragment[i] = 0;
    }

    // Worst Fit Allocation
    for (int i = 0; i < np; i++) {

        int worstIndex = -1;

        for (int j = 0; j < nb; j++) {

            if (blockUsed[j] == 0 &&
                blockSize[j] >= processSize[i]) {

                if (worstIndex == -1 ||
                    blockSize[j] > blockSize[worstIndex]) {

                    worstIndex = j;
                }
            }
        }

        if (worstIndex != -1) {

            allocation[i] = worstIndex;
            blockUsed[worstIndex] = 1;

            fragment[i] =
                blockSize[worstIndex] - processSize[i];
        }
    }

    // Display Output
    cout << "\nProcess No.\tProcess Size\tBlock No.\tBlock Size\tFragment\n";

    for (int i = 0; i < np; i++) {

        cout << i << "\t\t"
             << processSize[i] << "\t\t";

        if (allocation[i] != -1) {

            cout << "B" << allocation[i] << "\t\t"
                 << blockSize[allocation[i]] << "\t\t"
                 << fragment[i] << endl;

        } else {

            cout << "Not Allocated\t--\t\t--" << endl;
        }
    }

    return 0;
}