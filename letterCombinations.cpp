#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
	    vector<string> result;

	    string table[] = {"","","abc","def",
		                 "ghi","jkl","mno",
				 "pqrs","tuv","wxyz"};
        letterCombinationsDFS(digits,"",0,table,result);

	    return result;
	    
    }

    void letterCombinationsDFS(string digits,string curr,size_t level,string table[],vector<string> &result)
    {
        if(level == digits.size())
        {
            if(curr != "")
                result.push_back(curr);
            return;
        }
        string data = table[digits[level] - '0'];
        for(size_t i = 0;i < data.size();++i)
        {
            curr.push_back(data[i]);
            letterCombinationsDFS(digits,curr,level + 1,table,result);
        }
    }
};

int main()
{
    string test = "";
    vector<string> result;
    Solution *solution = new Solution();
    result = solution->letterCombinations(test);
    vector<string>::iterator it;
    for(it = result.begin(); it != result.end();++it )
    {
        cout << "[" << *it << "] ";
    }
}
