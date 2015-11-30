class Solution {
public:
    bool isIsomorphic(string s, string t) {
		if (s.size()!=t.size()) return false;
		unordered_map <char,char> map1;
		unordered_map <char,char> map2;
		for (int i=0;i<pattern.size();i++)
		{
			if (map1.find(s[i])!=map1.end() && map1[s[i]]!=t[i]) return false;
			else if (map2.find(t[i])!=map2.end() && map1[t[i]]!=s[i]) return false;
			else if (map1.find(s[i])==map1.end() && map2.find(t[i])==map2.end())
			{
				map1[s[i]] = t[i];
				map2[t[i]] = s[i];
			}			
		}
		return true;        
    }
};