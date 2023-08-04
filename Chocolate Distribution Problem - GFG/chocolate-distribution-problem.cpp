//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    long long findMinDiff(vector<long long> v, long long n, long long m){
    //code
    sort(v.begin(),v.end()); 
    int i=0;
    int res=1e9;
    //  for(auto i:v)
    //      cout<<i <<" ";
    while(i<=n-m)
    {
        if(res>v[i+m-1]-v[i]) res=v[i+m-1]-v[i];
        i+=1;
    }
    return res;
    }   
};

//{ Driver Code Starts.
int main() {
	long long t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		vector<long long> a;
		long long x;
		for(long long i=0;i<n;i++)
		{
			cin>>x;
			a.push_back(x);
		}
		
		long long m;
		cin>>m;
		Solution ob;
		cout<<ob.findMinDiff(a,n,m)<<endl;
	}
	return 0;
}
// } Driver Code Ends