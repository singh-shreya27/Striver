      //kindly understand this 
  class Solution {
  public:
    // Function to count the frequency of all elements from 1 to N in the array.
    vector<int> frequencyCount(vector<int>& arr) {
        int N = arr.size();

        // Step 1: Reduce all elements out of range [1, N]
        for (int i = 0; i < N; i++) {
            if (arr[i] > N || arr[i] < 1)
                arr[i] = 0;
        }

        // Step 2: Use the array to store frequencies
        for (int i = 0; i < N; i++) {
            if (arr[i] % (N + 1) > 0) {
                int index = arr[i] % (N + 1) - 1;
                arr[index] += (N + 1);
            }
        }

        // Step 3: Extract frequencies from the encoded values
        for (int i = 0; i < N; i++) {
            arr[i] /= (N + 1);
        }

        return arr;
    }
};
