class Solution {
public:

    void combinations(int i, vector<int>& cur_comb,vector<vector<int>>& final_ans,vector<int>& candidates, int target) {

        if (target == 0) {
            final_ans.push_back(cur_comb);
            return;
        }

        for (int j = i; j < candidates.size(); j++) {

            if (candidates[j] > target)
                break;

            cur_comb.push_back(candidates[j]);

            // Same element can be used again
            combinations(j, cur_comb, final_ans,
                          candidates, target - candidates[j]);

            cur_comb.pop_back(); // backtrack
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<int> cur_comb;
        vector<vector<int>> final_ans;

        sort(candidates.begin(), candidates.end());

        combinations(0, cur_comb, final_ans, candidates, target);

        return final_ans;
    }
};