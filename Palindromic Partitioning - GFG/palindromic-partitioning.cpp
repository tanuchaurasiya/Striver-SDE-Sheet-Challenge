//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public: 
vector<int> dp;
    bool isPalindrome(string s, int start, int end){
        while(start<=end){
            if(s[start]!=s[end]) return false;
            start++; 
            end--;
        }
        return true;
    }
    int help(int idx, int n, string s){ 
        if(idx==n) return 0; 
        if(dp[idx]!=-1) return dp[idx];
        int ans=INT_MAX;
        for(int i=idx;i<n;i++){
            if(isPalindrome(s, idx, i)){
                // cout<<"idx= "<<idx<<" i = "<<i<<endl;
                ans=min(ans, 1+ help(i+1,n,s));
            }
            
        }
        dp[idx] = ans;
        return dp[idx];
        
    }
    int palindromicPartition(string s) { 
        int n = s.length();
        dp.resize(n,-1);
        return help(0, n, s)-1;
        
    }
    
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends