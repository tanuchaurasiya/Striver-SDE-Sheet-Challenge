//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // code here 
        if(A[0][0]==0) 
        return -1;
        queue<pair<int,pair<int,int>>>q;
        vector<vector<int>>dist(N,vector<int>(M,INT_MAX));
        dist[0][0] = 0;
        q.push({dist[0][0],{0,0}});
        int nx[4] = {0,0,1,-1};
        int ny[4] = {1,-1,0,0};
        while(q.size()){
            auto ele = q.front();
            q.pop();
            if(ele.second.first == X && ele.second.second == Y){
                return ele.first;
            }
            for(int i = 0;i<4;i++){
                int x1 = ele.second.first + nx[i];
                int y1 = ele.second.second + ny[i];
                if(x1>=0 && x1<N && y1>=0 && y1<M && A[x1][y1]){
                    if(dist[x1][y1]>1+ele.first){
                        dist[x1][y1] = 1+ ele.first;
                        q.push({dist[x1][y1],{x1,y1}});
                    }
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends