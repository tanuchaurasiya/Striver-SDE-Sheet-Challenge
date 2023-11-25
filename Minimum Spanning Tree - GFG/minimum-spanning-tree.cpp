//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	int find(int a, vector<int>&graph){
	    if(graph[a]<0) 
	        return a;
	    int temp = find(graph[a], graph);
	    graph[a] = temp;
	    return temp;
	}
	
	bool Union(int a, int b, vector<int> &graph){
	    int n1 = find(a, graph);
	    int n2 = find(b, graph);
	    
	    if(n1==n2) return false;
	    
	    if(abs(graph[n1]>=abs(graph[n2]))){
	        graph[n1] = graph[n1] + graph[n2]; 
	        graph[n2] = n1;
	    }
	    
	    else{
	        graph[n2] = graph[n1] + graph[n2]; 
	        graph[n1] = n2;
	    }
	    return true;
	}
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<int> graph(V,-1);
        vector<vector<int>> temp;
        for(int i=0;i<V;i++){ 
            for(auto j:adj[i])
               temp.push_back({j[1], i, j[0]});
        }
        int res=0;
        sort(temp.begin(),  temp.end()); 
        
        for(auto it:temp){
            // cout<<it[0]<<" "<<it[1]<<" "<<it[2]<<endl;
            if(Union(it[1], it[2], graph)) res+=it[0];
        }
        return res;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends