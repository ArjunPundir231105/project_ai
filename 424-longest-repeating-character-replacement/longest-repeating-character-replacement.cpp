class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0;
        int r=0;
        int ans=0;
        int n = s.length();
        unordered_map<char,int>mp;
        int z=0;
        int cnt=0;
        while(r<n){
           cnt++;
           mp[s[r]]++;
           z=max(z,mp[s[r]]);
           while(cnt-z>k){
            mp[s[l]]--;
            cnt--;
            l++;
           }
           ans=max(ans,r-l+1);
           r++;
        }
        return ans;
    }
};