#include <iostream>
#include <vector>

using namespace std;
 
class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        vector<int> dp(n,0);
        int max_length = 0;
        int length = 0;
        for(int i = 1; i < s.size(); ++i)
        {
            if(s[i] == ')')
            {
                int index = i - 1 - dp[i - 1];
                if(index >= 0)
                {
                    if(s[index] == '(')
                    {
                        if(index == 0)
                            dp[i] =  dp[i - 1] + 2;
                        else
                            dp[i] = i - index + 1 + dp[index - 1];
                    }
                    length = dp[i];
                }
            }
            if(length > max_length)
                max_length = length;
        }
        return max_length;
    }
};
