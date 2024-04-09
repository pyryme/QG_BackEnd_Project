#include"AdditionnalPartSort.h"

int main() {
    printf("这个是快速排序的非递归方法：\n");
    int arr[] = {8,9,11,7,5,3,4};//这里测试的时候随便写
    int n0 = sizeof(arr) / sizeof(arr[0]);
    NonRecursiveQuickSort(arr, 0, n0 - 1);
    printf("排序后的数组: \n");
    printArray(arr, n0);


    printf("这个是快速排序随机基准元素的方法：\n");
    int arr11[] = { 8,9,11,7,5,3,4 };
    int n11 = sizeof(arr11) / sizeof(arr11[0]);
    RandomQuickSort(arr11, 0, n11 - 1);
    printf("排序后的数组: \n");
    for (int i = 0; i < n11; i++) {
        printf("%d ", arr11[i]);
    }
    printf("\n");

    printf("这个是快速排序三枢轴的方法：\n");
    int arr22[] = { 8,9,11,7,5,3,4 };
    int n22 = sizeof(arr22) / sizeof(arr22[0]);
    TriQuickSort(arr22, 0, n22 - 1);
    printf("排序后的数组:  \n");
    printArray(arr22, n22);



    printf("这个是冒泡排序优化1的方法：\n");
    int arr1[] = { 8,9,11,7,5,3,4 };
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    bubbleSort1(arr1, n1);
    printf("排序后的数组: \n");
    for (int i = 0; i < n1; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\n");


    printf("这个是冒泡排序优化2的方法：\n");
    int arr2[] = { 8,9,11,7,5,3,4 };
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    bubbleSort2(arr2, n2);
    printf("排序后的数组: \n");
    for (int i = 0; i < n2; i++) {
        printf("%d ", arr2[i]);
    }
    printf("\n");



    printf("这个是冒泡排序优化3的方法：\n");
    int arr3[] = { 8,9,11,7,5,3,4 };
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    bubbleSort3(arr3, n3);
    printf("Sorted array: \n");
    for (int i = 0; i < n3; i++) {
        printf("%d ", arr3[i]);
    }
    printf("\n");





    return 0;
}