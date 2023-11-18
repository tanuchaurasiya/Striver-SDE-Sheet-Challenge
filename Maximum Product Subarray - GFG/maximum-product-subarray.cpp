//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(vector<int> nums, int n) {
	    // code here
	    long long res=-1e9;
	    long long prefix=1;
        long long suffix=1;
        for(long long i=0;i<n;i++){
            if (prefix==0)
                prefix=1;
            if (suffix==0)
                suffix=1;
            prefix=prefix*nums[i];
            suffix=suffix*nums[n-i-1];
            res=max(res,max(prefix,suffix));
        }
        return res;
	    
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends