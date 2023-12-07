class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) { 
        int start;
        int n = gas.size();
        
        int gasSum=0;
        int costSum=0;
        
        for(auto i:gas) gasSum+=i;
        for(auto i:cost) costSum+=i; 
        
        if(gasSum<costSum) return -1;
        
        int total=0;
        int res=0;
        for(int i=0;i<n;i++){
            total+=gas[i]-cost[i];
            if(total<0) {
                total=0;
                res=i+1;
            }
        } 
        return res;
        
    }
};