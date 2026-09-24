class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int r = 0;

        vector<int> alf(256, 0);
        int ans = 0;

        while (r < s.length()) {

            alf[s[r]]++;

            while (alf[s[r]] > 1) {
                alf[s[l]]--;
                l++;
            }

            ans = max(ans, r - l + 1);
            r++;
        }

        return ans;
    }
};