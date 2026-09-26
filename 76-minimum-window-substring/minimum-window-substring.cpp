class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> mp;
        for(char c : t) mp[c]++;
        int r=0;
        int l=0;
        int start=0;
        int len=INT_MAX;
        int cnt=0;
        while(r<s.length()){
            if(mp.find(s[r]) != mp.end()){
              mp[s[r]]--;
              if(mp[s[r]]==0) cnt++;
            }
            while(cnt==mp.size()){
                if((r-l+1)<len) {
                    len = r-l+1;
                    start = l;
                }
                if(mp.find(s[l]) != mp.end()){
                   mp[s[l]]++;
                   if(mp[s[l]]>0) cnt--;
                } 
            l++;
            }

         r++;
        }
    if(len == INT_MAX) return "";    
    return s.substr(start,len);    
    }
};