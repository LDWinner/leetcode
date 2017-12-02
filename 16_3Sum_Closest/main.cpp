#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int result = 0;
        int diff = 0;
        size_t size = nums.size();
        sort(nums.begin(),nums.end());
        for(int i = 0;i < size;++i)
        {
            int j = i + 1;
            int k = size - 1;
            while(j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if(sum != target )
                {
                    if(diff == 0 || diff > abs(sum - target))
                    {
                        diff = abs(sum - target);
                        result = sum;
                    }
                    if(sum > target)
                        --k;
                    else
                        ++j;
                }
                else
                {
                    return sum;
                }

            }
        }
        return result;
    }
};

int main()
{
    Solution a;
    vector<int> v{0,1,2};
    a.threeSumClosest(v,3);
    return 0;
}
