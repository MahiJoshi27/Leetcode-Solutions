class Solution {
public:

    const int M = 1e9 + 7;

    long long findPower(long long a, long long b) {

        // a^0 = 1
        if(b == 0) {
            return 1;
        }

        // Calculate a^(b/2)
        long long half = findPower(a, b/2);

        // (a^(b/2))²
        long long result = (half * half) % M;

        // If b is odd, multiply one extra a
        if(b % 2 == 1) {
            result = (result * a) % M;
        }

        return result;
    }

    int countGoodNumbers(long long n) {

        return findPower(5, (n+1)/2)
             * findPower(4, n/2) % M;
    }
};