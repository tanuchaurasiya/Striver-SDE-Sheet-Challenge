class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int c=0;
        int n= s.length();
        for(auto i:s){
            if(i=='1') c++;
        }
        
        int i=0;
        while(i<c-1){
            s[i]='1';
            i++;
        }
        while(i<n-1){
            s[i]='0';
            i++;
        }
        s[i]='1';
        return s;
        
    }
};