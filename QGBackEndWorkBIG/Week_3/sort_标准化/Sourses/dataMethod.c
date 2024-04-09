#include"sort.h"

// ����ָ������������������浽�ļ�
void generateTestData(const char* filename, int count) {
    FILE* fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("�޷����ļ� %s\n", filename);
        return;
    }

    srand(time(NULL));
    for (int i = 0; i < count; i++) {
        fprintf(fp, "%d\n", rand() % 10000); // ���ɷ�Χ�� 0 �� 9999 ֮��������
    }

    fclose(fp);
    printf("�����ɲ����� %d ����������ļ� %s\n", count, filename);
}

/*int main() {
    generateTestData("test_data.txt", 10000); // ���� 10000 ����������ɸ�����Ҫ�޸�����
    return 0;
}
*/
// ��ȡ�ļ��е�����
int* readDataFromFile(const char* filename, int count) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("�޷����ļ� %s\n", filename);
        return NULL;
    }

    int* data = (int*)malloc(count * sizeof(int));
    if (data == NULL) {
        printf("�ڴ�����ʧ��\n");
        fclose(fp);
        return NULL;
    }

    for (int i = 0; i < count; i++) {
        if (fscanf(fp, "%d", &data[i]) != 1) {
            printf("��ȡ�ļ�ʧ��\n");
            free(data);
            fclose(fp);
            return NULL;
        }
    }

    fclose(fp);
    return data;
}

// ��ӡ����������
void printSortedArray(int* arr, int count) {
    for (int i = 0; i < count; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/*
int main() {

    generateTestData("test_data.txt", 10000); // ���� 10000 ����������ɸ�����Ҫ�޸�����
 


    const char* filename = "test_data.txt";
    int count = 10000; // ��Ҫ�����ɲ�������ʱ������ƥ��
    int* data = readDataFromFile(filename, count);
    if (data == NULL) {
        return 1;
    }

    // ������������ data ��������
    // �����������������������磺
     insertsort(data, count);
    // mergesort(data, count);
    // quicksort(data, count);
    // countsort(data, count);
    // radixsort(data, count);

    // ��ӡ���������飨��������֤��
    printSortedArray(data, count);

    // �ͷŶ�̬������ڴ�
    free(data);

    return 0;
}
*/






///////////////////////////////////////////////
// ����ָ�������������
void generateRandomNumbers(int* arr, int count) {
    srand(time(NULL));
    for (int i = 0; i < count; i++) {
        arr[i] = rand() % 1000; // ���ɷ�Χ�� 0 �� 999 ֮��������
    }
}

// ���������������ܣ�����3�������������ʱ��
void evaluateSortingAlgorithm(void (*sortFunction)(int*, unsigned int), int count) {
    int* data = (int*)malloc(count * sizeof(int));
    if (data == NULL) {
        printf("�ڴ�����ʧ��\n");
        return;
    }

    generateRandomNumbers(data, count);//������Ըĳɶ�ȡ�ļ��е����ݣ�����������������

    clock_t start = clock();
    sortFunction(data, count);
    clock_t end = clock();
    double elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;

    printf("��������%d��������ʱ��%f ��\n", count, elapsed_time);

    free(data);
}


/*
////////////////////////////////////////////////
int main() {

    generateTestData("test_data.txt", 10000); // ���� 10000 ����������ɸ�����Ҫ�޸�����



    const char* filename = "test_data.txt";
    int count = 10000; // ��Ҫ�����ɲ�������ʱ������ƥ��
    int* data = readDataFromFile(filename, count);
    if (data == NULL) {
        return 1;
    }

    // ������������ data ��������
    // �����������������������磺
    insertsort(data, count);
    // mergesort(data, count);
    // quicksort(data, count);
    // countsort(data, count);
    // radixsort(data, count);

    // ��ӡ���������飨��������֤��
    printSortedArray(data, count);

    // �ͷŶ�̬������ڴ�
    free(data);

   // return 0;




    //////////////////////////////////////////////////


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

    return 0;
}*/



// ���������������ܣ�����100����ͬ������100k�ε�ʱ��
void evaluateSortingAlgorithmSmallData(void (*sortFunction)(int*, unsigned int), int dataSize, int numIterations) {
    int* data = (int*)malloc(dataSize * sizeof(int));
    if (data == NULL) {
        printf("�ڴ�����ʧ��\n");
        return;
    }

    clock_t total_time = 0;

    for (int i = 0; i < numIterations; i++) {
        // ���������
        srand(time(NULL));
        for (int j = 0; j < dataSize; j++) {
            data[j] = rand() % 1000; // ���ɷ�Χ�� 0 �� 999 ֮��������
        }

        clock_t start = clock();
        sortFunction(data, dataSize); // ����������
        clock_t end = clock();

        total_time += (end - start);
    }

    double average_time = (double)total_time / numIterations / CLOCKS_PER_SEC;
    printf("������ƽ����ʱ��%f ��\n", average_time);

    free(data);
}







































