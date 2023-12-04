class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int size = temperatures.size();
        vector<int> ans(size);
        stack<int> helperStack;
        
        for (int i = size - 1; i >= 0; --i) {
            // Popping all indices with a lower or equal
            // temperature than the current index
            while (!helperStack.empty() && temperatures[i] >= temperatures[helperStack.top()]) {
                helperStack.pop();
            }
            
            // If the stack still has elements,
            // then the next warmer temperature exists!
            if (!helperStack.empty()) {
                ans[i] = helperStack.top() - i;
            }
            
            // Inserting current index in the stack
            helperStack.push(i);
        }
        
        return ans;
    }
};