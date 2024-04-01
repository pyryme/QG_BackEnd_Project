#include"sort.h"

// 生成指定数量的随机数并保存到文件
void generateTestData(const char* filename, int count) {
    FILE* fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("无法打开文件 %s\n", filename);
        return;
    }

    srand(time(NULL));
    for (int i = 0; i < count; i++) {
        fprintf(fp, "%d\n", rand() % 10000); // 生成范围在 0 到 9999 之间的随机数
    }

    fclose(fp);
    printf("已生成并保存 %d 个随机数到文件 %s\n", count, filename);
}

/*int main() {
    generateTestData("test_data.txt", 10000); // 生成 10000 个随机数，可根据需要修改数量
    return 0;
}
*/
// 读取文件中的数据
int* readDataFromFile(const char* filename, int count) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("无法打开文件 %s\n", filename);
        return NULL;
    }

    int* data = (int*)malloc(count * sizeof(int));
    if (data == NULL) {
        printf("内存申请失败\n");
        fclose(fp);
        return NULL;
    }

    for (int i = 0; i < count; i++) {
        if (fscanf(fp, "%d", &data[i]) != 1) {
            printf("读取文件失败\n");
            free(data);
            fclose(fp);
            return NULL;
        }
    }

    fclose(fp);
    return data;
}

// 打印排序后的数组
void printSortedArray(int* arr, int count) {
    for (int i = 0; i < count; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/*
int main() {

    generateTestData("test_data.txt", 10000); // 生成 10000 个随机数，可根据需要修改数量
 


    const char* filename = "test_data.txt";
    int count = 10000; // 需要与生成测试数据时的数量匹配
    int* data = readDataFromFile(filename, count);
    if (data == NULL) {
        return 1;
    }

    // 调用排序函数对 data 进行排序
    // 在这里调用你的排序函数，例如：
     insertsort(data, count);
    // mergesort(data, count);
    // quicksort(data, count);
    // countsort(data, count);
    // radixsort(data, count);

    // 打印排序后的数组（仅用于验证）
    printSortedArray(data, count);

    // 释放动态分配的内存
    free(data);

    return 0;
}
*/






///////////////////////////////////////////////
// 生成指定数量的随机数
void generateRandomNumbers(int* arr, int count) {
    srand(time(NULL));
    for (int i = 0; i < count; i++) {
        arr[i] = rand() % 1000; // 生成范围在 0 到 999 之间的随机数
    }
}

// 评估排序函数的性能，测试3个层次数据量的时间
void evaluateSortingAlgorithm(void (*sortFunction)(int*, unsigned int), int count) {
    int* data = (int*)malloc(count * sizeof(int));
    if (data == NULL) {
        printf("内存申请失败\n");
        return;
    }

    generateRandomNumbers(data, count);//这里可以改成读取文件中的数据！！！！！！！！！

    clock_t start = clock();
    sortFunction(data, count);
    clock_t end = clock();
    double elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;

    printf("数据量：%d，排序用时：%f 秒\n", count, elapsed_time);

    free(data);
}


/*
////////////////////////////////////////////////
int main() {

    generateTestData("test_data.txt", 10000); // 生成 10000 个随机数，可根据需要修改数量



    const char* filename = "test_data.txt";
    int count = 10000; // 需要与生成测试数据时的数量匹配
    int* data = readDataFromFile(filename, count);
    if (data == NULL) {
        return 1;
    }

    // 调用排序函数对 data 进行排序
    // 在这里调用你的排序函数，例如：
    insertsort(data, count);
    // mergesort(data, count);
    // quicksort(data, count);
    // countsort(data, count);
    // radixsort(data, count);

    // 打印排序后的数组（仅用于验证）
    printSortedArray(data, count);

    // 释放动态分配的内存
    free(data);

   // return 0;




    //////////////////////////////////////////////////


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

    return 0;
}*/



// 评估排序函数的性能，测量100个不同数据算100k次的时间
void evaluateSortingAlgorithmSmallData(void (*sortFunction)(int*, unsigned int), int dataSize, int numIterations) {
    int* data = (int*)malloc(dataSize * sizeof(int));
    if (data == NULL) {
        printf("内存申请失败\n");
        return;
    }

    clock_t total_time = 0;

    for (int i = 0; i < numIterations; i++) {
        // 生成随机数
        srand(time(NULL));
        for (int j = 0; j < dataSize; j++) {
            data[j] = rand() % 1000; // 生成范围在 0 到 999 之间的随机数
        }

        clock_t start = clock();
        sortFunction(data, dataSize); // 调用排序函数
        clock_t end = clock();

        total_time += (end - start);
    }

    double average_time = (double)total_time / numIterations / CLOCKS_PER_SEC;
    printf("排序函数平均用时：%f 秒\n", average_time);

    free(data);
}







































