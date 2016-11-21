/*
 Nameofapp.cpp

 description of app

 Jose Roberto Adame
 Date
 version 1.0
 */
#include <iostream>
#include <fstream>
using namespace std;
const int iMax = 100000;
/*
 NameOfFunction

 Description of function

 Parameters:
 NameOfVariable:Description
 Returns:
 NameOfVariable:Description
 */
string wordtext(string iFile)
{
    int iRandNumber;
    srand(time(NULL));
    string iWord;
    string line;
    int iCounter = 0;
    string iArrWord[iMax];
    ifstream myfile (iFile);
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            iArrWord[iCounter] = line;
            iCounter++;
        }
        myfile.close();

        for (int iX = 0; iX<iCounter; iX++) {
        }
        iRandNumber = rand()%iCounter;
        iWord = iArrWord[iRandNumber];
    }
    return iWord;
}

void Drawings(int iLives)
{

    switch (iLives) {
        case 60:
            cout << "|----------|" << endl;
            cout << "|          O" << endl;
            cout << "|         /|\\ " << endl;
            cout << "|         / \\ " << endl;
            cout << "               " << endl;
            cout << "⌇⌇⌇⌇⌇⌇⌇⌇⌇" << endl;

            break;
        case 1:
            cout << "|----------|" << endl;
            cout << "|          O" << endl;
            cout << "|         /|\\ " << endl;
            cout << "|         /  " << endl;
            cout << "               " << endl;
            cout << "⌇⌇⌇⌇⌇⌇⌇⌇⌇" << endl;

            break;
        case 2:
            cout << "|----------|" << endl;
            cout << "|          O" << endl;
            cout << "|         /| " << endl;
            cout << "|         /  " << endl;
            cout << "               " << endl;
            cout << "⌇⌇⌇⌇⌇⌇⌇⌇⌇" << endl;

            break;
        case 3:
        cout << "|----------|" << endl;
        cout << "|          O" << endl;
        cout << "|         /| " << endl;
        cout << "|            " << endl;
            cout << "               " << endl;
            cout << "⌇⌇⌇⌇⌇⌇⌇⌇⌇" << endl;

            break;

        case 4:
        cout << "|----------|" << endl;
        cout << "|          O" << endl;
        cout << "|          | " << endl;
        cout << "|            " << endl;
        cout << "               " << endl;
        cout << "⌇⌇⌇⌇⌇⌇⌇⌇⌇" << endl;
            break;
        case 5:
        cout << "|----------|" << endl;
        cout << "|          O" << endl;
        cout << "|            " << endl;
        cout << "|            " << endl;
        cout << "               " << endl;
        cout << "⌇⌇⌇⌇⌇⌇⌇⌇⌇" << endl;

            break;

        case 6:
        cout << "|----------|" << endl;
        cout << "|           " << endl;
        cout << "|            " << endl;
        cout << "|            " << endl;
        cout << "               " << endl;
        cout << "⌇⌇⌇⌇⌇⌇⌇⌇⌇" << endl;

            break;

        default:
            break;
    }
}

int DisplayGame(string iWord)
{
    int iLives = 6;
    int iLenght;
    int iHits = 0;
    int iCounter = 0;
    bool bTest = false;
    string iArrCounter[iMax];
    string iTry;
    string iArrWord[iMax];
    iLenght = iWord.length();
    string iArrString[100];
    bool bNeg = false;
    for(int iX = 0; iX < iLenght; iX++) // to give the first all of asterisks
    {
        iArrString[iX] = "*";
    }

    for (int iY = 0; iY < iLenght; iY++)
    {
        iArrWord[iY] = iWord[iY];
    }

    for(int iX = 0; iX < iLenght; iX++)
    {
        cout << iArrString[iX];
    }
    cout << endl;

    while (iLives > 0 && iHits < iLenght && iHits != -1)// or ihits = ilenght
    {
        bTest = false;
        bNeg = false;
        cout << endl;
        cout << "Lives: " << iLives << endl;
        Drawings(iLives);
        for(int iX = 0; iX < iLenght; iX++)
        {
            cout << iArrString[iX];
        }
        cout << endl;
        cout << "give me a letter" << endl;
        cin >> iTry;
        cout << endl;
        cout << endl;
        iArrCounter[iCounter] = iTry;
        for (int iH = 0; iH < iCounter; iH++)
        {
            if (iTry == iArrCounter[iH])
            {
                bTest = true;
            }
        }
        iCounter++;
        cout << "letters used: ";
        for (int iG = 0; iG<iCounter; iG++)
        {
            cout << iArrCounter[iG] << " ";
        }
        if (bTest == false)
        {
        if (iTry == iWord)
        {
            iHits = -1;
                    }
        if (iHits != -1)
        {
            for(int iX = 0; iX < iLenght; iX++)
            {
                if (iTry == iArrWord[iX])
                {
                    iArrString[iX] = iTry;
                    iHits++;
                    bNeg = true;
                }

            }

            if (bNeg == false)
            {
                iLives--;
            }



        } else if (iHits == -1)
        {
            for (int iZ = 0; iZ < iLenght; iZ++)
            {
                cout << iWord[iZ];
            }
            cout << endl;
            cout << "congratulations you got " << iWord << " right" << endl;
        }
    } else
    {
        cout << endl;
        cout << "please enter a letter that you have not used" << endl;
    }
    }
    cout << endl;
cout << "the word was: " << iWord << endl;


    return iLives;

}

/*
 Main Function

 Description of main value

 Parameters:
 none
 Returns:
 an integer value with the error number (0 = none)
 */
int main()
{
    string iWord;
    int iScore = 0;
    string sContinue;
    string iFile;
    string iWordAns;
    int iWin = 0;
    int iLoose = 0;
    double dTimes = 0;
    double dWinratio;
    {
    cout << "give the name of the file to use like a dictionary, end it on .txt" << endl;
    cin >> iFile;
    cout << "is " << iFile << " your file? (y/N)" << endl;
    cin >> iWordAns;
    } while (iWordAns != "y" && iWordAns != "Y");

    do
    {
        iWord = wordtext(iFile);
        iScore = DisplayGame(iWord);
        if (iScore > 0)
        {
            iWin++;
        } else {
            iLoose++;
        }
        dTimes++;
        cout << "you have won: " << iWin << " times." << endl;
        cout << "you have lost " << iLoose << " times." << endl;
        dWinratio = iWin/dTimes;
        cout << "your win ratio is: " << dWinratio << endl;
        cout << "do you want to continue? (Y/N)" << endl;
        cin >> sContinue;
    } while (sContinue != "N" && sContinue != "n" );
    return 0;
}
