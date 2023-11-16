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
        nums.push_back(curr);
        unordered_map<int,int> visited;
        visited[curr]=1;
        
        while (nums.size() < adjMap.size()) {
            cout<<"curr="<<curr<<endl;
            for (auto& next : adjMap[curr]) {
                if (!visited[next]) {
                     cout<<"next="<<next<<endl;
                    nums.push_back(next);
                    visited[next]=1;
                    curr=next;
                }
            }
        }
        // nums.push_back(curr);
        return nums;
    }
};