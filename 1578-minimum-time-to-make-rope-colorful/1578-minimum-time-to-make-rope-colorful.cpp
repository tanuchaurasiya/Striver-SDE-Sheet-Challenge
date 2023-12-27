class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int time=0;
        int index=0;
        int sum=neededTime[0];
        int leng=colors.length();
        bool flag=false;
        for(int i=0;i<leng-1;i++){
            if(colors[i]==colors[i+1]){
                sum=sum+neededTime[i+1];
                int t=max(neededTime[i],neededTime[i+1]);
                index=max(index,t);
                flag=true;
                if(i==leng-2){
                    time=time+sum-index;
                }
            }
            else{
                if(flag==true){
                    time=time+sum-index;
                index=0;
                sum=neededTime[i+1];
                    flag=false;
                }
                else{
                    index=0;
                sum=neededTime[i+1];
                }
                
            }
        }
        return time;
    }
};