class Solution {

public:
    long long countTriplets(int n, long long sum, long long arr[]) {

        sort(arr, arr + n);
        long long count = 0;

        for(int i = 0; i < n - 2; i++) {
            int left = i + 1, right = n - 1;

            while(left < right) {
                long long current_sum = arr[i] + arr[left] + arr[right];

                if(current_sum < sum) {
                    count += (right - left);  // Count all valid triplets
                    left++;
                } else {
                    right--;
                }
            }
        }

        return count;
    }
};
