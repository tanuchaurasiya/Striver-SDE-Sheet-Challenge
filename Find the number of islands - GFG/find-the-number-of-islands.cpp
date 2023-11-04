//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands. 
    bool isvalid(int i, int j, int m, int n, vector<vector<char>>& grid){
        if(i<0 || j<0 || i>=m || j>=n ||  grid[i][j]!='1') 
            return false;
        return true;
    }
    
    void help(int i, int j, int m, int n, vector<vector<char>>& grid){
        
        grid[i][j] = '2';
        vector<vector<int>>v{{-1,0},{-1,-1},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
        for(auto x: v){
            if(isvalid(x[0]+i, x[1]+j, m,n, grid)){
                help(x[0]+i, x[1]+j,m,n,grid);
            } 
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        // Code here  
        int res=0;
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='1')
                    { 
                        res+=1; 
                        help(i,j,m,n,grid);
                    }
                    
            }
        }
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends