class Solution {
public:
    int addDigits(int num) {
        while (num >= 10) {
            int currentSum = 0;
            int temp = num;
            while (temp > 0) {
                currentSum += temp % 10;
                temp /= 10;
            }
            num = currentSum;
        }
        return num;
    }
};