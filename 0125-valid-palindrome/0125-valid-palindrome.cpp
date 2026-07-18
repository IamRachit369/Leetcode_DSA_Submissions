class Solution {
public:
    vector<char>valid = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','0','1','2','3','4','5','6','7','8','9'};
    bool isValid(char s)
    {
        return (find(valid.begin(), valid.end(), s)!=valid.end());
    }
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.size() - 1;
        
        while(i < j)
        {
           while(i < s.size() && !isValid(tolower(s[i])))
           {
            i++;
           }
           while(j >= 0 && !isValid(tolower(s[j])))
           {
            j--;
           }
           if(i < j && tolower(s[i]) == tolower(s[j]))
           {
            i++;
            j--;
           }
           else if(i < j)
           {
            return false;
           }
        }
        return true;
    }
};