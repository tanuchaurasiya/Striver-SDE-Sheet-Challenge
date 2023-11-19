class Solution {
public:
    bool coloring(int node,int par,vector<vector<int>>& graph, vector<int> &visited, vector<int> &color){
        visited[node]=1;
        if(par!=-1){
            if(color[par]==0)
                color[node]=1;
            else
                color[node]=0;
        }
        
        for(auto child: graph[node]){
            if(!visited[child]){
                if (coloring(child, node, graph, visited, color)==true) 
                    return true;
                return false;
            }
            else{
                if(color[child] == color[node])
                    return false;
            }
        }
        return true;
        
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> visited(n);
        
        for(int i=0;i<n;i++){
            if (!visited[i]){
                vector<int> color(n,-1);
                color[i]=0;
                if(coloring(i, -1, graph, visited, color)==false) 
                    return false;
            }
        }
        
        return true;
    }
};