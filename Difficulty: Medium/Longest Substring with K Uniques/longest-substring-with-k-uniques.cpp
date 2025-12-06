class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        unordered_map<char, int> mp;
        int low = 0, high = 0;
        int ans = 0;

        while (high < s.size()) {
            mp[s[high]]++;  // include current character

            // shrink the window if more than k distinct characters
            while (mp.size() > k) {
                mp[s[low]]--;
                if (mp[s[low]] == 0) mp.erase(s[low]);
                low++;
            }

            // update answer only when we have exactly k distinct chars
            if (mp.size() == k) {
                ans = max(ans, high - low + 1);
            }

            high++;
        }

        return (ans == 0 ? -1 : ans);
    }
};
