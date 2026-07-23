class Solution {
public:
    int nthUglyNumber(int n) {
        int i2;
        int i3;
        int i5;
        i2 = i3 = i5 = 1;   
        vector<int>nums(n + 1, 0);
        nums[1] = 1;
        for(int i = 2; i <= n; i++)
        {
            int second = nums[i2] * 2;
            int third = nums[i3] * 3;
            int fifth = nums[i5] * 5;
            nums[i] = min({second, third, fifth});
            if(nums[i] == second)
            {
                i2++;
            }
            if(nums[i] == third)
            {
                i3++;
            }
            if(nums[i] == fifth)
            {
                i5++;
            }
        }
        return nums[n];
    }
};