#include"sort.h"

int main() {
    printf("目标3：编写一个按要求生成测试数据，并保存到文件的程序，和一个能按要求读取文件中的数据，并让上述排序函数进行排序的程序。\n");
//////////////////////////////////////目的3的代码
    //生成数据1存入到文件中
    generateTestData("test_data10k.txt", 10000); // 生成 10000 个随机数，可根据需要修改数量
    generateTestData("test_data50k.txt", 50000);
    generateTestData("test_data200k.txt", 200000);


    //读取数据1,2,3.
    const char* filename1 = "test_data10k.txt";
    const char* filename2 = "test_data50k.txt";
    const char* filename3 = "test_data200k.txt";
    int count1 = 10000; // 需要与生成测试数据时的数量匹配
    int count2 = 50000;
    int count3 = 200000;
    int* data1 = readDataFromFile(filename1, count1);
    int* data2 = readDataFromFile(filename2, count2);
    int* data3 = readDataFromFile(filename3, count3);
    if (data1 == NULL) {
        return 1;
    }

    // 调用排序函数对 data 进行排序.配合printf可以测试
    // 在这里调用你的排序函数，例如：
    //insertsort(data1, count1);
    //mergesort(data1, count1);
    //quicksort(data1, count1);
    //countsort(data1, count1);
    //radixsort(data1, count1);

    // 打印排序后的数组（仅用于验证这个排序功能是否正常进行）
    //printSortedArray(data1, count1);
///////////////////////////////////////// 上面是目标3的代码

    printf("\n\n");
    printf("目标1：编写测试程序，输出上述排序函数在不同的大数据量下的用时，有三个层次（10000、50000、200000)\n");

 ////////////////////////下面是目标1的代码
    int sizes[] = { 10000, 50000, 200000 }; // 测试不同大小的数据集
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);

    void (*sorting_algorithms[])(int*, unsigned int) = {
        insertsort,
        mergesort,
        quicksort,
        countsort,
        radixsort
    };
    int num_algorithms = sizeof(sorting_algorithms) / sizeof(sorting_algorithms[0]);

    for (int i = 0; i < num_algorithms; i++) {
        void (*sortFunction)(int*, unsigned int) = sorting_algorithms[i];
        printf("评估排序函数：%d\n", i + 1);
        for (int j = 0; j < num_sizes; j++) {
            int size = sizes[j];
            evaluateSortingAlgorithm(sortFunction, size);
        }
        printf("\n");
    }

/////////////////////////////////下面是目标2的代码

    // 测试参数
    int dataSize = 100; // 数据大小
    int numIterations = 100000; // 迭代次数

    // 测试排序函数
    /*void (*sorting_algorithms[])(int*, unsigned int) = {
        insertsort,
        mergesort,
        quicksort,
        countsort,
        radixsort
    };*/
    int num_algorithms_2 = sizeof(sorting_algorithms) / sizeof(sorting_algorithms[0]);

    for (int i = 0; i < num_algorithms_2; i++) {
        printf("评估排序函数：%d\n", i + 1);
        evaluateSortingAlgorithmSmallData(sorting_algorithms[i], dataSize, numIterations);
        printf("\n");
    }


///////////////////////////////////////

    // 释放动态分配的内存
    free(data1);
    free(data2);
    free(data3);
    return 0;

}

