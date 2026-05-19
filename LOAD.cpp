#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// Global Variables 
char M[100][4];  // Memory (RAM)
char R[4];       // General Purpose Register --> Holds Data
char IR[4];      // Instruction Register --> Stores Instruction
int IC;          // Instruction Pointer --> points at next instrution address
bool C;          // Toggle rgister, used for comparision
char buffer[40]; // Temporary Storage

int m = 0;       // Memory pointer for LOAD
int SI ;         // Service interrupt flag 

// Function Declarations 
void INIT();
void LOAD(ifstream &infile, ofstream &outfile);
void STARTEXECUTION(ifstream &infile, ofstream &outfile);
void MOS(ifstream &infile, ofstream &outfile);
void READ(ifstream &infile);
void WRITE(ofstream &outfile);
void TERMINATE(ofstream &outfile);
void print_memory();

void INIT()
{
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            M[i][j] = '*';
        }
    }

    for (int i = 0; i < 4; i++)
    {
        R[i] = '*';
        IR[i] = '*';
    }

    IC = 0;
    C = 0;

    for (int i = 0; i < 10; i++)
    {
        if (i < 10)
        {
            cout << '0' << i << " ";
        }
        for (int j = 0; j < 4; j++)
        {
            cout << M[i][j];
        }
        cout << "\n";
    }
}

void LOAD()
{
    ifstream inputFile("input.txt");
    while (inputFile.getline(buffer, 40))
    {
        if (buffer[0] == '$' && buffer[1] == 'A' && buffer[2] == 'M' && buffer[3] == 'J')
        {
            cout << "\nInstruction is Control Card" << endl;
            INIT();
        }

        else if (buffer[0] != '$')
        {
            int k = 0;
            while (buffer[k] != '\0')
            {
                for (int j = 0; j < 4; j++)
                {
                    if (buffer[k] != '\0')
                    {
                        M[m][j] = buffer[k];
                        k++;
                    }
                    else
                    {
                        M[m][j] = '*';
                    }
                }
                m++;
            }

            cout<<"\nMemory after loading Program cards"<<endl;

            for (int i = 0; i < 10; i++)
            {
                if (i < 10)
                {
                    cout << '0' << i << " ";
                }
                for (int j = 0; j < 4; j++)
                {
                    cout << M[i][j];
                }
                cout << "\n";
            }
        }
    }
}

int main()
{

    ifstream inputFile("input.txt");
    string line;

    if (inputFile.is_open())
    {
        while (getline(inputFile, line))
        {
            cout << line << endl;
        }
        inputFile.close();
    }
    else
    {
        cout << "Unable to Open File";
    }

    LOAD();

    return 0;
}