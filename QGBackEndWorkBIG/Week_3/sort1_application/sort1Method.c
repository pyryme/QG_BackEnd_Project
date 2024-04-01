#include"sort1.h"

void sortColors(int* nums, int numsSize) {
    int p0 = 0; // p0用于存放0的位置
    int p2 = numsSize - 1; // p2用于存放2的位置
    int i = 0; // 遍历数组的索引

    while (i <= p2) {
        if (nums[i] == 0) {// 当遍历到0时，将其与p0位置的元素交换

            int temp = nums[i];
            nums[i] = nums[p0];
            nums[p0] = temp;
            p0++;
            i++; 
        }
        else if (nums[i] == 2) {
            int temp = nums[i];
            nums[i] = nums[p2];
            nums[p2] = temp;
            p2--; 
            // 易错：因为换过来的元素还未检查，所以i不能加1（本质是i是从左往右走的，一定要保证左边都是0，所以要检查换过来的是否是0或1 而不是2）
        }
        else {
            // 当遍历到1时，直接继续往后遍历
            i++;
        }
    }
}








////////////////这个方法思路就是快速排序的分类，通过判断pivot的左右的数字数量来判断第几个大小
// 快速排序中的划分函数
int partition(int* arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            // 交换 arr[i] 和 arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // 交换 arr[i+1] 和 arr[high]，使得 pivot 放在正确的位置
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1; // 返回 pivot 的位置
}

// 找到数组中第 k 小的元素
int findKthSmallest(int* arr, int low, int high, int k) {
    if (low <= high) {
        int pivotIndex = partition(arr, low, high);

        // 如果 pivotIndex 等于 k-1，则找到第 k 小的元素
        if (pivotIndex == k - 1) {
            return arr[pivotIndex];
        }
        // 如果 pivotIndex 大于 k-1，则在左侧子数组中查找
        else if (pivotIndex > k - 1) {
            return findKthSmallest(arr, low, pivotIndex - 1, k);
        }
        // 如果 pivotIndex 小于 k-1，则在右侧子数组中查找
        else {
            return findKthSmallest(arr, pivotIndex + 1, high, k);
        }
    }
    // 如果 low 大于 high，则返回 -1 表示未找到
    return -1;
}

