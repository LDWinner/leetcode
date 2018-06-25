#include <iostream>
#include <limits>

using namespace std;
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor == -1 && dividend == (numeric_limits<int>::min)())
            return (numeric_limits<int>::max)();
        if(divisor == 1)
            return dividend;
        unsigned long long div = abs((long long)dividend);
        unsigned long long dir = abs((long long)divisor);

        unsigned long long tmp = dir;
        long long result = 0;

        while(tmp <= div)
        {
            ++result;
            tmp+=dir;
        }

        if((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0))
            return 0-result;
        else
            return result;
    }
};

int main()
{
    Solution s;
    cout << s.divide(2147483647,2) << endl;;
    return 0;
}
