#include <limits.h>
int minSubArrayLen(int target, int* nums, int numsSize) {
    // initally point l and r both at the start them sincrement one by one
    int sum =0;
    int left=0;
    int minlength = INT_MAX;
    for (int right = 0; right < numsSize; right++) {
        sum += nums[right];

        // Shrink window while target constraint is satisfied
        while (sum >= target) {
            int currentLen = right - left + 1;
            if (currentLen < minlength) {
                minlength = currentLen;
            }
            sum -= nums[left];
            left++;
        }
    }

    // Return 0 if no valid subarray was found
    return (minlength == INT_MAX) ? 0 : minlength;
}
