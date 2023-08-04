//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    bool check(int i,int j,int row,int col){
        return i>-1&&i<row && j>-1&&j<col;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int clr) {
        // Code here 

        //these array are the direction in which flood water can move
        int row[4]={0,-1,0,1};
        int col[4]={-1,0,1,0};

        //size of area
        int n=image.size(),m=image[0].size();

        //visited area 
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        queue <pair<int,int>> q;
        int oldclr=image[sr][sc];
        q.push({sr,sc});
        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            visited[i][j]=true;
            image[i][j]=clr;
            q.pop();
            for(int k=0;k<4;k++){
                if(check(i+row[k],j+col[k],n,m)&& image[i+row[k]][j+col[k]]==oldclr && !visited[i+row[k]][j+col[k]]){
                    image[i+row[k]][j+col[k]]=clr;
                    visited[i+row[k]][j+col[k]]=true;
                    q.push({i+row[k],j+col[k]});
                }
            }
        }
        return image;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends