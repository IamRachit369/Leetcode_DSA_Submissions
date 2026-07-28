class Solution {
public:
    bool isPowerOfTwo(int n) {
        int curr = 1;
        if(n == 1) return true;
        for(int i = 1; i < 31; i++)
        {
            curr = curr * 2;
            if(curr == n) return true;
        }
        return false;
    }
};