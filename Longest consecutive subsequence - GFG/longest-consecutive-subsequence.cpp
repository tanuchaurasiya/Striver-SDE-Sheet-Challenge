//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int nums[], int n)
    {
        unordered_set<int> sett;
        for(int i=0;i<n;i++)
            sett.insert(nums[i]);
        
        int res=0;
        for(auto i:sett){
            if(sett.find(i-1)!=sett.end())
                continue;
            int count = 0;
            int x = i;
            while(sett.find(x)!=sett.end()) 
            {
                count+=1;
                x+=1;
            }
            
            res=max(res, count);
        }
        return res; 
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends