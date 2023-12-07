
class Solution {
public:
    bool check(int i, int j, string& s){
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    int minCut(string s) {
        vector<int>dp(s.size()+1, 0);
        for(int i=s.size()-1; i>=0; i--){
            int ans=INT_MAX;
            for(int j=i; j<s.size(); j++){
                if(check(i, j, s)){
                    int cnt=1+dp[j+1];
                    ans=min(ans, cnt);
                }
            }
            dp[i]=ans;
        }
        return dp[0]-1;
    }
};