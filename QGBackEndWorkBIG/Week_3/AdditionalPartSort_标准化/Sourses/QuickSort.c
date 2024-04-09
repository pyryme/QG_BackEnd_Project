#include"AdditionnalPartSort.h"


//一///////////////////////////////选做1：实现快排非递归版(QuickSort)
void swap(int* a, int* b) {// 交换数组中两个元素的位置
    int temp = *a;
    *a = *b;
    *b = temp;
}


int partition(int arr[], int low, int high) {// 快速排序中的划分操作
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


void NonRecursiveQuickSort(int arr[], int l, int h) {// 非递归实现的快速排序
    // 创建一个辅助栈
    //int stack[h - l + 1];
    int* stack = (int*)malloc((h - l + 1) * sizeof(int));//？？？？？？？/这里好像会溢出


    
    int top = -1;// 初始化栈的顶部
    stack[++top] = l;// 将初始的low和high压入栈，目的是为了配合下面的while操作，进行边缘处理
    stack[++top] = h;

    while (top >= 0) {
        // 这里弹出high和low
        h = stack[top--];
        l = stack[top--];

        // 将数组划分为两部分，并将划分后的两部分分别压入栈中
        int p = partition(arr, l, h);

        if (p - 1 > l) {// -------------1-------------如果划分后左侧部分有元素，则压入栈中
            stack[++top] = l;
            stack[++top] = p - 1;
        }

       
        if (p + 1 < h) { //--------------1------------- 如果划分后右侧部分有元素，则压入栈中
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



//二///////////////////////////快速排序的随机选择基准元素的优化
// 随机选择基准元素
int RandomPartition(int arr[], int low, int high) {
    srand(time(NULL)); // 设置随机种子
    int random_index = low + rand() % (high - low + 1); //这个是随机生成元素的核心代码
    swap(&arr[random_index], &arr[high]); // 将随机选择的元素与最后一个元素交换之后，选取最后一个元素作为基准，就是选择了一个随机的作为基准元素
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



//三//////////////////////////////////////// 三枢轴法？？？？？？？？？？？？？？？？？？？？？？？？？？？这个真的不知道代码什么意思，画图理解都很模糊，后续再看看
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

int partition2(int arr[], int low, int high) {// 划分数组，并返回划分后的中枢值的位置
    triMedian(arr, low, high); // 三枢轴优化
    int pivot = arr[low]; // 使用第一个元素作为中枢值
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

void TriQuickSort(int arr[], int low, int high) {// 快速排序的递归函数
    if (low < high) {
        int pivotIndex = partition2(arr, low, high);
        TriQuickSort(arr, low, pivotIndex - 1);
        TriQuickSort(arr, pivotIndex + 1, high);
    }
}
