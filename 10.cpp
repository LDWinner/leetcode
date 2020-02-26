#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        if(p.empty()) return s.empty();

        if(p.size() == 1)
        {
            return (s.size() == 1 && (s[0] == p[0] || p[0] == '.'));
        }

        if(p[1] != '*')
        {
            if(s.empty()) return false;
            if(p[0] == s[0] || p[0] == '.') 
                return isMatch(s.substr(1),p.substr(1));
            return false;
        }

        if (!s.empty() && (p[0] == s[0] || p[0] == '.'))
        {
            return isMatch(s,p.substr(2)) || isMatch(s.substr(1),p);
        }

        return isMatch(s,p.substr(2));

    }
};