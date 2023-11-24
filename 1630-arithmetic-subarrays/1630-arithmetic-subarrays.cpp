class Solution {
public:
    // Function to check if the given array forms an arithmetic sequence
    bool check(vector<int>& arr) {
        int minElement = INT_MAX; // Variable to store the minimum element in the array
        int maxElement = INT_MIN; // Variable to store the maximum element in the array
        unordered_set<int> arrSet; // Set to store elements of the array
        
        // Finding minimum and maximum elements and populating the set
        for (int num : arr) {
            minElement = min(minElement, num);
            maxElement = max(maxElement, num);
            arrSet.insert(num);
        }
        
        // Check if the elements can form an arithmetic sequence
        if ((maxElement - minElement) % (arr.size() - 1) != 0) {
            return false; // If not evenly spaced, it's not an arithmetic sequence
        }
        
        int diff = (maxElement - minElement) / (arr.size() - 1); // Calculate the common difference
        int curr = minElement + diff; // Initialize current element
        
        // Check for each expected element in the sequence
        while (curr < maxElement) {
            if (arrSet.find(curr) == arrSet.end()) {
                return false; // If any element is missing, it's not an arithmetic sequence
            }
            curr += diff; // Move to the next expected element
        }
        
        return true; // If all conditions satisfy, it's an arithmetic sequence
    }
    
    // Function to check arithmetic subarrays in the given range
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans; // Vector to store results
        
        // Iterate through the ranges and check each subarray
        for (int i = 0; i < l.size(); i++) {
            // Extract the subarray from nums using the given range [l[i], r[i]]
            vector<int> arr(begin(nums) + l[i], begin(nums) + r[i] + 1);
            ans.push_back(check(arr)); // Check if the subarray forms an arithmetic sequence
        }
        
        return ans; // Return the results for each subarray
    }
};
