#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result {-1,-1};
        int size = nums.size();
        if(size == 0 || (size == 1 && nums[0] != target))
            return result;
        if(size == 1 && nums[0] == target)
        {
            result[0] = 0;
            result[1] = 0;
        }
            
        int left_low = 0;
        int left_high = 0;;
        int right_low = 0;
        int right_high = 0;
        int mid = (size - 1) / 2;
        if(nums[mid] < target)
        {
            left_low = right_low = mid + 1;
            left_high = right_high = size - 1;
        }
        else if(nums[mid] > target)
        {
            left_low = right_low = 0;
            left_high = right_high = mid - 1;
        }
        else
        {
            if (mid == 0)
            {
                if (nums[mid + 1] == target)
                {
                    result[0] = 0;
                    result[1] = 1;
                }
                else
                {
                    result[0] = 0;
                    result[1] = 0;
                }
                return result;
            }
            else
            {
                if (nums[mid - 1] != target && nums[mid + 1] == target)
                {
                    result[0] = mid;
                    left_low = left_high + 1;
                    right_low = mid + 1;
                    right_high = size - 1;
                }
                else if (nums[mid - 1] == target && nums[mid + 1] != target)
                {
                    result[1] = mid;
                    left_low = 0;
                    left_high = mid - 1;
                    right_low = right_high + 1;
                }
                else if(nums[mid - 1] == target && nums[mid + 1] == target)
                {
                    left_low = 0;
                    left_high = mid - 1;
                    right_low = mid + 1;
                    right_high = size - 1;
                }
                else
                {
                    result[0] = mid;
                    result[1] = mid;
                    return result;
                }
            }
        }
        
        while(left_low <= left_high)
        {
            int mid_left = (left_low + left_high) / 2;
            if(mid_left >= target)
            {
                left_high = mid_left;
            }
            else
            {
                left_low = mid_left;
            }
        }
    }
};