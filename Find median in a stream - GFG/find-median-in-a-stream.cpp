//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
     priority_queue<int> maxHeap; //small
    priority_queue<int,vector<int>,greater<int>> minHeap; //large
    
    void insertHeap(int &num)
    { 
        if(maxHeap.empty() || maxHeap.top() >= num) maxHeap.push(num);
        else minHeap.push(num);

        if(maxHeap.size() > minHeap.size() + 1){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else if(maxHeap.size() < minHeap.size()){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        
    }
    
    void balanceHeaps()
    {
        
    }
    
    double getMedian()
    {
        if(maxHeap.size() == minHeap.size()){
            return maxHeap.top()/2.0 + minHeap.top()/2.0;
        }
        return maxHeap.top();
    }
};


//{ Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}
// } Driver Code Ends