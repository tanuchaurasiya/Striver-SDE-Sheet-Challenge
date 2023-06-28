class Solution:
    def maxProbability(self, n: int, edges: List[List[int]], prob: List[float], start: int, end: int) -> float: 
        def dijkstra(start,graph,visited,probability):
            bag=[]
            heappush(bag,[-1,start])
            probability[start]=-1
            while bag:
                p1,n=heappop(bag) 
                for p,cn in graph[n]: 
                    p=-p
                    if (-(probability[n])*p)>(-probability[cn]) :
                        probability[cn] = -(-(probability[n])*p)
                        heappush(bag,[probability[cn],cn]) 
                    # print(probability,bag)

        graph={} 
        visited={} 
        probability={}
        for i in range(n):
            visited[i]=0 
            graph[i]=[] 
            probability[i]=(10**8+1)
        for i in range(len(edges)):
            graph[edges[i][0]].append([-prob[i],edges[i][1]]) 
            graph[edges[i][1]].append([-prob[i],edges[i][0]]) 
        print(graph) 
        dijkstra(start,graph,visited,probability)
        # print(probability)
        if probability[end]==10**8+1:
            return 0.00000 
        return -probability[end] 
        