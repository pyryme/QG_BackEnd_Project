#include"sort1.h"


int main() {
    int nums[] = { 1,2,1,0,2,0,0 };
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    printf("����ǰ: ");
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    sortColors(nums, numsSize);

    printf("�����: ");
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n---------------------\n");


 
    int arr[] = { 5,2,8,4,3,7,6 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3; // �ҵ���3С����

    int result = findKthSmallest(arr, 0, n - 1, k);

    if (result != -1) {
        printf("�� %d С�����ǣ�%d\n", k, result);
    }
    else {
        printf("�Ҳ����� %d С����\n", k);
    }

    



    return 0;
}