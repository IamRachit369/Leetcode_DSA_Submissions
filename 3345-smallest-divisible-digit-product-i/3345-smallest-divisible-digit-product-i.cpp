class Solution {
public:
    int find(int x)
    {
        int curr = 1;
        while(x)
        {
            int dig = x%10;
            curr = curr * dig;
            x = x/10;
        }
        return curr;
    }
    int smallestNumber(int n, int t) {
        while(true)
        {
            int prod = find(n);
            if(prod%t == 0)
            {
                return n;
            }
            n++;
        }
        return 0;
    }
};