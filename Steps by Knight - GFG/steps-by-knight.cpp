//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position. 
    bool isValid(int i, int j, int n, vector<vector<int>> &visited){
        if(i<1 || j<1 || i>n || j>n || visited[i][j]==1) 
            return false;
        return true;
    }
    
    int help(int i, int j, int n,int di, int dj){
        if(i==di && j==dj) return 0; 
        
        queue<vector<int>> q; 
        
        vector<vector<int>> visited; 
        for(int k=0;k<n+1;k++){
            vector<int> v;
            for(int p=0;p<n+1;p++)
                v.push_back(0);
            visited.push_back(v); 
        }
        
        visited[i][j] = 1; 
        vector<vector<int>> moves={{-2,-1}, {-2,1}, {-1,-2},{1,-2}, {-1,2}, {1,2},{2,-1},{2,1}};
        
        q.push({i,j, 0});
        while(!q.empty()){
            int x = q.front()[0];
            int y = q.front()[1]; 
            int d = q.front()[2];
            q.pop();
            if(x==di && y==dj) return d;
            for(auto temp:moves){
                if(isValid(x+temp[0], y+temp[1], n, visited)){
                    visited[x+temp[0]][y+temp[1]] = 1;
                    q.push({x+temp[0], y+temp[1], d+1});
                }
            }
        }
        return -1;
        
    }
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here 
	    return help(KnightPos[0], KnightPos[1], N, TargetPos[0], TargetPos[1]);
	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends