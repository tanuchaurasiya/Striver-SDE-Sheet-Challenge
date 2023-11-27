class Solution:
    def shortestAlternatingPaths(self, n: int, redEdges: List[List[int]], blueEdges: List[List[int]]) -> List[int]:
        red=collections.defaultdict(list)
        blue=collections.defaultdict(list) 
        for src,dst in redEdges:
            red[src].append(dst) 
        for src,dst in blueEdges:
            blue[src].append(dst) 
        
        ans=[-1 for i in range(n)] 
        ans[0]=0 
        q=[] 
        q.append([0,0,None]) #[node,dist,prev_edge_clr] 
        visit=set()  
        while q:
            node,dist,prev_edge_clr=q.pop(0) 
            if (node, prev_edge_clr) in visit : continue
            visit.add((node,prev_edge_clr)) 
            if ans[node]==-1:
                ans[node]=dist 
            if prev_edge_clr!="RED":
                for neighbour in red[node]: 
                    if (neighbour,"RED") not in visit:
                        q.append([neighbour,dist+1,"RED"])
            if prev_edge_clr!="BLUE":
                for neighbour in blue[node]: 
                    if (neighbour,"BLUE") not in visit:
                        q.append([neighbour,dist+1,"BLUE"]) 
        
        return ans