class Solution {
public:
    bool isValid(int x)
    {
        return x == 2 ||  x == 3 || x == 5 || x == 7 || x == 11 || x == 13 || x == 17 || x == 19 || x == 23 || x == 29;
    }
    int find(int x)
    {
        int count = 0;
        for(int i = 0; i < 31; i++)
        {
            count += ((x >> i) & 1);
        }
        // cout << x << " " << count << endl;
        return count;
    }
    int countPrimeSetBits(int left, int right) {
        int count = 0;
        for(int i = left; i <= right; i++)
        {
            if(isValid(find(i))){
                count++;
            }
            
        }
        return count;
    }
};