class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) { 
        vector<vector<pair<int,int>>> adj(n);  
        vector<int> distance(n, INT_MAX);
        for(int i=0;i<flights.size();i++){
            int s = flights[i][0];
            int d = flights[i][1]; 
            int c = flights[i][2]; 
            adj[s].push_back({c,d});  
        }
        queue<vector<int>> pq; 
        pq.push({0, 0, src}); 
        distance[src]=0;
        while(!pq.empty()){
            int dist = pq.front()[0]; 
            int k_value = pq.front()[1]; 
            int node = pq.front()[2];  
            pq.pop();
            for(auto child:adj[node]){
                int adj_edge = child.first;
                int adj_node = child.second; 
                if((distance[adj_node]>dist+adj_edge) && k_value<=k){ 
                    distance[adj_node] = dist+adj_edge; 
                    pq.push({distance[adj_node], k_value+1, adj_node});
                }
                
            }
        }
        if(distance[dst]==INT_MAX)return -1;
        return distance[dst];
    }
};