class Solution {
public:
int fib(int n , vector<int> &arr){
    if(n==1 || n==2 )return n;
    if(arr[n]!=-1)return arr[n];
    arr[n]=fib(n-1, arr)+fib(n-2,arr);
    return arr[n];
}
    int climbStairs(int n) {
        vector<int> arr(n+1 , -1);
        return fib(n ,arr);
        
    }
};