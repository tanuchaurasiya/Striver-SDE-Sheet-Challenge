class Solution {
public:
    int maxHistogramArea(vector<int> heights){
        int n = heights.size();
        vector<int> leftSmaller(n);
        vector<int> rightSmaller(n);
        
        stack<pair<int,int>> st;
        for(int i=0;i<n;i++){
            if(st.empty()){
                leftSmaller[i]=0;
                st.push({i, heights[i]});
            }
            else{
                while(!st.empty()){
                    int idx = st.top().first;
                    int val = st.top().second;
                
                    if(val>=heights[i])
                        st.pop();
                    else{
                        leftSmaller[i] = idx+1;
                        st.push({i, heights[i]}); 
                        break;
                    }
                }
                
                if(st.empty()){
                    leftSmaller[i] = 0;
                    st.push({i, heights[i]});
                }      
            }
        }
        
        while(!st.empty()) st.pop();
        
        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                rightSmaller[i]=n-1;
                st.push({i, heights[i]});
            }
            else{
                while(!st.empty()){
                    int idx = st.top().first;
                    int val = st.top().second;
                
                    if(val>=heights[i])
                        st.pop();
                    else{
                        rightSmaller[i] = idx-1;
                        st.push({i, heights[i]}); 
                        break;
                    }
                }
                
                if(st.empty()){
                    rightSmaller[i] = n-1;
                    st.push({i, heights[i]});
                }      
            }
        }
        
        int res=0;
        for(int i=0;i<n;i++)
            res=max(res, (rightSmaller[i]-leftSmaller[i]+1)* heights[i]);
        return res;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<int> heights(m,0);
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1')
                    heights[j]+=1;
                else
                    heights[j] = 0;
            }
            ans = max(ans, maxHistogramArea(heights));
        }
        
        return ans;
            
    }
};