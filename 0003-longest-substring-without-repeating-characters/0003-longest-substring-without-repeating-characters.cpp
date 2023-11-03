class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0;
        int n= s.length(); 
        int res= 0;
        // cout<<n;
        while(i<n){
            int j=i+1;
            unordered_map<char, int> st; 
            st[s[i]]=1; 
            
            while(j<n){
                if(st[s[j]]==0) { 
                    st[s[j]]=1; 
                    j+=1;
                }
                else{
                    res=max(res, j-i);
                    break;
                }
            }
            
            
            res=max(res,j-i);
            i+=1;
        }
        return res;
    }
        
};