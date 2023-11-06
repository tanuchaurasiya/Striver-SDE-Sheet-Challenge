//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
     void Findpermutation(vector<int>& a, int n){
        int idx=-1;
        for(int i = n-2;i>=0;i--){
            if(a[i]<a[i+1]){
                idx=i;
                break;
            }
        }
        
        if(idx==-1){
            reverse(a.begin(), a.end());
            return;
        }
        
        for(int i=n-1;i>idx;i--){
            if(a[i]>a[idx]) 
            {
                int temp = a[i];
                a[i]=a[idx];
                a[idx] = temp;
                break;
            }
        }
        reverse(a.begin()+idx+1, a.end());
        return;
        
       
    }
    vector<int> nextPermutation(int N, vector<int> a){
        Findpermutation(a,N);
        return a;
    }
    
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends