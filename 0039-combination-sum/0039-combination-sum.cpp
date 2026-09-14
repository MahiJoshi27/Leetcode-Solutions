class Solution {
public:

    void solve(vector<int>& candidates, int target,
               int index, vector<int>& temp,
               vector<vector<int>>& ans) {

        // Target mil gaya
        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        // Target cross ho gaya
        if (target < 0) {
            return;
        }

        for (int i = index; i < candidates.size(); i++) {

            // Current element choose
            temp.push_back(candidates[i]);

            // i hi pass kar rahe hain
            // because same number dobara use kar sakte hain
            solve(candidates, target - candidates[i],
                  i, temp, ans);

            // Backtrack
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates,
                                        int target) {

        vector<vector<int>> ans;
        vector<int> temp;

        solve(candidates, target, 0, temp, ans);

        return ans;
    }
};