class Solution:
    def findCircleNum(self, isConn: List[List[int]]) -> int:
        def dfs(graph,node,visited):
            visited[node]=1 
            for child in graph[node]:
                if not visited[child]:
                    dfs(graph,child,visited) 
        graph={} 
        visited={} 
        n=len(isConn) 
        c=0 
        for i in range(n):
            graph[i]=[]
            visited[i]=0 
        for i in range(n):
            for j in range(n):
                if isConn[i][j]==1:
                    graph[i].append(j)  
        print(graph)
        for key,val in graph.items():
            if not visited[key]:
                dfs(graph,key,visited) 
                c+=1 
        return c
        