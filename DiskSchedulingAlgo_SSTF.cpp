#include <iostream>
#include <cmath>
using namespace std;

void SSTF(int request[], int head, int size)
{
    int seek_count = 0;
    int visited[100] = {0};

    cout << "Seek Sequence is" << endl;

    for (int i = 0; i < size; i++)
    {
        int min_distance = 9999;
        int index = -1;

        for (int j = 0; j < size; j++)
        {
            if (!visited[j])
            {
                int distance = abs(request[j] - head);

                if (distance < min_distance)
                {
                    min_distance = distance;
                    index = j;
                }
            }
        }

        visited[index] = 1;
        seek_count += min_distance;
        head = request[index];

        cout << head << endl;
    }

    cout << "Total number of seek operations = " << seek_count << endl;
}

int main()
{
    int request[] = {176, 79, 34, 60, 92, 11, 41, 114};
    int size = sizeof(request) / sizeof(request[0]);
    int head = 50;

    SSTF(request, head, size);

    return 0;
}