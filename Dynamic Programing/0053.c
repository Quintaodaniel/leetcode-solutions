/*
 * Time complexity: O(n)
 * Space complexity: O(1)
*/

#include <stdio.h>

int maxSubArray(int* nums, int numsSize) {
    int maxSum = nums[0];
    int sum = 0;

    for (int i = 0; i < numsSize; i++) {
        if (sum >= 0) sum += nums[i];
        else sum = nums[i];

        if (sum > maxSum) maxSum = sum;
    }

    return maxSum;
}