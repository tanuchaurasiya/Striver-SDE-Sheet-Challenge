class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int res1=1e9+7;
        int res2=1e9+7;
        int count1=0;
        int count2 =0;
        for(int i=0;i<nums.size();i++){
            
            if(nums[i]==res2)
                    count2+=1; 
            
            else if(nums[i]==res1)
                    count1+=1;
            
            else if(count1==0)
            {
                count1=1;
                res1=nums[i];
            }
            else if(count2==0){ 
                count2=1;
                res2=nums[i];
            }
            
            
            else{
                count1-=1;
                count2-=1;
            }
                
        } 
        
        cout<<count1<<" "<<count2<<" "<<res1<<" "<<res2<<endl;
        
        count1=0;
        count2=0;
        for(int i=0;i<nums.size();i++){
            if (nums[i]==res1)
                count1++;
            if(nums[i]==res2)
                count2++;
        }
        
        if(count1> int(nums.size()/3) && count2> int(nums.size()/3)) return {res1,res2}; 
        
        if(count1> int(nums.size()/3)) return {res1};
        
        if(count2> int(nums.size()/3)) return {res2};
        
        return {};
    }
};