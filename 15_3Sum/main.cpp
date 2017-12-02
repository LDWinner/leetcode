#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        size_t size = nums.size();
        if(size < 3)
            return result;
        int flag = 0;
        size_t ignore_size = 0;
        sort(nums.begin(),nums.end());
        for(int i = 0;i < size;++i)
        {
            if(nums[i] == flag)
            {
                ++ignore_size;
                continue;
            }
            flag = nums[i];
            int j = i + 1;
            int k = size - 1;
            while(j < k)
            {
                if(nums[j] + nums[k] == -flag)
                {
                    result.push_back({flag,nums[j],nums[k]});
                    ++j;
                    --k;
                    while(j < k)
                    {
                        if(nums[j] == nums[j - 1])
                            ++j;
                        if(nums[k] == nums[k + 1])
                            --k;
                        if(nums[j] != nums[j - 1] && nums[k] != nums[k + 1])
                            break;
                    }
                }
                else if(nums[j] + nums[k] < -flag)
                {
                    ++j;
                }
                else
                {
                    --k;
                }

            }
        }
        if(ignore_size == size && nums[0] == 0)
            result.push_back({0,0,0});
        return result;
    }
};

int main()
{
    Solution a;
    vector<int> v({-1,0,1,2,-1,-4});
    a.threeSum(v);
    cout << "Hello World!" << endl;
    return 0;
}
