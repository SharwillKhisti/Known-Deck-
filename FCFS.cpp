#include <iostream>
using namespace std;

struct process_struct {
    int pid;
    int at;   // Arrival Time
    int bt;   // Burst Time
    int ct;   // Completion Time
    int tat;  // Turnaround Time
    int wt;   // Waiting Time
    int rt;   // Response Time
    int start_time;
};

int main() {

    int n;

    float sum_tat = 0.0f, sum_wt = 0.0f;

    cout << "Enter total number of processes: ";
    cin >> n;

    process_struct ps[100];

    // Input
    for (int i = 0; i < n; i++) {

        cout << "Enter Arrival Time and Burst Time for Process "
             << i + 1 << ": ";

        cin >> ps[i].at >> ps[i].bt;

        ps[i].pid = i + 1;
    }

    // FCFS Scheduling
    for (int i = 0; i < n; i++) {

        if (i == 0) {
            ps[i].start_time = ps[i].at;
        }
        else {

            if (ps[i - 1].ct < ps[i].at) {
                ps[i].start_time = ps[i].at;
            }
            else {
                ps[i].start_time = ps[i - 1].ct;
            }
        }

        ps[i].ct = ps[i].start_time + ps[i].bt;

        ps[i].tat = ps[i].ct - ps[i].at;

        ps[i].wt = ps[i].tat - ps[i].bt;

        ps[i].rt = ps[i].start_time - ps[i].at;

        sum_tat += ps[i].tat;
        sum_wt += ps[i].wt;
    }

    // Average Calculations
    float atat = sum_tat / n;
    float awt = sum_wt / n;

    // Throughput Calculation
    float throughput = (float)n / (ps[n - 1].ct - ps[0].start_time);

    // Output
    cout << "\nProcess\tAT\tBT\tCT\tTAT\tWT\tRT\n";

    for (int i = 0; i < n; i++) {

        cout << "P" << ps[i].pid << "\t"
             << ps[i].at << "\t"
             << ps[i].bt << "\t"
             << ps[i].ct << "\t"
             << ps[i].tat << "\t"
             << ps[i].wt << "\t"
             << ps[i].rt << endl;
    }

    cout << "\nAverage Turnaround Time (ATAT): "
         << atat << endl;

    cout << "Average Waiting Time (AWT): "
         << awt << endl;

    cout << "Throughput: "
         << throughput
         << " processes/unit time" << endl;

    return 0;
}