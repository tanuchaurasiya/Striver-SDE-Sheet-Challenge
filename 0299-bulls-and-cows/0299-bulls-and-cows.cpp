class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.length();
        int bulls=0;
        int cows=0;
        unordered_map<char,int> mp1;
        unordered_map<char,int> mp2;
        for(int i=0;i<n;i++) {
            if(secret[i]!=guess[i]){
                mp1[secret[i]]++;
                mp2[guess[i]]++;
            }
            
        }
        unordered_map<char,int> visited;
        for(int i=0;i<n;i++){
            if(secret[i]!=guess[i]) {
                if((!visited[guess[i]]) && (mp1[guess[i]]!=0)) {
                    visited[guess[i]] = 1;
                    cows+=min(mp1[guess[i]], mp2[guess[i]]);
                }
            }
            else
                bulls++;
        }
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};