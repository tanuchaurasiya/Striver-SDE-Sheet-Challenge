class Solution {
public:
    string sortVowels(string s) { 
        
        vector<char> v{'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};
        vector<char> v1;
        for(int i=0;i<s.length();i++){
             if(find(v.begin(), v.end(), s[i]) == v.end()) continue; 
             v1.push_back(s[i]); 
        }
        
        sort(v1.begin(), v1.end()); 
        int j=0;
        for(int i=0;i<s.length();i++){
            if(find(v.begin(), v.end(), s[i]) == v.end()) continue; 
            s[i] = v1[j];
            j++;
        }
        return s;
    }
};