#include"sort.h"

int main() {
    printf("Ŀ��3����дһ����Ҫ�����ɲ������ݣ������浽�ļ��ĳ��򣬺�һ���ܰ�Ҫ���ȡ�ļ��е����ݣ�����������������������ĳ���\n");
//////////////////////////////////////Ŀ��3�Ĵ���
    //��������1���뵽�ļ���
    generateTestData("test_data10k.txt", 10000); // ���� 10000 ����������ɸ�����Ҫ�޸�����
    generateTestData("test_data50k.txt", 50000);
    generateTestData("test_data200k.txt", 200000);


    //��ȡ����1,2,3.
    const char* filename1 = "test_data10k.txt";
    const char* filename2 = "test_data50k.txt";
    const char* filename3 = "test_data200k.txt";
    int count1 = 10000; // ��Ҫ�����ɲ�������ʱ������ƥ��
    int count2 = 50000;
    int count3 = 200000;
    int* data1 = readDataFromFile(filename1, count1);
    int* data2 = readDataFromFile(filename2, count2);
    int* data3 = readDataFromFile(filename3, count3);
    if (data1 == NULL) {
        return 1;
    }

    // ������������ data ��������.���printf���Բ���
    // �����������������������磺
    //insertsort(data1, count1);
    //mergesort(data1, count1);
    //quicksort(data1, count1);
    //countsort(data1, count1);
    //radixsort(data1, count1);

    // ��ӡ���������飨��������֤����������Ƿ��������У�
    //printSortedArray(data1, count1);
///////////////////////////////////////// ������Ŀ��3�Ĵ���

    printf("\n\n");
    printf("Ŀ��1����д���Գ�����������������ڲ�ͬ�Ĵ��������µ���ʱ����������Σ�10000��50000��200000)\n");

 ////////////////////////������Ŀ��1�Ĵ���
    int sizes[] = { 10000, 50000, 200000 }; // ���Բ�ͬ��С�����ݼ�
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
        printf("������������%d\n", i + 1);
        for (int j = 0; j < num_sizes; j++) {
            int size = sizes[j];
            evaluateSortingAlgorithm(sortFunction, size);
        }
        printf("\n");
    }

/////////////////////////////////������Ŀ��2�Ĵ���

    // ���Բ���
    int dataSize = 100; // ���ݴ�С
    int numIterations = 100000; // ��������

    // ����������
    /*void (*sorting_algorithms[])(int*, unsigned int) = {
        insertsort,
        mergesort,
        quicksort,
        countsort,
        radixsort
    };*/
    int num_algorithms_2 = sizeof(sorting_algorithms) / sizeof(sorting_algorithms[0]);

    for (int i = 0; i < num_algorithms_2; i++) {
        printf("������������%d\n", i + 1);
        evaluateSortingAlgorithmSmallData(sorting_algorithms[i], dataSize, numIterations);
        printf("\n");
    }


///////////////////////////////////////

    // �ͷŶ�̬������ڴ�
    free(data1);
    free(data2);
    free(data3);
    return 0;

}

