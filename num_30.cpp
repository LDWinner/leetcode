#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
	vector<int> findSubstring(string s, vector<string> &words)
	{
		vector<int> indices;
		int string_length;

		unordered_map<string,int> march;
		unordered_map<string,int> sub;

		if(s.empty() || words.empty())
			return indices;

		string_length = words[0].size();

		for (int i = 0; i < words.size(); ++i)
		{
			if(sub.find(words[i]) != sub.end())
			{
				sub[words[i]]++;
			}
			else
			{
				sub[words[i]] = 1;
			}
		}
		
		int end_index = s.size() - words.size() * string_length; 
		for (int i = 0; i < string_length; ++i)
		{
			for(int index = i; index <= end_index; index += string_length)
			{
				march.clear();
				for(int j = 0; j < words.size(); ++j)
				{
					string substr = s.substr(index + j * string_length,string_length);
					if(sub.find(substr) == sub.end())
						break;
					if(march.find(substr) == march.end())
					{
						march[substr] = 1;
					}
					else
					{
						march[substr]++; 
					}
				}
				bool is_index = true;
				for(auto &it : sub)
				{
					unordered_map<string, int>::iterator march_it = march.find(it.first);
					if (march_it == march.end() || it.second != march_it->second)
					{
						is_index = false;
						break;
					}
				}
				if(is_index)
				{
					indices.push_back(index);
				}
			}
		}
		return indices;

	}
};
