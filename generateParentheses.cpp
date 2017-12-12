#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generateParenthesisDFS(n,n,"",result);
        return result;
    }

    void generateParenthesisDFS(int left,int right,string curr,vector<string> &result)
    {
        if(left > right)
            return;
        if(left == 0 && right == 0)
            result.push_back(curr);
        else 
        {
            if(left > 0)
                generateParenthesisDFS(left - 1,right,curr + '(',result);
            if(right > 0)
                generateParenthesisDFS(left,right - 1,curr + ')',result);
        }
    }
};
