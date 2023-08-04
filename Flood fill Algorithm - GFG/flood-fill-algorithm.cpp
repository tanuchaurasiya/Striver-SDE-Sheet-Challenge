//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
public:
    
    bool isValid(int i,int j, int r,int c, int clr, vector<vector<int>>& image)
    {
        if(i>=0 && j>=0 && i<r && j<c && image[i][j]==clr)
            return true;
        return false;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        if(image[sr][sc]==newColor) 
            return image;
        int r=image.size();
        int c=image[0].size();
        int clr = image[sr][sc];
        queue<pair<int,int>> q; 
        q.push({sr,sc}); 
        image[sr][sc]=newColor;
        while(!q.empty())
        { 
            int i = q.front().first;
            int j = q.front().second; 
            q.pop();
            
            if(isValid(i-1,j,r,c,clr,image)) {
                q.push({i-1,j});
                image[i-1][j]=newColor;}
                
            if(isValid(i,j-1,r,c,clr,image)) {
                q.push({i,j-1});
                image[i][j-1]=newColor;}
                
            if(isValid(i+1,j,r,c,clr,image)) {
                q.push({i+1,j});
                image[i+1][j]=newColor;}
                
            if(isValid(i,j+1,r,c,clr,image)) {
                q.push({i,j+1});
                image[i][j+1]=newColor;}
                
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