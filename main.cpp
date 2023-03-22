#include <iostream>
#include <fstream>
#include <array>
#include <string>
#include <algorithm>
#include <list>
#include "ArgumentManager.h"
#include "stack.h"
using namespace std;

bool orderP(string s);
bool validP(string a);
bool doubleP(string a);
void print(list<string> valid, list<string> invalid, ofstream &output);


int main(int argc, char *argv[])
{
    ArgumentManager an(argc, argv);
    const string input = an.get("input");
    const string output = an.get("output");
    // ifstream inputfile(input);
    // ofstream outfile(output);

    // Delete when done
    ifstream inputfile("input1.txt");
    ofstream outfile("output.txt");

    string tmpstr = "";
    bool isValid = false;
    list<string> valid = {};
    list<string> invalid = {};

    while (getline(inputfile, tmpstr)){
        if (orderP(tmpstr) && validP(tmpstr) && doubleP(tmpstr))
            valid.push_back(tmpstr);
        else
            invalid.push_back(tmpstr);
    }

    print(valid, invalid, outfile);

    inputfile.close();
    outfile.close();
    return 0;
}


bool orderP(string s)
{
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        if (s.at(i) == '{' || s.at(i) == '[' || s.at(i) == '(')
        {
            if (!st.empty() && (priority(st.top()) < priority(s.at(i))))
                return false;
            st.push(s.at(i));
        }
    }

    return true;
}


bool validP(string a)
{
    stack<char> str;
    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] == '(' || a[i] == '[' || a[i] == '{')
        {
            str.push(a[i]);
        }
        else if (a[i] == ')')
        {
            if (str.empty() || str.top() != '(')
            {
                return false;
            }
            str.pop();
        }
        else if (a[i] == ']')
        {
            if (str.empty() || str.top() != '[')
            {
                return false;
            }
            str.pop();
        }
        else if (a[i] == '}')
        {
            if (str.empty() || str.top() != '{')
            {
                return false;
            }
            str.pop();
        }
    }
    return str.empty();
}


bool doubleP(string a){
    // TODO
    return true;
}


void print(list<string> valid, list<string> invalid, ofstream &output){
    // write to output file
    output << "Valid" << endl;
    for (string node : valid)
        output << node << endl;
    output << "Invalid" << endl;
    for(string node : invalid)
        output << node << endl;

    // print
    cout << "Valid" << endl;
    for (string node : valid)
        cout << node << endl;
    cout << "Invalid" << endl;
    for(string node : invalid)
        cout << node << endl;
}