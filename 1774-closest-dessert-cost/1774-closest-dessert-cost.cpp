class Solution {
public:
//     TC = n*3^m (n is for iterating all elements of baseCost and we have 3 choice for each toppings)
    int target;
    int closest(int a,int b){ 
        if(a==0)
            return b;
        if(b==0)
            return a;
        if(abs(target-a)==abs(target-b))
            return a<b?a:b;
        return abs(target-a)<abs(target-b)?a:b;
    }
    
    int dfs(vector<int>&top,int i,int sum){
        if(i>=top.size())
            return sum;

        int takeSingle=dfs(top,i+1,sum+top[i]);
        int takeDouble=dfs(top,i+1,sum+(top[i]*2));
        int nottake=dfs(top,i+1,sum);
        sum=closest(takeSingle,closest(takeDouble,nottake));
        return sum;
    }
    
    int closestCost(vector<int>& base, vector<int>& top, int t) {
        target=t;//i made target global so that i don't need to pass it in any function
        int ans=0;
        for(int i=0;i<base.size();i++){
            ans = closest(dfs(top,0,base[i]),ans);
        } 
        return ans;
    }
};