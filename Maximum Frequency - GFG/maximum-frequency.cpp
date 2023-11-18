//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxFrequency(int nums[], int n, int k) {
        long long l=0;
        long long r=0;
        long long total=0;
        long long res=0;
        sort(nums, nums+n);
        while(r<n){
            total+=nums[r];
            while(nums[r]*(r-l+1) > total+k){
                total-=nums[l];
                l+=1;
            }
            res=max(res, r-l+1);
            r+=1;
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t; // testcases
    while (t--) {
        int n, k;
        cin >> n >> k; // total size of array and integer k

        int arr[n];

        // inserting elements in the array
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution obj;
        // calling maxFrquency() function
        int ans = obj.maxFrequency(arr, n, k);

        cout << ans << endl;
    }
}
// } Driver Code Ends