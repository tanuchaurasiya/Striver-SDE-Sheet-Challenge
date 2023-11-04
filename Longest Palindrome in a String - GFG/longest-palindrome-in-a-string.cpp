//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    string longestPalin (string s) {
        int res=0;
        string op;
        int n=s.length();
        
        for(int i=0;i<n;i++){
            int l = i;
            int r = i;
            string x ="";
            while(l>=0 && r<=n-1 && s[l]==s[r]){  
                if (res<r-l+1){
                    res=r-l+1; 
                    for(int j=l;j<=r;j++)
                       x+=s[j];
                    op = x;  
                    x="";
                } 
            
                l-=1;
                r+=1;
            } 
            
            l = i;
            r = i+1;
           
            
            while(l>=0 && r<=n-1 && s[l]==s[r]){
                if (res<r-l+1){
                    res=r-l+1; 
                    for(int j=l;j<=r;j++)
                       x+=s[j];
                    op = x;
                    x="";
                } 
                l-=1;
                r+=1;
            } 
            
        }
        return op;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends