#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int length = nums.size();
        if(length == 0)
            return 0;
        int i = 0;
        int j = length - 1;
        while(i < j)
        {
            if(nums[i] == val)
            {
                if(nums[j] != val)
                    nums[i] = nums[j];
                --j;
            }
            else
            {
                ++i;
            }
        }
        if(nums[i] != val)
            ++i;
        nums.resize(i);
        return i;
        
    }
};

