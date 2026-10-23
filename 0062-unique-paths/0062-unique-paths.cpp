
class Solution {
public:
    int helper(int i, int j, int m, int n, vector<vector<int>>& arr) {
        if(i == m - 1 && j == n - 1) return 1;

        if(i >= m || j >= n) return 0;

        if(arr[i][j] != -1) return arr[i][j];

        int right = helper(i, j + 1, m, n, arr);
        int down = helper(i + 1, j, m, n, arr);

        return arr[i][j] = right + down;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> arr(m, vector<int>(n, -1));
        return helper(0, 0, m, n, arr);
    }
};
