class Solution {
public:
    long long find(long long int node, vector<long long int> &graph){
        if(graph[node]<0) 
            return node;
        long long int temp = find(graph[node], graph);
        graph[node] = temp;
        return temp;
    }
    
    bool Union(long long int node1, long long int node2, vector<long long int> &graph){
        long long int n1 = find(node1, graph);
        long long int n2 = find(node2,  graph);
        if(n1==n2)
            return false;
        
        if(abs(graph[n1]) >= abs(graph[n2])) {
            graph[n1] = graph[n1]+graph[n2];
            graph[n2] = n1;
        }
        else{
            graph[n2] = graph[n1] + graph[n2];
            graph[n1] = n2;
        }
        
        return true;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        // return 0;
        long long int leng = points.size();
        
        vector<vector<long long int>> v;
        for(long long int i=0;i<leng;i++){
            for(long long int j=i+1;j<leng;j++)
                v.push_back({abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]),i,j});
        }
        
        sort(v.begin(), v.end());
        vector<long long int> graph(leng,-1);
        int res=0;
        
        for(auto temp:v){
            if(Union(temp[1], temp[2], graph))
                res+=temp[0];
        }
        
        return res;
    }
};