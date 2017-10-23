#include <string>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        bool p[1000][1000];
        memset(p,false,sizeof(p));

        for(int i = 0;i < s.length(); ++i) //init
        {
            p[i][i] = true;
            if(s[i] == s[i + 1] && i < s.length() - 1)
            {
                p[i][i + 1] = true;
            }
        }
        for(int i = 2; i < s.length(); ++i)
        {
            for(int j = 0; j < i - 1 ; ++j)
            {
                if(s[j] == s[i] && p[j + 1][i - 1])
                {
                    p[j][i] = true;
                }
                else
                {
                    p[j][i] = false;
                }
            }
        }
        int max_length = 0;
        int max_i = 0;
        int max_j = 0;
        for(int i = 0;i < s.length();++i)
            for(int j = 0;j < s.length(); ++j)
            {
                if(p[i][j])
                {
                    if(max_length < j - i)
                    {
                        max_length = j - i;
                        max_i = i;
                        max_j = j;
                    }
                }
            }
        return s.substr(max_i,max_j - max_i + 1);
    }
};

int main()
{
    Solution test;
    string s = test.longestPalindrome("abcba");
    cout << s << endl;
    return 0;
}
