class Solution {
public:
 
    int maxFrequency(std::vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end()); // Sort the array
        int l = 0, r = 0;                   // Two pointers
        long long total = 0;                // To hold the sum of elements in the window
        int res = 0;                        // To track the maximum frequency

        while (r < nums.size()) {
            total += nums[r]; // Add the current number to the total

            // Check if the current window is valid
            while (static_cast<long long>(nums[r]) * (r - l + 1) > total + k) {
                total -= nums[l]; // Shrink the window from the left
                l++;
            }

            // Update the result with the size of the valid window
            res = std::max(res, r - l + 1);
            r++;
        }

        return res;
    }
};

 
