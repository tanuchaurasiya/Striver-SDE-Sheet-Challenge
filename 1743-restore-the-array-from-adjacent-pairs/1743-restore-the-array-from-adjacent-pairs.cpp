class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adj) {
        unordered_map<int,int> indegree;
        unordered_map<int, vector<int>> adjMap;
        
        for(auto t: adj){
            indegree[t[0]]+=1; 
            indegree[t[1]]+=1; 
            
            adjMap[t[0]].push_back(t[1]);
            adjMap[t[1]].push_back(t[0]);
        }
        int start;
        for(auto i: indegree){
            if(i.second==1){ 
                start=i.first;
                break;
            }
        }
        int curr = start, prev = INT_MIN;
        vector<int> nums; 
        unordered_map<int,int> visited;
        while (nums.size() < adj.size()) {
            nums.push_back(curr);
            visited[curr]=1;
            for (auto& next : adjMap[curr]) {
                if (!visited[next]) {
                    curr=next;
                    // break;
                }
            }
        }
        nums.push_back(curr);
        return nums;
    }
};