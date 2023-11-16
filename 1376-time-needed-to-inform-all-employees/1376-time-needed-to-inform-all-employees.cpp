class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) { 
        unordered_map<int, vector<int>> adj;
 
        
        for(int i=0;i<n;i++){
            adj[manager[i]].push_back(i);
        }
        
        queue<pair<int,int>> q;
        q.push({headID,0});
        int maxtime = 0;
        while(!q.empty()){
            int node = q.front().first;
            int time = q.front().second;
            q.pop();
            maxtime = max(maxtime, time+informTime[node]);
            for(auto c:adj[node]){
                q.push({c, time+informTime[node]});
            } 
        } 
        
        return maxtime;
        
    }
};