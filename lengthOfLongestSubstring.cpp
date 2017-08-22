class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int max_length = 0;
        list<char> window;
        max_length = window.size();
        list<char>::iterator it;
        for(int i = 0;i < s.size();++i)
        {
            if((it = find(window.begin(),window.end(),s[i])) != window.end())
            {
                window.erase(window.begin(),++it);
            }
            window.push_back(s[i]);
            if(max_length < window.size())
            {
                ++max_length;
            }
        }
        return max_length;
        
    }
};
