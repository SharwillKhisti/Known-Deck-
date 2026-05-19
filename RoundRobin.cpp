#include <iostream>
using namespace std;

struct Process {
    int pid;
    int at;     // Arrival Time
    int bt;     // Remaining Burst Time
    int rbt;    // Original Burst Time
    int ct;     // Completion Time
    int tat;    // Turnaround Time
    int wt;     // Waiting Time
    int visited;
};

int main() {

    int n, tq;

    cout << "Enter number of processes: ";
    cin >> n;

    cout << "Enter Time Quantum: ";
    cin >> tq;

    Process p[100];

    // Input
    for (int i = 0; i < n; i++) {

        cout << "Enter AT and BT for Process "
             << i + 1 << ": ";

        cin >> p[i].at >> p[i].bt;

        p[i].pid = i + 1;

        p[i].rbt = p[i].bt;

        p[i].visited = 0;
    }

    int completed = 0;

    int time = 0;

    // Round Robin Scheduling
    while (completed != n) {

        int found = 0;

        for (int i = 0; i < n; i++) {

            // Process has arrived and not completed
            if (p[i].at <= time && p[i].bt > 0) {

                found = 1;

                // Execute for Time Quantum
                if (p[i].bt > tq) {

                    time += tq;

                    p[i].bt -= tq;
                }

                // Process completes
                else {

                    time += p[i].bt;

                    p[i].bt = 0;

                    p[i].ct = time;

                    p[i].tat =
                        p[i].ct - p[i].at;

                    p[i].wt =
                        p[i].tat - p[i].rbt;

                    completed++;
                }
            }
        }

        // No process available → CPU Idle
        if (found == 0) {
            time++;
        }
    }

    // Output
    cout << "\nProcess\tAT\tBT\tCT\tTAT\tWT\n";

    for (int i = 0; i < n; i++) {

        cout << "P" << p[i].pid << "\t"
             << p[i].at << "\t"
             << p[i].rbt << "\t"
             << p[i].ct << "\t"
             << p[i].tat << "\t"
             << p[i].wt << endl;
    }

    return 0;
}