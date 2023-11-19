class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        long long int leng = points.size();
        vector<vector<pair<long long int, long long int>>> adj(leng);
        for(long long int i=0;i<leng;i++){
            for(long long int j=i+1;j<leng;j++){
                adj[i].push_back({abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]),j});
                adj[j].push_back({abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]),i});
            }
        }
        
        priority_queue<pair<long long int,long long int>, vector<pair<long long int, long long int>>, greater<pair<long long int, long long int>>> pq;
        long long int start=0;
        pq.push({0, start});
        vector<long long int> visited(leng);
        long long int res=0;
        while(!pq.empty()){
            long long int d = pq.top().first;
            long long int n = pq.top().second;
            pq.pop();
            if(visited[n]==1) continue;
            // cout<<"d and n "<<d<<" "<<n<<endl;
            res+=d;
            visited[n] = 1;
            
            for(auto child : adj[n]){
                if(!visited[child.second]){
                    pq.push({child.first, child.second});
                    // cout<<"child weight and node "<<child.first<<" "<<child.second<<endl;
                }
            }
        } 
    
        return res;
        
    }
};