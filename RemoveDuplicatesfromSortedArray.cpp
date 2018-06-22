#include <iostream>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int length = nums.size();
        int i,j;
        if(length == 1)
            return 1;
        if(length == 0)
            return 0;
        i = 0;
        j = 0;
        while(j < length)
        {
            if(nums[i] == nums[j])
            {
                ++j;
            }
            else
            {
                ++i;
                nums[i] = nums[j];
            }
        }
        nums.resize(i + 1);
        return i + 1;
    }
};

int main()
{
}
