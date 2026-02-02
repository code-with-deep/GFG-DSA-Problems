class Solution {
  public:
    int cntSubarrays(vector<int> &arr, int k) {
        unordered_map<int,int> f;
        f[0] = 1;          // prefix sum 0 occurs once

        int sum = 0, count = 0;

        for(int i = 0; i < arr.size(); i++) {
            sum += arr[i];

            if(f.find(sum - k) != f.end()) {
                count += f[sum - k];
            }

            f[sum]++;
        }

        return count;
    }
};
