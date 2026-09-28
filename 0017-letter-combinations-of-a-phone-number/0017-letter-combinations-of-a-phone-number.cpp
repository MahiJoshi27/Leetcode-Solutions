class Solution {
public:
    vector<string> ans;

    string keypad[10] = {
        "", "", "abc", "def", "ghi",
        "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    void solve(int index, string digits, string current) {

        // agar saare digits use ho gaye
        if (index == digits.size()) {
            ans.push_back(current);
            return;
        }

        // current digit
        int digit = digits[index] - '0';

        // us digit ke saare letters
        for (char ch : keypad[digit]) {

            current.push_back(ch);

            solve(index + 1, digits, current);

            current.pop_back();   // backtracking
        }
    }

    vector<string> letterCombinations(string digits) {

        if (digits.empty())
            return {};

        solve(0, digits, "");

        return ans;
    }
};