// Watch neetcode vdo
class Solution {
public:
    string longestPalindrome(string s) { 
        int res=0;
        string op;
        int n=s.length();
        
        for(int i=0;i<n;i++){
            int l = i;
            int r = i;
            string x ="";
            while(l>=0 && r<=n-1 && s[l]==s[r]){ 
                if(l==r)
                    x+=s[l]; 
                else
                    x=s[l] + x + s[r];
            
                l-=1;
                r+=1;
            } 
            
            // cout<<"x before ="<<x<<endl;
            if (res<r-l+1){
                res=r-l+1; 
                op = x;
            } 
            
            l = i;
            r = i+1;
            x="";
            
            while(l>=0 && r<=n-1 && s[l]==s[r]){
                x=s[l]+x+s[r]; 
                l-=1;
                r+=1;
            } 
            
            // cout<<"x after ="<<x<<endl;
            if (res<r-l+1){
                res=r-l+1; 
                op = x;
            } 
        }
        return op;
    }
};