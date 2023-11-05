// Watch striver vdo
// in c++ stl next_permuation function is present which gives the next permuation 
//  it will be like this - next_permutation(A.begin(), A.end());
// So we have to implement our own next_permuation fn instead of using stl fn.
class Solution {
public:
    void nextPermutation(vector<int>& A) {
        next_permutation(A.begin(), A.end());
    }
};