class Solution {
    // ITERATIVE
    public int search(int[] nums, int target) {
        int l = 0;
        int r = nums.length - 1;
        
        while (l <= r) {
            int mid = (l + r)/2;
            
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        
        return -1;
    }
    
    // RECURSIVE
    public int binarySearch(int[] arr, int l, int r, int searchElement) {
        if (l <= r) {
            int mid = (l + r)/2;
            
            if (arr[mid] == searchElement) {
                return mid;
            }
            
            if (arr[mid] > searchElement) {
                return binarySearch(arr, l, mid - 1, searchElement);
            }
            
            return binarySearch(arr, mid + 1, r, searchElement);
        } else {
            return -1;
        }
    }
    
    public int search(int[] nums, int target) {
        int lIndex = 0;
        int rIndex = nums.length - 1;
        
        return binarySearch(nums, lIndex, rIndex, target);
    }
}