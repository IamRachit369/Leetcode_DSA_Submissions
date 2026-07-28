class Solution {
public:
    using ll = long long;

    long long minArraySum(vector<int>& nums) {
        ll res = 0;
        int maxVal = INT_MIN;

        for(const int& e : nums)
        {
            maxVal = max(maxVal, e);
        }

        vector<int> arr(maxVal + 1, 0);

        for(const int& a : nums)
        {
            arr[a] = a;
        }

        for(int i = 1; i <= maxVal; ++i)
        {
            if(arr[i] == i)
            {
                for(int j = 2 * i; j <= maxVal; j += i)
                {
                    if(arr[j] == j)
                    {
                        arr[j] = i;
                    }
                }
            }
        }

        for(const auto& e : nums)
        {
            res += arr[e];
        }

        return res;
    }
};