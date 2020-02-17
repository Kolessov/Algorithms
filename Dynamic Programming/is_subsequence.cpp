class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.empty()) return true;
        if(t.empty()) return false;
        int ls = s.length();
        int lt = t.length();
        vector<int> dp(lt,0);
        for(int i=0; i<lt; i++){
            if(i>0 && dp[i]!=dp[i-1]){
                dp[i] = dp[i-1];
            }
            if(s[dp[i]]==t[i]){
                dp[i]++;
            }
        }
        return (dp[lt-1]==ls);
    }
};
