class Solution {
public:
    vector<int> nextLargerElement(vector<int>& arr) {
        int n = arr.size();
        vector<int> NGE(n, -1);        // Initialize all with -1
        stack<int> st;                 // Stack to store potential NGE

        // Traverse from right to left
        for (int i = n - 1; i >= 0; i--) {
            // Pop elements smaller or equal to arr[i]
            while (!st.empty() && st.top() <= arr[i]) {
                st.pop();
            }

            // If stack not empty, top is the next greater element
            if (!st.empty()) {
                NGE[i] = st.top();
            }

            // Push current element to stack
            st.push(arr[i]);
        }
        return NGE;
    }
};
