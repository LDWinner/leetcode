#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        vector<int>::iterator begin = height.begin();
        vector<int>::iterator back = --height.end();
        int most = 0;
        x1 = begin - height.begin(); 
        while(begin != back)
        {
            x2 = back - height.begin();
            for(;begin != back;--back)
            {
                h = min(*begin,*back);
                area = h * (x2 - x1);
                if(most < area)
                    most = area;
            }
        }
    }
};

int main()
{
}
