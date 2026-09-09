class Solution {
public:
    long long countCommas(long long n) {
        long long ans = max(n - 999, 0LL) + max(n - 999999, 0LL) + max(n - 999999999, 0LL) + max(n - 999999999999, 0LL) + max(n - 999999999999999, 0LL);
        return ans;
    }
};