#include <iostream>
#include <fstream>
using namespace std;

char M[100][4];
char R[4], IR[4];

int IC, C, SI, m;
char buffer[41];


ifstream fin;
ofstream fout;

int ADDRESS()
{
    return (IR[2] - '0') * 10 + (IR[3] - '0');
}

void DISPLAY_MEMORY()
{
    for (int i = 0; i < 100; i++)
    {
        cout << i << " : ";

        for (int j = 0; j < 4; j++)
            cout << M[i][j];

        cout << endl;
    }
}

void INIT()
{
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 4; j++)
            M[i][j] = '*';
    }

    for (int i = 0; i < 4; i++)
    {
        R[i] = '*';
        IR[i] = '*';
    }

    IC = 0;
    C = 0;
    m = 0;

    cout << "\nMemory after initialization:\n";
    DISPLAY_MEMORY();
}

void TERMINATE()
{
    cout << "\nMemory after execution:\n";
    DISPLAY_MEMORY();

    cout << "\nProgram Executed Successfully.\n";
}

void READ()
{
    fin.getline(buffer, 41);

    int loc = ADDRESS();
    int k = 0;

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (buffer[k])
                M[loc][j] = buffer[k++];
            else
                M[loc][j] = '*';
        }

        loc++;
    }
}

void WRITE()
{
    int loc = ADDRESS();

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (M[loc][j] != '*')
                fout << M[loc][j];
        }

        loc++;
    }

    fout << endl;
}

void MOS()
{
    if (SI == 1)
        READ();

    else if (SI == 2)
        WRITE();

    else
        TERMINATE();
}

void EXECUTE_USER_PROGRAM()
{
    while (true)
    {
        for (int i = 0; i < 4; i++)
            IR[i] = M[IC][i];

        IC++;

        switch (IR[0])
        {
        case 'G':
            SI = 1;
            MOS();
            break;

        case 'P':
            SI = 2;
            MOS();
            break;

        case 'H':
            SI = 3;
            MOS();
            return;

        case 'L':
        {
            int loc = ADDRESS();

            for (int i = 0; i < 4; i++)
                R[i] = M[loc][i];

            break;
        }

        case 'S':
        {
            int loc = ADDRESS();

            for (int i = 0; i < 4; i++)
                M[loc][i] = R[i];

            break;
        }

        case 'C':
        {
            C = 1;

            int loc = ADDRESS();

            for (int i = 0; i < 4; i++)
            {
                if (R[i] != M[loc][i])
                {
                    C = 0;
                    break;
                }
            }

            break;
        }

        case 'B':
            if (C == 1)
                IC = ADDRESS();
            break;

        case 'N':
        {
            int loc = ADDRESS();

            for (int i = 0; i < 4; i++)
                R[i] = (R[i] == '1' && M[loc][i] == '1') ? '1' : '0';

            break;
        }

        case 'O':
        {
            int loc = ADDRESS();

            for (int i = 0; i < 4; i++)
                R[i] = (R[i] == '1' || M[loc][i] == '1') ? '1' : '0';

            break;
        }

        case 'X':
        {
            int loc = ADDRESS();

            for (int i = 0; i < 4; i++)
                R[i] = (R[i] != M[loc][i]) ? '1' : '0';

            break;
        }

        default:
            break;
        }
    }
}

void STARTEXECUTION()
{
    IC = 0;
    EXECUTE_USER_PROGRAM();
}

void LOAD()
{
    fin.open("input1.txt");
    fout.open("output1.txt");

    m = 0;

    while (fin.getline(buffer, 41))
    {
        if (buffer[0] == '$')
        {
            switch (buffer[1])
            {
            case 'A':
                INIT();
                break;

            case 'D':
                cout << "\nMemory after loading program card:\n";
                DISPLAY_MEMORY();

                STARTEXECUTION();
                break;

            case 'E':
                fout << endl << endl;
                break;
            }
        }
        else
        {
            int k = 0;

            while (buffer[k])
            {
                for (int j = 0; j < 4; j++)
                {
                    if (buffer[k])
                        M[m][j] = buffer[k++];
                    else
                        M[m][j] = '*';
                }

                m++;
            }
        }
    }

    fin.close();
    fout.close();
}

int main()
{
    LOAD();
    return 0;
}