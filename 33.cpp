#include <iostream>

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        size_t n = nums.size();
        if (n == 0)
            return -1;
        int index_left = 0, index_right = n - 1;
        int center = 0;
        int l, r;
        if (nums[0] > nums[n - 1])
        {
            while (index_right - index_left > 1)
            {
                int center = (index_right + index_left) / 2;
                if (nums[index_left] < nums[center])
                {
                    index_left = center;
                }

                else
                {
                    index_right = center;
                }
            }

            if (target < nums[0] && target > nums[n - 1])
                return -1;
            if (target == nums[0])
                return 0;
            if (target == nums[n - 1])
                return n - 1;
            if (target <= nums[0])
            {
                l = index_right;
                r = n - 1;
            }
            else if (target >= nums[n - 1])
            {
                l = 0;
                r = index_left;
            }
            else
            {
                return -1;
            }
        }
        else
        {
            l = 0;
            r = n - 1;
        }
        while (l <= r)
        {
            int mid = (r + l) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                l = mid + 1;
            else if (nums[mid] > target)
                r = mid - 1;
        }
        return -1;
    }
};