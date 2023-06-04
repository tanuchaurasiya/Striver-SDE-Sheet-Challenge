class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals = sorted(intervals)
        tmp = intervals[0]
        ans = []
        for i in range(1,len(intervals)):
            if tmp[0] <= intervals[i][0] <= tmp[1]:
                tmp = [tmp[0],max(intervals[i][1],tmp[1])]
            else:
                ans.append(tmp)
                tmp = intervals[i]
        ans.append(tmp)
        return ans