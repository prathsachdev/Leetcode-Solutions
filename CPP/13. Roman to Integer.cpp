class Solution {
public:
    int romanToInt(string s) {
        vector<int> romanMap(128);
        
        romanMap['I'] = 1;
        romanMap['V'] = 5;
        romanMap['X'] = 10;
        romanMap['L'] = 50;
        romanMap['C'] = 100;
        romanMap['D'] = 500;
        romanMap['M'] = 1000;
        
        int result = 0, currValue = 0, prevValue = 0;

        for(int i = s.length() - 1; i >= 0; i--) {
            currValue = romanMap[s[i]];

            if(currValue >= prevValue) {
                result += currValue;
            } else {
                result -= currValue;
            }
            prevValue = currValue;
        }
        
        return result;
    }
};