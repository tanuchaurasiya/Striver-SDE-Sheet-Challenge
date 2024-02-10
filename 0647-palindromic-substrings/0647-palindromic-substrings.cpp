class Solution {
public:
    int countSubstrings(string s) {
        int res=0;
        int n = s.length();
        for(int i=0;i<n;i++){
            // for odd length palindrome
            int l=i;
            int r=i; 
            while(l>=0 and r<n and s[l]==s[r]){
                res+=1;
                l-=1;
                r+=1;
            }
            
            // for even length palindrome 
            l=i;
            r=i+1;  
            while(l>=0 and r<n and s[l]==s[r]){
                res+=1;
                l-=1;
                r+=1;
            }
        }
        return res;
    }
};