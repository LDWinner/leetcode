#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        int max_area = 0;
        while(i < j)
        {
            int area = min(height[i],height[j]) * (j - i);
            max_area = max(max_area,area);
            if(height[i] < height[j])
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return max_area;
    }
};

int main()
{
    Solution abc;
    vector<int> tmp{1,1};
    cout << abc.maxArea(tmp) << endl;
    return 0;
}
