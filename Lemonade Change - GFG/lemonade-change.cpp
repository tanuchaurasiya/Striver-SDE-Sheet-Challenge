//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool lemonadeChange(int n, vector<int> &bills) {
        // code here
        
       map<int,int> mp;
       
       for(int i=0;i<n;i++)
       {
           mp[bills[i]]++;
           int returnb=bills[i]-5;
           
         
               if(returnb >=20)
               {
                 int twenty=returnb/20;
                 if(mp[20]>=twenty)
                 returnb=returnb-twenty*20;
                 if(mp[20]>=twenty)
                 mp[20]=mp[20]-twenty;
               }
               if(returnb>=10)
               {
                   int ten=returnb/10;
                   
                   if(mp[10]>=ten)
                 returnb=returnb-ten*10;
                 if(mp[10]>=ten)
                 mp[10]=mp[10]-ten;
               }
               
               if(returnb>=5)
               {
                   int five=returnb/5;
                   if(mp[5]>=five)
                 returnb=returnb-five*5;
                 if(mp[5]>=five)
                 mp[5]=mp[5]-five;
               }
               
           
           
           if(returnb!=0)
           {
               return false;
           }
           
       }
       
       return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> bills(N);
        for (int i = 0; i < N; i++) cin >> bills[i];

        Solution obj;
        int ans = obj.lemonadeChange(N, bills);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends