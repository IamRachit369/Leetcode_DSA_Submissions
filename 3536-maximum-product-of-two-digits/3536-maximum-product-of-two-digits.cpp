class Solution {
public:
    int maxProduct(int n) {
        vector<int>digits;
        while(n)
        {
            digits.push_back(n%10);
            n = n/10;
        }
        sort(digits.begin(), digits.end(), greater<int>());
        return (digits[0] * digits[1]);
    }
};