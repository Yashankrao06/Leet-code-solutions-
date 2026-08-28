int findMaxConsecutiveOnes(int* nums, int numsSize) {
    int count =0;
    int left=0;
    int right = numsSize;
    int currentcount =0;
    while(left<right){
        if(nums[left]==1){
            currentcount++;
            if(currentcount>count){
                count=currentcount;
            }
        }else{
            currentcount=0;
        }left++;
    }
    return count;
}