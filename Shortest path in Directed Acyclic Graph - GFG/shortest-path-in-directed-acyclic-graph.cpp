//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector<vector<pair<int,int>>> adjList(N);
        vector<int> dist(N,1e9); 
        vector<int> res(N,0);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; 
        
        
         for(int i=0;i<M;i++){
             adjList[edges[i][0]].push_back({edges[i][2],edges[i][1]});
            //  adjList[edges[i][1]].push_back({edges[i][2],edges[i][0]});
         }
        
        pq.push({0,0}); 
        dist[0]=0;
        while(!pq.empty())
        {
            int d=pq.top().first; 
            int n = pq.top().second; 
            pq.pop();
            // cout<<n<<" "<<d<<endl;
            for(auto child :adjList[n])
            {
                int edgeweight= child.first;
                int adjNode = child.second;
                if(dist[adjNode]>d+edgeweight)
                {
                    dist[adjNode] = d+edgeweight; 
                    pq.push({dist[adjNode], adjNode});
                }
            }
        } 
        
        
        for(int i=0;i<N;i++)
        {
            if(dist[i]==1e9)
                res[i]=-1;
            else
                res[i]=dist[i];
        }
        return res;
        
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends