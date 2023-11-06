//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    void help(int i, int sum, vector<int> arr, vector<int> &res, int n){
        // cout<<sum<<endl;
        if(i>=n){
            res.push_back(sum); 
            return; 
        }
        help(i+1, sum+arr[i],arr, res, n); 
        help(i+1,sum, arr, res, n);
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> res;
        help(0,0,arr,res,N); 
        return res;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends