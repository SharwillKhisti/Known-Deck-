#include <iostream>
using namespace std;

void FCFS(int arr[], int head, int size)
{
    int seek_count = 0; //
    int distance, cur_track;

    for (int i = 0; i < size; i++) {
        cur_track = arr[i];
        distance = abs(cur_track - head);
        seek_count += distance;
        head = cur_track;
    }

    cout << "Total number of seek operations = " << seek_count << endl;
    cout << "Seek Sequence is" << endl;

    for (int i = 0; i < size; i++) {
        cout << arr[i] << endl;
    }
}

int main()
{
    int request[] = {176, 79, 34, 60, 92, 11, 41, 114};
    int size = sizeof(request) / sizeof(request[0]);
    int head = 50;

    FCFS(request, head, size);

    return 0;
}



// PROCEDURE:
// You have a list of disk requests
// These are track numbers the disk needs to access
// Example: 176, 79, 34, 60, etc.
// You set a starting position (head)
// This is where the disk head is initially
// In your case: 50
// Start processing the first request
// Move the head from 50 → first request (176)
// Calculate how far it moved
// Add that distance to total movement
// Move to the next request
// Now head is at 176
// Move from 176 → 79
// Again calculate distance and add it
// Repeat this for all requests
// Each time:
// Go to the next request in order
// Measure movement
// Keep adding to total
// Keep updating head position
// After each move, the head stays at the latest track
// After finishing all requests
// The program:
// Prints total movement (seek operations)
// Prints the order in which requests were served