int search(int* nums, int numsSize, int target) {
    int n = numsSize;
    int left =0 ;
    int right = n-1;
    while (left <=right){
        int mid = left +(right -left)/2;
        if(nums[mid]==target){
            return mid;
        }else if(nums[mid]<target){
            left=mid+1;
        }else{
            right=mid-1;
        }
    }
    return -1;
}