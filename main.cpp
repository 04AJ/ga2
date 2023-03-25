#include <iostream>
#include <fstream>
#include <array>
#include <string>
#include <algorithm>
#include <list>
#include <stack>
#include "ArgumentManager.h"
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

bool doubleP(string a)
{
    stack<char> st;
    for (int i = 0; i < a.length(); i++)
    {
        // pushes if opening
        if (a.at(i) == ')' || a.at(i) == ']' || a.at(i) == '}')
        {
            if (st.top() == '(' || st.top() == '[' || st.top() == '{')
            {
                return true;
            }
            while (st.top() != '(' && st.top() != '[' && st.top() != '{')
            {
                st.pop();
            }
            st.pop();
        }
        else
        {
            st.push(a.at(i));
        }
    }
    return false;
}