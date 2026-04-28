#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    stack<char> st;
    for (int i = 0 ; i < s.length() ; i++)
    {
        if (s[i] == '(')
            st.push('(');
        else 
        {
            if (st.empty())
                return false;
            st.pop();
        }
    }
    return st.empty();
}