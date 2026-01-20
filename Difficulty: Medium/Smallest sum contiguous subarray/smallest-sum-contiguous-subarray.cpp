// User function Template for C++

class Solution {
  public:
    int smallestSumSubarray(vector<int>& a) {
        int currsum = a[0];
        int minsum = a[0];
        for(int i=1; i<a.size(); i++){
            currsum = min(a[i],currsum+a[i]);
            minsum = min(currsum,minsum);
        }
        return minsum;
        
    }
};
