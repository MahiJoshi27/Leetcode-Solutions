class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        
        sort(potions.begin(), potions.end());

        vector<int> ans;

        for(int i = 0; i < spells.size(); i++) {
            
            long long need = (success + spells[i] - 1) / spells[i];

            int idx = lower_bound(potions.begin(), potions.end(), need) - potions.begin();

            ans.push_back(potions.size() - idx);
        }

        return ans;
    }
};