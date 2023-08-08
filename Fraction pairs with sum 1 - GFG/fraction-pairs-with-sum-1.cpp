//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++ 

class Solution
{
    public:
    int countFractions(int n, int nume[], int deno[])
    { 
        map<pair<int,int>,int> m;
        int res=0;
        for(int i=0;i<n;i++){
            int fac=__gcd(nume[i],deno[i]);
            nume[i]=nume[i]/fac;
            deno[i]=deno[i]/fac;
        } 
        
        for(int i=0;i<n;i++) 
        {
            if(m.find({deno[i]-nume[i],deno[i]})!=m.end())
            {
                res+=m[{deno[i]-nume[i],deno[i]}];
            }
            m[{nume[i],deno[i]}]++;
        } 
        
        return res;
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int numerator[n],denominator[n];
        for(int i=0;i<n;i++)
            cin>>numerator[i];
        for(int i=0;i<n;i++)
            cin>>denominator[i];
        Solution ob;
        int ans=ob.countFractions(n,numerator,denominator);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends