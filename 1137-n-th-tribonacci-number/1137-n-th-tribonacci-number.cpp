class Solution {
public:
    int trib(int n, vector<int> &arr) {
        if (n == 0) return 0;
        if (n == 1 || n == 2) return 1;

        if (arr[n] != -1) return arr[n]; // Memoization

        arr[n] = trib(n - 1, arr)
               + trib(n - 2, arr)
               + trib(n - 3, arr);

        return arr[n];
    }

    int tribonacci(int n) {
        vector<int> arr(n + 1, -1);
        return trib(n, arr);
    }
};