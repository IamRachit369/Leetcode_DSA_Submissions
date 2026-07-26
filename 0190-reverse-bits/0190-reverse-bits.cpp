class Solution {
public:
    int reverseBits(int n) {
        bitset<32>b(n);
        string s = b.to_string();
        reverse(s.begin(), s.end());
        int ans = stoi(s, nullptr, 2);
        return ans;
    }
};