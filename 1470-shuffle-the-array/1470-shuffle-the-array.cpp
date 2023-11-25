class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
//         Remember here n is half of the size of nums array
        for(int i=0;i<nums.size();i++){
            int currNum = nums[i];
            int currPos = i;
            int newPos;
            while(currNum>0){
                if(currPos<n) 
                    newPos = 2*currPos;
                else
                    newPos = 2*(currPos-n) + 1;
                
                int newNum = nums[newPos]; 
                
                nums[newPos] = -currNum; 
                currNum = newNum;
                currPos = newPos;
            }
        }
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<0)
                nums[i] = -nums[i];
        }
        return nums;
    }
};