#ifndef STACK_H
#define STACK_H
#include <stack>
#include <stack>
using namespace std;

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
#endif
