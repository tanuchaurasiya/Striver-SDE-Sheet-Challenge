class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        ref_map = {}        
        for n in range(len(nums)):
            if nums[n] not in ref_map:
                ref_map[nums[n]] = n
            second_number = target -nums[n]            
            if second_number in ref_map and ref_map.get(second_number)!=n:
                return[n, ref_map.get(second_number)]	