class Solution {
    public boolean isPalindrome(int x) {
        if (x < 0) {
            return false;
        }

        int num = x, revNum = 0, lastDigit = 0;
        
        while (num > 0) {
            lastDigit = num % 10;
            revNum = revNum * 10 + lastDigit;
            num = num / 10;
        }
        
        return (x == revNum);
    }
}