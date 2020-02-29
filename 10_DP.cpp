#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int s_size = s.size();
        int p_size = p.size();
        vector<vector<bool>> DP (s_size + 1, vector<bool>(p_size + 1,false)); 
        DP[0][0] = true;
        for(int i = 0; i <= s_size ; ++i)
        {
            for(int j = 1; j <= p_size; ++j)
            {
                if(p[j - 1] == '*')
                {
                    DP[i][j] = DP[i][j - 2] || (i > 0 && DP[i - 1][j]);
                }
                else
                {
                    if(i > 0 && (p[j - 1] == s[i - 1] || p[j - 1] == '.'))
                        DP[i][j] = DP[i - 1][j - 1];
                }
            }
        }
        return DP[s_size][p_size];
        
    }
};