//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends



class Solution{
    public:
    //Complete this function
    void findAllPermutations(string s, string permut, vector<string> &ans) {
        if(s.length()==0) {
            ans.push_back(permut);
            return;
        }
        for(int i=0; i<s.length(); i++) {
            permut+=s[i];
            findAllPermutations((s.substr(0, i)+s.substr(i+1)), permut, ans);
            permut.pop_back();
        }        
    }
    vector<string> permutation(string &s)
    {
        vector<string> ans;
        findAllPermutations(s, "", ans);
        sort(ans.begin(), ans.end());
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