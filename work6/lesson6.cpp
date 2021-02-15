#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

void exercise2();

int main()
{
    ofstream myFile;
    myFile.open("HomeWork.txt");

    myFile << "The C++ language was developed by Bjorn Stroustrup.\n";
    myFile.close();

    myFile.open("HomeWork2.txt");

    myFile << "Its popularity was due to the object-oriented nature of the language.\n";
    myFile.close();

    void (*ex2)();
    ex2=exercise2;
    (*ex2)();

    return 0;
}

void exercise2()
{
    char line[100];
    char *sentenses=new char[200];
    *sentenses=NULL;

    ifstream myfile;
    myfile.open("HomeWork.txt");
    while(myfile.getline(line, 100)){
        strcat(sentenses, line);
    }

    myfile.close();

    strcat(sentenses, "\n");

    myfile.open("HomeWork2.txt");
    while(myfile.getline(line, 100)){
        strcat(sentenses, line);
    }
    myfile.close();


    cout << sentenses;

    delete[] sentenses;
}
