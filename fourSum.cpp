#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    public:
        vector<vector<int>> fourSum(vector<int>& nums, int target) {
            vector<vector<int>> result;
            if(nums.size() < 4)
                return result;
            sort(nums.begin(),nums.end());
            for(size_t i = 0; i < nums.size() - 3;++i)
            {
                if(nums[i] == nums[i - 1] && i > 0)
                    continue;
                for(size_t j = i + 1; j < nums.size() - 2;++j)
                {
                    if(nums[j] == nums[j - 1] && j > i + 1) 
                        continue;
                    size_t k = j + 1;
                    size_t m = nums.size() - 1;
                    while(k < m)
                    {
                        if(nums[k] == nums[k - 1] && k > j + 1)
                        {
                            ++k;
                            continue;
                        }
                        if(nums[m] == nums[m + 1] && m < nums.size() - 1)
                        {
                            --m;
                            continue;
                        }
                        int r = nums[i] + nums[j] + nums[k] + nums[m]; 
                        if(r > target)
                            --m;
                        else if(r < target)
                            ++k;
                        else
                        {
                            vector<int> tmp{ nums[i],nums[j],nums[k],nums[m] };
                            result.push_back(tmp);
                            --m;
                            ++k;
                        }
                    }
                }
            }
            return result;

        }
};
