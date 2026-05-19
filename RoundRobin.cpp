#include <iostream>
#include <vector>
using namespace std;

struct Process {
    int pid;  // Process ID
    int at;   // Arrival Time
    int bt;   // Remaining Burst Time (will decrease)
    int tat;  // Turnaround Time
    int wt;   // Waiting Time
    int rbt;  // Original Burst Time (backup)
};

int main() {
    size_t n;
    int tq;

    int y = 0;  // completed processes count
    int x = 0;  // current time
    size_t i = 0;

    cout << "Enter number of processes: ";
    cin >> n;

    cout << "Enter Time Quantum: ";
    cin >> tq;

    vector<Process> p(n);

    // Input
    for (size_t j = 0; j < n; j++) {
        cout << "Enter AT and BT for Process " << j + 1 << ": ";
        cin >> p[j].at >> p[j].bt;

        p[j].pid = static_cast<int>(j + 1);
        p[j].rbt = p[j].bt;  // store original burst time
    }

    // Round Robin Scheduling
    while (true) {

        if (p[i].bt > 0) {

            if (p[i].bt > tq) {
                x += tq;
                p[i].bt -= tq;
            } else {
                x += p[i].bt;
                p[i].bt = 0;

                // Completion for this process
                p[i].tat = x - p[i].at;
                p[i].wt  = p[i].tat - p[i].rbt;

                y++;  // process completed
            }
        }

        if (y == static_cast<int>(n)) {
            break;
        }

        // Move to next process cyclically
        if (i == n - 1) {
            i = 0;
        } else {
            i++;
        }
    }

    // Output
    cout << "\nProcess\tAT\tBT\tTAT\tWT\n";

    for (size_t j = 0; j < n; j++) {
        cout << "P" << p[j].pid << "\t"
             << p[j].at << "\t"
             << p[j].rbt << "\t"
             << p[j].tat << "\t"
             << p[j].wt << "\n";
    }

    return 0;
}