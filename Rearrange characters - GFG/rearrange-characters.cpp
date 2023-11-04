//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 26;

// } Driver Code Ends
class Solution
{
    public:
    string rearrangeString(string s)
    {
        //code here
        unordered_map<char, int> mp; 
        int n = s.length();
        for(int i=0;i<n;i++){
            mp[s[i]]+=1;
        } 
       
        vector<pair<int,char>> counter; 

        for(auto i:mp){  
            if(i.second > int((n+1)/2))
                return "-1";
            counter.push_back({i.second, i.first}); 
        }
        
        sort(counter.rbegin(),counter.rend()); 
        
        vector<char> res(n); 
        int idx=0;
        for(auto i:counter){
            
            while(i.first){
                res[idx] = i.second;
                idx+=2;
                i.first-=1;
         
                if(idx>=n)
                    idx=1;
            }
            
        }
        string op="";
        for(auto i:res)
            op+=i;
        return op;
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
	    string str1=ob.rearrangeString(str);
	    int flag=1;
	    int c[26] = {0};
	    for(int i=0; i<str.length(); i++)
	        c[str[i]-'a']+=1;
	    int f = 0;
	    int x = (str.length()+1)/2;
	    for(int i=0; i<26; i++)
	    {
	        if(c[i]>x)
	            f = 1;
	    }
	    if(f)
	    {
	        if(str1=="-1")
	            cout<<0<<endl;
	        else
	            cout<<1<<endl;
	    }
	    else
	    {
    	    int a[26] = {0};
    	    int b[26] = {0};
    	    for(int i=0; i<str.length(); i++)
    	        a[str[i]-'a']+=1;
    	    for(int i=0; i<str1.length(); i++)
    	        b[str1[i]-'a']+=1;
    	        
    	    for(int i=0; i<26; i++)
    	        if(a[i]!=b[i])
    	            flag = 0;
    	    
    	    for(int i=0;i<str1.length();i++)
    	    {
    		    if(i>0)
    		        if(str1[i-1]==str1[i])
    			        flag=0;
    	    }
    	    if(flag==1)
    		    cout<<"1\n";
    	    else
    	        cout<<"0\n";
	    }
	}
    return 0;
}
// } Driver Code Ends