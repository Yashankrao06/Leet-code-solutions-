int maxArea(int* height, int heightSize) {
    int left = 0;
    int right = heightSize-1;
    int maxarea = 0;
    while(left<right){
        int maxheight = 1;
        if(height[left]<height[right]){
            maxheight= height[left];
        }else{
            maxheight= height[right];
        }

        int area = maxheight*(right-left);

        if(maxarea<area){
            maxarea=area;
        }
        if(height[left]<height[right]){
            left++;
        }else{
            right--;
        }

    }return maxarea;
    
};