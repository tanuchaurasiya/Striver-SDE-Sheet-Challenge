class Solution {
public:
    unordered_map<char, int> mp;
    bool cmp(char c1, char c2){
        if(mp[c1]> mp[c2]) return true;
        return false;
    }
    string customSortString(string order, string s) { 
        mp.clear();
        int c = order.length();
        for(auto i:order){
            mp[i] = c;
            c--;
        }
        sort(s.begin(), s.end(), [this](char a, char b) { return cmp(a,b); });
        return s;
    }
};