/*
 * N = numsSize
 * Time complexity: O(N) 
 * Space complexity: O(N)
*/

int missingMultiple(int* nums, int numsSize, int k) {
    bool* map = (bool*)calloc(numsSize, sizeof(bool)); 

    for (int i = 0; i < numsSize; i++) {
        int q =  nums[i] / k;
        if (nums[i] % k == 0 && q <= numsSize) {
            map[q - 1] = 1;
        }
    }

    for (int i = 0; i < numsSize; i++) {
        if (!map[i]) { 
            free(map);
            return (i + 1) * k;
        }
    }
    free(map);
    return k * (numsSize + 1);
}