class Solution {
public:
    string smallestNumber(string S) {
        int n=S.length();
        int cnt=1;
        vector<char>ans(n+1);
        for(int i=0;i<=n;i++){
            if(i==n || S[i]=='I'){
                for(int j=i-1;j>=-1;j--) 
                {
                    ans[j+1]=(char)('0'+cnt); 
                    // cout<<" "<<j+1<<" "<<ans[j+1]<<endl;
                    cnt++;
                    if (j >= 0 && S[j] == 'I')  
                        break;
                }
            }
        }
        
        string op="";
        for(auto i:ans)
            op+=i;
        return op;
    }
};