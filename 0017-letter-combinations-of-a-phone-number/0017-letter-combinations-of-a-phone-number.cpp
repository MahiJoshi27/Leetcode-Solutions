class Solution {
public:
    vector<string> ans;

    string phone[10] = {
        "", "", "abc", "def", "ghi",
        "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    void solve(int index, string digits, string temp) {

        // Base case
        if (index == digits.size()) {
            ans.push_back(temp);
            return;
        }

        // Current digit
        int digit = digits[index] - '0';

        // Try all letters of current digit
        for (int i = 0; i < phone[digit].size(); i++) {

            temp.push_back(phone[digit][i]);

            solve(index + 1, digits, temp);

            // Backtracking
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {

        if (digits.empty()) {
            return {};
        }

        solve(0, digits, "");

        return ans;
    }
};