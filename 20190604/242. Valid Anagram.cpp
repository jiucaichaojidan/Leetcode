class Solution {
public:
    bool isAnagram(string s, string t) {
        if (t.size() != s.size()) return false;
        
        map<char, int> mymap;
        for(int i = 0; i < s.size(); i++)
        {
            
            if(mymap.find(s[i]) == mymap.end())
                mymap[s[i]] = 0;
            mymap[s[i]] += 1;
        }
        for (int i = 0; i < t.size(); i++)
        {
            if (mymap.find(t[i]) == mymap.end())
                return false;
            mymap[t[i]] -= 1;
            if (mymap[t[i]] == 0)
                mymap.erase(mymap.find(t[i]));                
        }
        if (mymap.size() == 0)
            return true;
        else
            return false;

        // version2
        // int cnt[26] = {0};
        // for(auto ch : s) cnt[ch - 'a'] ++;
        // for(auto ch : t) cnt[ch - 'a'] --;
        // for(auto num : cnt) if(num) return false;
        // return true;    

        
    }
};