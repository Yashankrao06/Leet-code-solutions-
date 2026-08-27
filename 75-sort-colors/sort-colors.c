void sortColors(int* nums, int numsSize) {
    int mid = 0;
    int low = 0;
    int high = numsSize - 1;

    while (mid <= high) {
        if (nums[mid] == 0) {
            // Swap nums[low] and nums[mid]
            int temp = nums[low];
            nums[low] = nums[mid];
            nums[mid] = temp;
            
            low++;
            mid++;
        } else if (nums[mid] == 1) {
            mid++;
        } else {
            // Swap nums[mid] and nums[high]
            int temp = nums[high];
            nums[high] = nums[mid];
            nums[mid] = temp;
            
            high--;
        }
    }
}