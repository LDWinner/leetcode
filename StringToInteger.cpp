#include <iostream>
#include <sstream>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        string::iterator it;
        string tmp;
        bool finded = false;
        for(it = str.begin(); it != str.end(); it++)
        {
            if(*it >= '0' && *it <= '9' || *it == '-' || *it == '+')
            {
                finded = true;
                tmp.push_back(*it);
            }
            else if(finded)
            {
                break;
            }
            else if(tmp.empty() && *it != ' ')
                return 0;
        }
        istringstream iss(tmp);
        int result = 0;
        iss >> result;
        return result;
    }
};

int main()
{
    Solution s;
    int result = s.myAtoi("2147483648");
    cout << result << endl;
    return 0;
}
