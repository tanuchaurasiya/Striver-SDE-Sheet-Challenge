struct trienode{
    trienode* arr[2];
};

class Solution {
public:
    void insert(int num,trienode* root){
        trienode *temp=root;
        for(int i=31;i>=0;i--){
            int bit = (num>>i) & 1;
            if( ! temp->arr[bit])
                temp->arr[bit] = new trienode(); 
            temp=temp->arr[bit]; 
        }
    } 
    
    int findmax(int num, trienode* root){ 
        trienode *temp=root;
        int res=0;
        for(int i=31;i>=0;i--){
            int bit = num>>i & 1; 
            if(bit==0){
                if(temp->arr[1]){
                    res+=pow(2,i);
                    temp=temp->arr[1];
                } 
                else{
                    temp=temp->arr[0];
                }
            }
            if(bit==1){
                if(temp->arr[0]){
                    res+=pow(2,i);
                    temp=temp->arr[0];
                } 
                else{
                    temp=temp->arr[1];
                }
            } 
        }
        return res;
        
    }
        
vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries){
        vector<pair<int,pair<int,int>>> q;
        sort(nums.begin(),nums.end());
        int leng=queries.size();
        for(int i=0;i<leng;i++)
            q.push_back({queries[i][1],{queries[i][0],i}});
            
        sort(q.begin(),q.end()); 
        // for(auto x:q) 
        //     cout<<x.first <<" "<<x.second.first <<" "<<x.second.second<<endl;
        int n=nums.size();
        vector<int> ans(leng,0);
        trienode* root=new trienode();
        int i=0;
        for(int j=0;j<leng;j++){
            while( i< n && nums[i]<= q[j].first){
                insert(nums[i],root);
                i+=1 ;
            }
            if(i==0) 
                ans[q[j].second.second]=-1;
            else{
                ans[q[j].second.second]=findmax(q[j].second.first,root);
                // cout<<ans[q[j].second.second] <<endl;
            }
        }
         
        return ans;
        }
};