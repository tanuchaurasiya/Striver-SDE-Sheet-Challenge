//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    void update(int a[], int n, int s[], int k)
    {
        int cs=0,j=0;
        map<int,int>m;
        for(int i=0;i<k;i++)m[s[i]-1]++;
        auto it=m.begin();
        for(int i=0;i<n;i++){
            if(i==it->first){
                a[i]=cs+=it->second;
                it++;
            }
            else a[i]=cs;
        }
    }
};

//{ Driver Code Starts.
int main()
{
	int t; cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		int a[n]={0}, updates[k]={0};
		for(int i = 0; i < k; i++)
		cin>>updates[i];
		Solution ob;
		ob.update(a, n, updates, k);
		
		for(int i = 0; i < n; i++)
		cout<<a[i]<<" ";
		
		cout<<endl;
	}
	
	return 0;
}
// } Driver Code Ends