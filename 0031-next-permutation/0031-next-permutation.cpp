// Watch striver vdo
// in c++ stl next_permuation function is present which gives the next permuation 
//  it will be like this - next_permutation(A.begin(), A.end());
// So we have to implement our own next_permuation fn instead of using stl fn.
class Solution {
public:
    void Findpermutation(vector<int>& a){
        int n=a.size(); 
        int idx=-1;
        for(int i = n-2;i>=0;i--){
            if(a[i]<a[i+1]){
                idx=i;
                break;
            }
        }
        
        if(idx==-1){
            reverse(a.begin(), a.end());
            return;
        }
        
        for(int i=n-1;i>idx;i--){
            if(a[i]>a[idx]) 
            {
                int temp = a[i];
                a[i]=a[idx];
                a[idx] = temp;
                break;
            }
        }
        reverse(a.begin()+idx+1, a.end());
        return;
        
       
    }
    void nextPermutation(vector<int>& a) {
        Findpermutation(a);
    }
};