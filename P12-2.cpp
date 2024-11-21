#include <iostream> 
#include <string>
#include <fstream> 
#include <sstream>
#include <vector>
using namespace std;

//function prototypes
void pressEnterToContinue();
int readFromFile(string filename);

int main()
{
    string datafile;
    cout << "Lab 12 Intro to Text Files!\n";
    cout << "Please enter the file name: ";
    getline(cin, datafile);
    readFromFile(datafile);
    pressEnterToContinue();
}

void pressEnterToContinue()
{
    cout << "\nPress enter to continue... \n";
    cin.clear(); while (cin.get() != '\n') continue;
}

int readFromFile(string filename)
{
    ifstream inFile;
    int words = 0;
    int characters = 0;
    inFile.open(filename);

    if (inFile.fail())
    {
        cout << "Read error - Sorry!\n";
        return 0;
    }

    while (true)
    {
        string temp;
        if (inFile.fail())
            break;
        getline(inFile, temp);
        if (temp != "")
        {
            words++;
            for (int i = 0; i < temp.length(); i++)
            {
                if (isalnum(temp[i]))
                    characters++;
                if (temp[i] == ' ' && isalpha(temp[i + 1]))
                    words++;
            }
        }
    }
    inFile.close();
    cout << "Words: " << words << endl;
    cout << "Characters: " << characters;
}