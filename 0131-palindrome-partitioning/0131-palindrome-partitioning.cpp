class Solution {
public:
    bool isPalindrome(string s, int start, int end){
        while(start<=end){
            if(s[start]!=s[end]) return false;
            start++;
            end--;
        }
        return true;
        
    }
    void help(int idx, string s, int n, vector<vector<string>> &res, vector<string> &path){
        if(idx==n) {
            res.push_back(path);
            return;
        } 
        
        for(int i=idx;i<n;i++){
            if(isPalindrome(s, idx, i)){
                // cout<<"s="<<s.substr(idx,i-idx+1)<<" idx="<<idx<<" i="<<i<<endl;
                path.push_back(s.substr(idx,i-idx+1)); 
                help(i+1, s, n, res, path);
                path.pop_back();
                
            } 
        }
    }
    vector<vector<string>> partition(string s) {
        int n = s.length();
        vector<vector<string>> res;
        vector<string> path;
        help(0, s, n, res, path); 
        return res;
    }
};