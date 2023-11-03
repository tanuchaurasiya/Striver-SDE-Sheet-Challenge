//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int longestUniqueSubsttr(string s){
        //code
        vector<int> index (26,-1);
        int start = 0;
        int ans = 0;
        
        for(int i=0 ; i<s.size() ; i++){
            
            if(index[s[i]-'a'] !=-1 && index[s[i]-'a'] >= start){
                
                start = index[s[i]-'a'] +1;
            }
            ans = max(ans,i-start+1);
            index[s[i] - 'a'] = i;
            // cout<<start << " "<<i <<endl;
            
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		Solution ob;
		cout<<ob.longestUniqueSubsttr(str)<<endl;
	}
	return 0;
}
// } Driver Code Ends