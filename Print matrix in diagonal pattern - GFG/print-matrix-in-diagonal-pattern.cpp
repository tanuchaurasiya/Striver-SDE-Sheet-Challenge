//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method */

class Solution{
  public:
    vector<int> matrixDiagonally(vector<vector<int>>&mat)
    {
         //Your code here
         int rows = mat.size();
        int cols = mat[0].size(); 
        
        int going_up = true;
        int curr_row = 0;
        int curr_col = 0;
        int i = 1;
        vector<int> res;
        
        while(res.size()!=rows*cols){
            if(going_up){
                while(curr_row>=0 && curr_col<cols){
                    res.push_back(mat[curr_row][curr_col]);
                    curr_row-=1;
                    curr_col+=1;
                }
                if(curr_col==cols){
                    curr_row+=2;
                    curr_col-=1;
                } 
                else
                    curr_row+=1;
                going_up=false;
            }
            
            else{
                while(curr_row<rows && curr_col>=0){
                    res.push_back(mat[curr_row][curr_col]);
                    curr_row+=1;
                    curr_col-=1;
                }
                if(curr_row==rows){
                    curr_col+=2;
                    curr_row-=1;
                } 
                else
                    curr_col+=1;
                going_up=true;
            } 
            
            i+=1;
        }
        
        return res;
    }
};


//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n;
        int k=0;
        //cin>>k;
        cin>>n;
        vector<vector<int>>mat(n, vector<int>(n));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> mat[i][j];
            }
        }
        Solution obj;
        vector<int>ans = obj.matrixDiagonally(mat);
        for(auto i: ans)cout << i << " ";
        cout << "\n";
        
       
    }
}
// } Driver Code Ends