//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:

int sumOfSquare(int n){
        int sum=0;
        while(n != 0){
            int d=n%10;
            sum+=(d*d);
            n/=10;
        }
        return sum;
    }
    
    bool isHappy(int n){
        if(n == 1 || n == 7){
            return true;
        }
        else if(n % 10 == n && n != 1 && n != 7){return false;}
        return isHappy(sumOfSquare(n));
        
    }

    int nextHappy(int N){
        int res=N+1;
        while(1){
            if(isHappy(res)){
                return res;
            }
            res++;
        }
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
        cin>>N;
        Solution ob;
        cout << ob.nextHappy(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends