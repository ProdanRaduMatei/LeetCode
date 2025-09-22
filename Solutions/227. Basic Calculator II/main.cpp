#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution
{
public:
    int calculate(string s)
    {
        stack<int> st;
        long num = 0;
        char sign = '+';

        for (int i = 0; i < s.size(); i++)
        {
            char c = s[i];

            if (isdigit(c))
            {
                num = num * 10 + (c - '0');
            }

            if ((!isdigit(c) && c != ' ') || i == s.size() - 1)
            {
                if (sign == '+')
                {
                    st.push(num);
                }
                else if (sign == '-')
                {
                    st.push(-num);
                }
                else if (sign == '*')
                {
                    int top = st.top();
                    st.pop();
                    st.push(top * num);
                }
                else if (sign == '/')
                {
                    int top = st.top();
                    st.pop();
                    // truncate toward zero
                    st.push(top / num);
                }

                sign = c;
                num = 0;
            }
        }

        int result = 0;
        while (!st.empty())
        {
            result += st.top();
            st.pop();
        }
        return result;
    }
};