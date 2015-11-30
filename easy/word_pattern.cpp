class Solution {
public:
    bool wordPattern(string pattern, string str) {
		istringstream buf(str);
		istream_iterator <string> beg(buf),end;
		vector <string> sub_string (beg,end);
		if (sub_string.size()!=pattern.size()) return false;
		unordered_map <char,string> map1;
		unordered_map <string,char> map2;
		for (int i=0;i<pattern.size();i++)
		{
			if (map1.find(pattern[i])!=map1.end() && map1[pattern[i]]!=sub_string[i]) return false;
			else if (map2.find(sub_string[i])!=map2.end() && map2[sub_string[i]]!=pattern[i]) return false;
			else if (map1.find(pattern[i])==map1.end() && map2.find(sub_string[i])==map2.end())
			{
				map1[pattern[i]] = sub_string[i];
				map2[sub_string[i]] = pattern[i];
			}			
		}
		return true;
    }
};