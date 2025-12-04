class Solution {
public:
    int maxSubarraySum(vector<int>& arr, int k) {

        int n = arr.size();
        int low = 0, high = k - 1;
        int sum = 0;

        // Step 1: Calculate the sum of first window of size k
        for (int i = 0; i <= high; i++) {
            sum += arr[i];
        }

        int result = sum; // store max sum

        // Step 2: Slide the window until 'high' reaches end
        while (high < n - 1) {

            low++;          // move window start
            high++;         // move window end

            // Update window sum: remove previous element, add new element
            sum = sum - arr[low - 1] + arr[high];

            // Update result
            result = max(result, sum);
        }

        return result;
    }
};
