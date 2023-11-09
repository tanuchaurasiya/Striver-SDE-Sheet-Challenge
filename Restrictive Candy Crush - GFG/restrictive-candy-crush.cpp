//{ Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    string Reduced_String(int k,string word){
        
        stack<pair<char,int>> st; 
        int count = 0 ;
        for(int i=0;i<word.length();i++){
            if(st.empty())
            {
                count=1;
                 st.push({word[i], 1});    
            }
            
            else{
                if(st.top().first==word[i]) 
                {
                    count= st.top().second+1;
                    st.push({word[i], st.top().second+1});
                    
                }
                else{
                    st.push({word[i],1});
                    count=1;
                }
            }
            
            if(count==k){
                while(count){
                    st.pop();
                    count--;
                }
            } 
            
        }
        
        string res="";
        vector<char> v;
        while(!st.empty()){
            v.push_back(st.top().first);
            st.pop();
        }
        
        for(int i=v.size()-1; i>=0;i--)
            res+=v[i];
        return res;
    }


};

//{ Driver Code Starts.

int main() {
    
    
    int t;cin>>t;
    while(t--)
    {
        int k;
        cin>>k;
        string s;
        cin>>s;
        Solution obj;
        cout<<obj.Reduced_String(k,s)<<"\n";
        
    }
    
	return 0;
}
// } Driver Code Ends