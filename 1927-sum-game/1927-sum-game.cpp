class Solution {
public:
    bool sumGame(string s) {
        int firstSum = 0;
        int secondSum = 0;
        int n = s.size();
        int left_mark = 0;
        int right_mark = 0;
        for(int i = 0; i < n/2; i++)
        {
            if(s[i] == '?') 
            {
                left_mark++;
                continue;
            }
            firstSum += s[i] - '0';
        }
        for(int i = n/2; i < n; i++)
        {
            if(s[i] == '?') 
            {
                right_mark++;
                continue;
            }
            secondSum += s[i] - '0';
        }
        if((left_mark + right_mark)%2 == 1) return true;
        int LEFT = 2 * firstSum + 9 * left_mark;
        int RIGHT = 2 * secondSum + 9 * right_mark;

        return LEFT!=RIGHT;
    }
};