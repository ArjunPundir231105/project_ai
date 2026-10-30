class Solution {
public:
    string reverseWords(string s) {
        int j = s.length()-1;
        string ans;
        while(j>=0){
            while(j>=0 && s[j] == ' ') j--;
            if(j<0) break;
            int i = j;
            while(j>=0 && s[j]!=' ') j--;
            string nw = s.substr(j+1,i-j);
            if(!ans.empty()) ans += ' ';
            ans+=nw; 
                
        }
        return ans;
    }
};