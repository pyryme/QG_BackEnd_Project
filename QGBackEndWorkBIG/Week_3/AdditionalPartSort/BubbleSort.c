#include"AdditionnalPartSort.h"



//---------------冒泡排序的优化1
//核心思想：在一次遍历中，如果没有发生元素交换，则表明数组已经有序，可以提前结束排序过程。
void bubbleSort1(int arr[], int n) {
    int i, j=0;
    int change=0; // 用于标志是否有交换发生

    for (i = 0; i < n - 1; i++) {
        change = 0;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                change = 1; //这个作为是否进行改变的标志
            }
        }
        // 如果没有交换发生，说明数组已经有序，提前结束
        if (change==0) break;
           
    }
}


//-----------------冒泡排序的优化2
//核心思想：在每一轮排序中，通过记录上一次交换的位置，可以确定无序区域的范围，从而减少内循环的遍历次数。(在优化1的基础上的优化)
void bubbleSort2(int arr[], int n) {
    int i, j=0;
    int FinalChange = n - 1; //最后改变的位置，本质是位置
    int change = 0;

    for (i = 0; i < n - 1; i++) {
        int CurrentChange = 0; // 当前交换发生的位置,必须这样设置一个变量来记录j，因为最后一次判断的时候会执行j=0，所以无法在for循环之后再用j了

        for (j = 0; j < FinalChange; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                change = 1; 
                CurrentChange = j; 
            }
        }

        if (change==0) break;
        FinalChange = CurrentChange;
    }
}

//-----------------冒泡排序的优化3
//核心思想：在1，2的基础上进行优化。2的优化是省去尾部已经有序的区间，这里就是再加上省去开头已经有序的区间
void bubbleSort3(int arr[], int n) {
    int i, j=0;
    int FinalIndex = n - 1; // 最后一次交换的位置
    int StartIndex = 0; // 第一次无序的位置

    for (i = 0; i < n - 1; i++) {
        int isChange = 0; 
        int CurrentIndex = -1; 

        for (j = StartIndex; j < FinalIndex; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                isChange = 1; 
                CurrentIndex = j; 
            }
        }

        if (isChange ==0)
            break;

        FinalIndex = CurrentIndex; 
        for (j = FinalIndex; j > StartIndex; j--) {
            if (arr[j] < arr[j - 1]) {
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
                isChange = 1;
                CurrentIndex = j - 1; 
            }
        }

        if (isChange ==0)
            break;

        StartIndex = CurrentIndex + 1;
    }
}



