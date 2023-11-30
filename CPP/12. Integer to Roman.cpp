class Solution {
public:
    string intToRoman(int num) {
        int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string romanNumerals[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        
        string result;
        int index = 0;
        
        while(num > 0) {
            if(num >= values[index]) {
                result += romanNumerals[index];
                num -= values[index];
            } else {
                index++;
            }
        }
        
        return result;
    }
};