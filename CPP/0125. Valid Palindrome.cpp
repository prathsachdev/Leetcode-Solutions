class Solution {
public:
    bool isPalindrome(string s) {
        int lPtr = 0, rPtr = s.length() - 1;
        
        while (lPtr < rPtr) {
            while (lPtr < rPtr && !isalnum(s[lPtr])) {
                ++lPtr;
            }
            
            while (lPtr < rPtr && !isalnum(s[rPtr])) {
                --rPtr;
            }
            
            if (tolower(s[lPtr]) != tolower(s[rPtr])) {
                return false;
            }
            
            ++lPtr;
            --rPtr;
        }        
        
        return true;
    }
};