class Solution:
    def checkStraightLine(self,coordinates: List[List[int]]) -> bool:
        dx1=(coordinates[1][0]-coordinates[0][0])
        dy1=(coordinates[1][1]-coordinates[0][1])
        for i in range(2,len(coordinates)):
            dx=coordinates[i][0]-coordinates[i-1][0]
            dy=coordinates[i][1]-coordinates[i-1][1]
            if(dy*dx1!=dx*dy1):return False
       
        return True