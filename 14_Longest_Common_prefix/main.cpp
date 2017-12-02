#include <iostream>
#include <vector>


using namespace std;

typedef vector<string>::iterator VectorStringIterator;
typedef string::iterator StringIterator;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        VectorStringIterator it;
        StringIterator sit;
        string commonPrefix;
        if(strs.size() == 0)
        {
            return commonPrefix;
        }
        string &s = *(strs.begin());
        for(sit = s.begin();sit != s.end();++sit)
        {
            commonPrefix.push_back(*sit);
            for(it = strs.begin();it != strs.end();++it)
            {
                if(it->find(commonPrefix) != 0)
                {
                    commonPrefix.pop_back();
                    return commonPrefix;
                }

            }
        }
        return commonPrefix;
    }
};

int main()
{
    Solution a;
    vector<string> s = { "aa" , "ab"};
    cout << a.longestCommonPrefix(s);
    return 0;
}
