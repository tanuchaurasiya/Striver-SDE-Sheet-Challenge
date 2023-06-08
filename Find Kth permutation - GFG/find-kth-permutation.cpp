//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

//User function Template for C++

class Solution
{
public:
    string kthPermutation(int n, int k)
    {
        // code here
        string res="";
        vector<int>v;
        int c = 1;
        
        while(c<=n){
            v.push_back(c++);
        }
        int i=0,j=n-1;
        while(i<=j){
            char t = v[i];
            v[i] = v[j];
            v[j] = t;
            i++;j--;
        }
        while(k--)
            next_permutation(v.begin(), v.end());
        
        for(int i=0;i<n;i++)
            res.push_back(v[i]+'0');
        
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
        int n, k;
        cin >> n >> k;
        Solution ob;
        string ans = ob.kthPermutation(n, k);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends