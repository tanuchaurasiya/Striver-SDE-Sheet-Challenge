class Solution {
public:
    int solve(int a,int b,vector<int> &dp){
        // cout<<a<<" "<<b<<endl;
        if(a<b)return b-a;
        if(a==b)return 0;
        if(dp[a]!=1e6)return dp[a];
        int p = 1e6,q=1e6,s = 1e6;
        if(!(a%11))
            p = 1+solve(a/11,b,dp);
        else
        p = min(a%11+solve(a/11,b,dp)+1,(11-a%11)+solve(a/11 +1 ,b,dp)+1);
        
        if(!(a%5))
            q = 1+solve(a/5,b,dp);
        else
        q = min(a%5+solve(a/5,b,dp)+1,(5-a%5)+solve(a/5 +1 ,b,dp)+1);
           
        s = 1+solve(a-1,b,dp);
        return dp[a] = min({p,q,s});
    }
    int minimumOperationsToMakeEqual(int x, int y) {
        // if(y>=x){
        //     return y-x;
        // }
        vector<int> ans(1e4+100,1e6);
        return solve(x,y,ans);
    }
};