class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int res=0;
        int n = points.size();
        for(int i=0;i<n;i++){
            unordered_map<int,int> mp;
            for(int j=0;j<n;j++){
                int dist = (points[i][0] - points[j][0])*(points[i][0] - points[j][0]) + (points[i][1] - points[j][1])*(points[i][1] - points[j][1]);
                
                mp[dist]+=1;
            } 
            for(auto kv:mp){
                int v = kv.second;
                res+=(v*(v-1));
            }
        }
        
        return res;
    }
};