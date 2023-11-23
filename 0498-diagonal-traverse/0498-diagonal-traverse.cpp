class Solution {
public:
//     We have to traverse like -- (Up -> right) or (down - > left)  
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
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