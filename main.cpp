#include <iostream>
#include <fstream>
#include <array>
#include <string>
#include <algorithm>
#include "ArgumentManager.h"
#include "stack.h"
using namespace std;

string decode(string input);

int main(int argc, char *argv[])
{
    ArgumentManager an(argc, argv);
    const string input = an.get("input");
    const string output = an.get("output");
    // ifstream inputfile(input);
    // ofstream outfile(output);

    ifstream inputfile("input1.txt");
    ofstream outfile("output.txt");

    return 0;
}