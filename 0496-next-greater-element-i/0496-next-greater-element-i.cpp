class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_map<int, int> mp;
        stack<int> st;

        // Find next greater element for nums2
        for (int i = 0; i < nums2.size(); i++) {
            
            while (!st.empty() && nums2[i] > st.top()) {
                mp[st.top()] = nums2[i];
                st.pop();
            }

            st.push(nums2[i]);
        }

        // Remaining elements have no greater element
        while (!st.empty()) {
            mp[st.top()] = -1;
            st.pop();
        }

        // Answer for nums1
        vector<int> ans;

        for (int x : nums1) {
            ans.push_back(mp[x]);
        }

        return ans;
    }
};