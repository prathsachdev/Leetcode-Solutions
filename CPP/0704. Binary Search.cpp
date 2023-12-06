class Solution {
public:
    // ITERATIVE
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        
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
    int binarySearch(vector<int>& arr, int l, int r, int searchElement) {
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
    
    int search(vector<int>& nums, int target) {
        int lIndex = 0;
        int rIndex = nums.size() - 1;
        
        return binarySearch(nums, lIndex, rIndex, target);
    }
};