class Solution {
public:
    int find_sum(int n)
    {
        int count = 0;
        while(n)
        {
            count += n%10;
            n/=10;
        }
        return count;
    }
    int find_prod(int n)
    {
        int curr = 1;
        while(n)
        {
            curr *= n%10;
            n/=10;
        }
        return curr;
    }
    bool checkDivisibility(int n) {
        int sum = find_sum(n);
        int prod = find_prod(n);
        return !(n%(sum + prod));
    }
};