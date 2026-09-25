class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp;
        int l = 0;
        int r = 0;
        int n = s.length();
        if(n==0) return 0;
        int ans=-1;
        while(r<n){
            if(mp.find(s[r])!=mp.end())  l=max(l,mp[s[r]]+1);  
            mp[s[r]]=r;
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};