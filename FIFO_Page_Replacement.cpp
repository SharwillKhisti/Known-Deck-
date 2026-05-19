#include <iostream>
using namespace std;

int main()
{
    int nf, np;

    int hit = 0, fault = 0;

    int pos = 0;

    cout << "Enter number of frames: ";
    cin >> nf;

    cout << "Enter number of pages: ";
    cin >> np;

    int F[100];
    int p[100];

    cout << "Enter page reference string: ";

    for (int i = 0; i < np; i++)
    {
        cin >> p[i];
    }

    // Initialize frames
    for (int i = 0; i < nf; i++)
    {
        F[i] = -1;
    }

    cout << "\nFIFO Page Replacement\n";

    for (int i = 0; i < np; i++)
    {
        int flag = 0;

        // Check Hit
        for (int j = 0; j < nf; j++)
        {
            if (F[j] == p[i])
            {
                hit++;

                flag = 1;

                break;
            }
        }

        // Only print when fault occurs
        if (flag == 0)
        {
            F[pos] = p[i];

            pos++;

            fault++;

            if (pos == nf)
            {
                pos = 0;
            }

            cout << "Page Fault for "
                 << p[i] << " -> ";

            // Print Frame Status
            for (int j = 0; j < nf; j++)
            {
                cout << F[j] << " ";
            }

            cout << endl;
        }
    }

    cout << "\nTotal Hits: "
         << hit << endl;

    cout << "Total Faults: "
         << fault << endl;

    return 0;
}