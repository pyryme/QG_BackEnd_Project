#include"sort1.h"

void sortColors(int* nums, int numsSize) {
    int p0 = 0; // p0���ڴ��0��λ��
    int p2 = numsSize - 1; // p2���ڴ��2��λ��
    int i = 0; // �������������

    while (i <= p2) {
        if (nums[i] == 0) {// ��������0ʱ��������p0λ�õ�Ԫ�ؽ���

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
            // �״���Ϊ��������Ԫ�ػ�δ��飬����i���ܼ�1��������i�Ǵ��������ߵģ�һ��Ҫ��֤��߶���0������Ҫ��黻�������Ƿ���0��1 ������2��
        }
        else {
            // ��������1ʱ��ֱ�Ӽ����������
            i++;
        }
    }
}








////////////////�������˼·���ǿ�������ķ��࣬ͨ���ж�pivot�����ҵ������������жϵڼ�����С
// ���������еĻ��ֺ���
int partition(int* arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            // ���� arr[i] �� arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // ���� arr[i+1] �� arr[high]��ʹ�� pivot ������ȷ��λ��
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1; // ���� pivot ��λ��
}

// �ҵ������е� k С��Ԫ��
int findKthSmallest(int* arr, int low, int high, int k) {
    if (low <= high) {
        int pivotIndex = partition(arr, low, high);

        // ��� pivotIndex ���� k-1�����ҵ��� k С��Ԫ��
        if (pivotIndex == k - 1) {
            return arr[pivotIndex];
        }
        // ��� pivotIndex ���� k-1����������������в���
        else if (pivotIndex > k - 1) {
            return findKthSmallest(arr, low, pivotIndex - 1, k);
        }
        // ��� pivotIndex С�� k-1�������Ҳ��������в���
        else {
            return findKthSmallest(arr, pivotIndex + 1, high, k);
        }
    }
    // ��� low ���� high���򷵻� -1 ��ʾδ�ҵ�
    return -1;
}

