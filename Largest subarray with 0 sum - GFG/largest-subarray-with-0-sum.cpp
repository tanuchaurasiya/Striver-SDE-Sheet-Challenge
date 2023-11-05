//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int N)
    {   
        // Your code here
        int sum=0;
        int res=0; 
        int k = 0;
        unordered_map<int,int> prefixsum; 
        for(int i=0;i<N;i++)
            {
                sum+=A[i]; 
                // cout<<sum<< " "<<sum-k<<" "<<prefixsum[sum-k]<<endl;
                if(sum==k)
                    res=max(res, i+1); 
                if(prefixsum.find(sum-k)!=prefixsum.end())
                    res=max(res, i-prefixsum[sum-k]);
                
                if(prefixsum.find(sum)==prefixsum.end())
                    prefixsum[sum] = i;
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
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends