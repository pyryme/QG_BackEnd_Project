#include"AdditionnalPartSort.h"


//һ///////////////////////////////ѡ��1��ʵ�ֿ��ŷǵݹ��(QuickSort)
void swap(int* a, int* b) {// ��������������Ԫ�ص�λ��
    int temp = *a;
    *a = *b;
    *b = temp;
}


int partition(int arr[], int low, int high) {// ���������еĻ��ֲ���
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}


void NonRecursiveQuickSort(int arr[], int l, int h) {// �ǵݹ�ʵ�ֵĿ�������
    // ����һ������ջ
    //int stack[h - l + 1];
    int* stack = (int*)malloc((h - l + 1) * sizeof(int));//��������������/�����������


    
    int top = -1;// ��ʼ��ջ�Ķ���
    stack[++top] = l;// ����ʼ��low��highѹ��ջ��Ŀ����Ϊ����������while���������б�Ե����
    stack[++top] = h;

    while (top >= 0) {
        // ���ﵯ��high��low
        h = stack[top--];
        l = stack[top--];

        // �����黮��Ϊ�����֣��������ֺ�������ֱַ�ѹ��ջ��
        int p = partition(arr, l, h);

        if (p - 1 > l) {// -------------1-------------������ֺ���ಿ����Ԫ�أ���ѹ��ջ��
            stack[++top] = l;
            stack[++top] = p - 1;
        }

       
        if (p + 1 < h) { //--------------1------------- ������ֺ��Ҳಿ����Ԫ�أ���ѹ��ջ��
            stack[++top] = p + 1;
            stack[++top] = h;
        }
    }
    free(stack);
}


void printArray(int arr[], int size) {
    for (int i = 0; i < size; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}



//��///////////////////////////������������ѡ���׼Ԫ�ص��Ż�
// ���ѡ���׼Ԫ��
int RandomPartition(int arr[], int low, int high) {
    srand(time(NULL)); // �����������
    int random_index = low + rand() % (high - low + 1); //������������Ԫ�صĺ��Ĵ���
    swap(&arr[random_index], &arr[high]); // �����ѡ���Ԫ�������һ��Ԫ�ؽ���֮��ѡȡ���һ��Ԫ����Ϊ��׼������ѡ����һ���������Ϊ��׼Ԫ��
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void RandomQuickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = RandomPartition(arr, low, high);

        RandomQuickSort(arr, low, pi - 1);
        RandomQuickSort(arr, pi + 1, high);
    }
}



//��//////////////////////////////////////// �����ᷨ�����������������������������������������������������������Ĳ�֪������ʲô��˼����ͼ��ⶼ��ģ���������ٿ���
void triMedian(int arr[], int low, int high) {
    int mid = low + (high - low) / 2;
    if (arr[low] > arr[mid])
        swap(&arr[low], &arr[mid]);
    if (arr[low] > arr[high])
        swap(&arr[low], &arr[high]);
    if (arr[mid] > arr[high])
        swap(&arr[mid], &arr[high]);
    swap(&arr[mid], &arr[low + 1]);
}

int partition2(int arr[], int low, int high) {// �������飬�����ػ��ֺ������ֵ��λ��
    triMedian(arr, low, high); // �������Ż�
    int pivot = arr[low]; // ʹ�õ�һ��Ԫ����Ϊ����ֵ
    int left = low + 1;
    int right = high;

    while (1) {
        while (left <= right && arr[left] <= pivot)
            left++;
        while (left <= right && arr[right] > pivot)
            right--;
        if (left >= right)
            break;
        swap(&arr[left], &arr[right]);
    }
    swap(&arr[low], &arr[right]);
    return right;
}

void TriQuickSort(int arr[], int low, int high) {// ��������ĵݹ麯��
    if (low < high) {
        int pivotIndex = partition2(arr, low, high);
        TriQuickSort(arr, low, pivotIndex - 1);
        TriQuickSort(arr, pivotIndex + 1, high);
    }
}
