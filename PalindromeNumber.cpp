#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
    if(x < 0)
        return false;
    int front = x;
    int back = x;
    int bit = 0;

    while (front != 0)
    {
        ++bit;
        front /= 10;
    }
    if(bit == 1)
        return true;
    for(int i = bit - 1;i >= bit / 2;i--)
    {
        front = (x / static_cast<int>(pow(10,i))) % 10;
        back  = (x % static_cast<int>(pow(10,bit - i))) / pow(10,bit - i - 1);
        if(front != back)
        return false;
    }
    return true;

    }
};

int main()
{
    Solution s;
    bool abc = s.isPalindrome(88888);
    cout <<  abc << endl;
    return 0;
}
