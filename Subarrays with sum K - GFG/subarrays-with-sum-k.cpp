//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int findSubArraySum(int A[], int N, int k)
    {
        // code here
        int sum=0;
        int res=0;

        unordered_map<int,int> prefixsum; 
        for(int i=0;i<N;i++)
            {
                sum+=A[i]; 
                if(sum==k)
                    res+=1; 
                if(prefixsum.find(sum-k)!=prefixsum.end())
                {
                    res+=prefixsum[sum-k].size();
                }
                
                prefixsum[sum].push_back(i);;
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
        int N;
        cin >> N;
        int Arr[N];
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int k;
        cin>>k;
        Solution obj;
        cout<<obj.findSubArraySum(Arr, N, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends