class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int res=0; 
        int i=1;
        int n = colors.size(); 
        int prev=0;
        while(i<n){
            if(colors[i]==colors[prev]){
                if(neededTime[i] > neededTime[prev]){
                    res+=neededTime[prev];
                    prev=i;
                    
                }
                
                else{
                    res+=neededTime[i];
                    
                }
            }
            else{
                prev=i;
            }
            i++;
        } 
        return res;
        
    }
};