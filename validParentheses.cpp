#include <iostream>
#include <string>
#include <map>
#include <stack>

using namespace std;
class Solution {
public:
    bool isValid(string s) {
        map<char,char> m;
        m[']'] = '[';
        m['}'] = '{';
        m[')'] = '(';
        stack<char> check_stack;
        string::iterator it;
        for(it = s.begin(); it != s.end(); ++it)
        {
            if(m.find(*it) == m.end())
            {
                check_stack.push(*it);
            }
            else
            {
                if(check_stack.empty() || m[*it] != check_stack.top())
                    return false;
                check_stack.pop();
            }
        }
        if(check_stack.empty())
            return true;
        return false;

    }
};
