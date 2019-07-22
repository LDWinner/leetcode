#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        if (nums.size() <= 1)
            return;
        for (int i = nums.size() - 1; i >= 1; --i)
        {
            if (nums[i - 1] < nums[i])
            {
                std::sort(nums.begin() + i,nums.end());
                vector<int>::iterator it = std::upper_bound(nums.begin() + i, nums.end(), nums[i - 1]);
                int tmp = *it;
                *it = nums[i - 1];
                nums[i - 1] = tmp;
                break;
            }
            else
            {
                if(i == 1)
                    std::sort(nums.begin(),nums.end());
            }
        }
    }
};