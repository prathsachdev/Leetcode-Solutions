class Solution {
    public int[] dailyTemperatures(int[] temperatures) {
        int size = temperatures.length;
        int[] ans = new int[size];
        Stack<Integer> helperStack = new Stack<>();

        for (int i = size - 1; i >= 0; --i) {
            // Popping all indices with a lower or equal
            // temperature than the current index
            while (!helperStack.isEmpty() && temperatures[i] >= temperatures[helperStack.peek()]) {
                helperStack.pop();
            }
            
            // If the stack still has elements,
            // then the next warmer temperature exists!
            if (!helperStack.isEmpty()) {
                ans[i] = helperStack.peek() - i;
            }
            
            // Inserting current index in the stack
            helperStack.push(i);
        }
        
        return ans;
    }
}