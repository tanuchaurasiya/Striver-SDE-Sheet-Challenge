class Solution {
public:
    int maxProfitAssignment(vector<int>& diff, vector<int>& profit, vector<int>& worker) { 
        int n = diff.size();
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++)
            v.push_back({profit[i], diff[i]}); 
        
        sort(v.rbegin(), v.rend()); 
        
        sort(worker.begin(), worker.end(), greater<int>()); 
        int res=0;
        int i=0;
        int j=0;
        while(j<worker.size() && i<n){
            if(v[i].second<=worker[j]) {
                res+=v[i].first;
                j++;
            }
            else{
                i++;
            }
        } 
        return res;
        
    } 
};