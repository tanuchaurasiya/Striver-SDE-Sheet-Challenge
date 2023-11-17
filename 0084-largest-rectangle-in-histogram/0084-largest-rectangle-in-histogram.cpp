class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> leftSmaller(n,-1);
        vector<int> rightSmaller(n,-1);
        stack<pair<int,int>> s;
        for(int i=0;i<n;i++){
            if(s.empty()){
                leftSmaller[i] = 0;
                s.push({0, heights[i]});
            }
            else{
                while(!s.empty()){
                    int idx = s.top().first;
                    int val = s.top().second;
                    if(heights[i]<=val)
                        s.pop();
                    else{
                        leftSmaller[i] = idx+1;
                        s.push({i,heights[i]});
                        break;
                    }
                }
                
                if(s.empty()) 
                {
                    leftSmaller[i] = 0;
                    s.push({i,heights[i]});
                }
            }
        }
        
        
        while(!s.empty())
            s.pop();
        
        for(int i=n-1;i>=0;i--){
            if(s.empty()){
                rightSmaller[i] = n-1;
                s.push({i, heights[i]});
            }
            else{
                while(!s.empty()){
                    int idx = s.top().first;
                    int val = s.top().second;
                    if(heights[i]<=val)
                        s.pop();
                    else{
                        rightSmaller[i] = idx-1;
                        s.push({i,heights[i]});
                        break;
                    }
                }
                
                if(s.empty()) 
                {
                    rightSmaller[i] = n-1;
                    s.push({i,heights[i]});
                }
            }
        }
    
        int res=0;
        for(int i=0;i<n;i++)
            res=max(res, (rightSmaller[i]-leftSmaller[i]+1)*heights[i]);
        
        return res;
    }
};