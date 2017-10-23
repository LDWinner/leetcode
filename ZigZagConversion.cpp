#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> str;
        str.reserve(numRows);
        for(int i = 0;i < numRows; i++)
        {
            str.push_back(string());
        }
        if(s.size() <= 2 || numRows == 1)
            return s;
        int row = 0;
        int flag = 1;
        for(int i = 0; i < s.size(); ++i)
        {
            if(row == numRows - 1 && flag == 1)
            {
                flag = -1;
            }
            else if(row == 0 && flag == -1)
            {
                flag = 1;
            }

            str[row].push_back(s[i]);

            row += flag;

        }
        string result;
        for(vector<string>::iterator it = str.begin();it != str.end();it++)
        {
            result.append(*it);
        }
        return result;
    }
};

int main()
{
    string abc("ABC");
    Solution solution;
    string s = solution.convert(abc,1);
    cout << s << endl;
    return 0;
}
