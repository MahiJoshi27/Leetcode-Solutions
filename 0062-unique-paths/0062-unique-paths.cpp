
class Solution {
public:
    int helper(int i, int j, vector<vector<int>>& arr) {
        if(i == 0 && j == 0) return 1;
        if(i < 0 || j < 0) return 0;
        if(arr[i][j] != -1) return arr[i][j];

        int right = helper(i - 1, j, arr);
        int down = helper(i, j - 1, arr);

        return arr[i][j] = right + down;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> arr(m, vector<int>(n, -1));
        return helper(m - 1, n - 1, arr);
    }
};
