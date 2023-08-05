//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    //Complete this function
    void solve(string temp,string S,vector<string> &ans,int n, vector<int> &vis,int ind=0){
        if(ind==n){
           ans.push_back(temp);
           return;
        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                vis[i]=1;
                temp.push_back(S[i]);
                solve(temp,S,ans,n,vis,ind+1);
                temp.pop_back();
                vis[i]=0;
            }
        }
    }
    
    vector<string> permutation(string S)
    {
        //Your code here
        int n = S.size();
        vector<string> ans;
        vector<int> vis(n,0);
        string temp="";
        
        solve(temp,S,ans,n,vis);
        sort(ans.begin(),ans.end());
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends