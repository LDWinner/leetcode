#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> m;
        vector<int> result;
        map<int,int>::iterator it;
        for(size_t i = 0;i < nums.size();++i)
        {
            it = m.find(target - nums[i]);
            if(it == m.end())
            {
                m.insert(make_pair(nums[i],i));
            }
            else 
            {
                result.push_back(i);
                result.push_back(it->second);
                break;
            }
        }
        return result;
        
    }
};
