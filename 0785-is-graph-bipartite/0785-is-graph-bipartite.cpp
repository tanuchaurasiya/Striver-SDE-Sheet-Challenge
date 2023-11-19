class Solution {
public:
    bool coloring(int node,int par,vector<vector<int>>& graph, vector<int> &visited, vector<int> &color){
        visited[node]=1;
        cout<<"node and par "<<node<<" "<<par<<endl;
        if(par!=-1)
        {
            cout<<"parent clr "<<color[par]<<endl;
            if(color[par]==0)
                color[node]=1;
            else
                color[node]=0;
        }
        
        for(auto child: graph[node]){
            cout<<"child and visited "<<child<<" "<<visited[child]<<endl;
            if(!visited[child]){
                if (coloring(child, node, graph, visited, color)==true) 
                    return true;
                else
                    return false;
            }
            else{
                cout<<"child and node "<<child<<" "<<node<<endl;
                cout<<"child clr="<<color[child]<<" node clr="<<color[node]<<endl;
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