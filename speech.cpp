#include <string>
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;
#include "functions.cpp"


int main()
{
    //variables
    ifstream f;
    string input;

    f.open("input.txt"); //open file

    input = getFileLine(f); //gets first line of text file
    evalSentence(input);
        
}



