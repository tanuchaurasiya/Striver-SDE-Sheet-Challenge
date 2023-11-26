class Solution {
public:
    int help(int i, int prev, int n, vector<string> &words, vector<int> &sizes, vector<vector<int>> &dp){
        if(i>n) return 0;
        
        int take=0;
        int nottake=0;
        
        if(dp[i][prev]!=-1) return dp[i][prev];
        if(prev==0 || sizes[prev-1]+1 == sizes[i-1]){
            if(prev==0) 
                take = 1+help(i+1, i, n, words, sizes,dp);
            else{
                int x=0;
                int y=0;
                bool flag=false;
                while(x<sizes[prev-1] && words[prev-1][x] == words[i-1][y]){
                    x++;
                    y++;
                }
                if(x==sizes[prev-1]) 
                    flag=true;
                else{
                    y++; 
                    while(x<sizes[prev-1] && words[prev-1][x] == words[i-1][y]){
                        x++;
                        y++;
                    } 
                    if(x==sizes[prev-1]) flag=true;
                }
                
                if(flag) 
                    take = 1+help(i+1, i, n, words, sizes,dp);
            }
        }
        
        nottake = help(i+1, prev, n, words, sizes,dp);
        dp[i][prev] =  max(take,nottake);
        return dp[i][prev];
    }
    
    static bool comp(string s1, string s2){
        if(s1.length()<s2.length()) return true;
        return false;
    }
    int longestStrChain(vector<string>& words) { 
        sort(words.begin(), words.end(), comp); 
        int n = words.size();
        vector<int> sizes(n);
        for(int i=0;i<n;i++) 
            sizes[i] = words[i].length();
        vector<vector<int>> dp;
        for(int i=0;i<n+1;i++){
            vector<int> v;
            for(int j=0;j<n+1;j++) 
                v.push_back(-1);
            dp.push_back(v);
        }
        return help(1,0,words.size(), words,sizes, dp);
    }
};