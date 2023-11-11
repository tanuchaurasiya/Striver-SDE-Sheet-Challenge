class Graph:

    def __init__(self, n: int, edges: List[List[int]]):
        self.graph = {} 
        self.n=n
        for i in range(0,n):
            self.graph[i]=[]

        for i in range(len(edges)):
            self.graph[edges[i][0]].append([edges[i][2],edges[i][1]])
        print(self.graph)
            
        

    def addEdge(self, edges: List[int]) -> None:
        self.graph[edges[0]].append([edges[2],edges[1]])
        

    def shortestPath(self, node1: int, node2: int) -> int:
        def dijkstra(graph,start,visited,distance):
            distance[start]=0 
            bag=[] 
            heappush(bag,[0,start]) 
            while bag:
                d,n=heappop(bag) 
                visited[n]=1 
                for cd,cn in graph[n]:
                    if not visited[cn] and distance[cn]>distance[n]+cd:
                        distance[cn]=distance[n]+cd
                        heappush(bag,[distance[cn],cn]) 
            print(distance) 
        visited={}
        distance={}
        for i in range(0,self.n):
            distance[i]=10**8+1 
            visited[i]=0 
        dijkstra(self.graph,node1,visited,distance) 
        m= distance[node2] 
        if m==10**8+1 :
            return -1 
        else:
            return m
         
        


# Your Graph object will be instantiated and called as such:
# obj = Graph(n, edges)
# obj.addEdge(edge)
# param_2 = obj.shortestPath(node1,node2)