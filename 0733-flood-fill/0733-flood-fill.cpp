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
        while(!q.empty())
        { 
            int i = q.front().first;
            int j = q.front().second; 
            q.pop();
            image[i][j]=newColor;
            if(isValid(i-1,j,r,c,clr,image) )
                q.push({i-1,j});
                
            if(isValid(i,j-1,r,c,clr,image)) 
                q.push({i,j-1});
                
            if(isValid(i+1,j,r,c,clr,image)) 
                q.push({i+1,j});
                
            if(isValid(i,j+1,r,c,clr,image)) 
                q.push({i,j+1});
                
        }
        
        return image;
    }
};