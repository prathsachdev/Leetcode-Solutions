class Solution {
    public boolean isPalindrome(String s) {
        int lPtr = 0, rPtr = s.length() - 1;
        
        while (lPtr < rPtr) {
            while (lPtr < rPtr && !Character.isLetterOrDigit(s.charAt(lPtr))) {
                ++lPtr;
            }
            
            while (lPtr < rPtr && !Character.isLetterOrDigit(s.charAt(rPtr))) {
                --rPtr;
            }
            
            if (Character.toLowerCase(s.charAt(lPtr)) != Character.toLowerCase(s.charAt(rPtr))) {
                return false;
            }
            
            ++lPtr;
            --rPtr;
        }
        
        return true;
    }
}