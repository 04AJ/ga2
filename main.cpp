#include <iostream>
#include <fstream>
#include <array>
#include <string>
#include <algorithm>
#include <list>
#include <stack>
#include "ArgumentManager.h"
using namespace std;

bool orderP(string s);
bool validP(string a);
bool doubleP(string a);
int priority(char c);
void print(list<string> valid, list<string> invalid, ofstream &output);

int main(int argc, char *argv[])
{
    ArgumentManager an(argc, argv);
    const string input = an.get("input");
    const string output = an.get("output");
    ifstream inputfile(input);
    ofstream outfile(output);

    // Delete when done
    // ifstream inputfile("input3.txt");
    // ofstream outfile("output.txt");

    string tmpstr = "";
    bool isValid = false;
    list<string> valid = {};
    list<string> invalid = {};

    while (getline(inputfile, tmpstr))
    {
        // cout << tmpstr << "---> Order:" << orderP(tmpstr) << " Valid:" << validP(tmpstr) << " Double:" << doubleP(tmpstr) << endl;
        if (orderP(tmpstr) && validP(tmpstr) && !doubleP(tmpstr))
            valid.push_back(tmpstr);
        else
            invalid.push_back(tmpstr);
    }

    print(valid, invalid, outfile);

    inputfile.close();
    outfile.close();
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

void print(list<string> valid, list<string> invalid, ofstream &output)
{
    // write to output file
    if (!valid.empty())
    {
        output << "Valid" << endl;
        for (string node : valid)
            output << node << endl;
    }
    if (!invalid.empty())
    {
        output << "Invalid" << endl;
        for (string node : invalid)
            output << node << endl;
    }
}

int priority(char c)
{
    int num = 0;
    switch (c)
    {
    case '{':
        num = 3;
        break;
    case '[':
        num = 2;
        break;
    case '(':
        num = 1;
        break;
    }

    return num;
}