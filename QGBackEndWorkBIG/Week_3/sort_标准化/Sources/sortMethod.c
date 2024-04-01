#include"sort.h"
//�����㷨��Ūһ��ͼ�λ��Ĺ��߽��ͺ󣬽�ÿһ���Ĳ������д��뻯�Ϳ�����

//��������
void insertsort(int* arr, unsigned int n)
{
	if (n < 2)return;//С��2�����Ͳ��������ˣ�

	int temp = 0;
	int i, j = 0;

	for(i = 1; i < n; i++){
		temp = arr[i];

		for (j = i - 1; j >= 0; j--) {
			if (arr[j] < temp) break;
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = temp;
	}
}

//�鲢���򣨵ݹ鷨������һ��������ѭ������
void _mergesort(int* arr, int* arrtmp,int start,int end) {
	if (start >= end )return;
	int mid = start + (end - start) / 2;
	
	int istart1 = start, iend1 = mid;
	int istart2 = mid + 1, iend2 = end;
	 
	//��ʼ�ֿ�
	_mergesort(arr, arrtmp, istart1, iend1);
	_mergesort(arr, arrtmp, istart2, iend2);


	//��ʼ���б��״���
	int i = start;

	while (istart1 <= iend1&&istart2<=iend2) {//������������������кϲ����������arrtmp��
		arrtmp[i++] = arr[istart1] < arr[istart2] ? arr[istart1++] : arr[istart2++];
	}

	while (istart1 <= iend1) {//���������ߵ�δ���е�ȫ���ƶ���������
		arrtmp[i++] = arr[istart1++];
	}
	while (istart2 <= iend2) {//���������ߵ�δ���е�ȫ���ƶ���������
		arrtmp[i++] = arr[istart2++];
	}

	memcpy(arr + start, arrtmp + start, (end - start + 1) * sizeof(int));
}

void mergesort(int* arr, unsigned int len) {
	if (len < 2)return;
	//int arrtmp[len];
	int* arrtmp = (int*)malloc(len *sizeof(int));
	_mergesort(arr, arrtmp, 0, len - 1);
}


//�������򣨵ݹ鷨��
void quicksort(int * arr, unsigned int n) {
	if (n < 2)return;

	int itmp = arr[0];
	int ileft = 0;
	int iright = n - 1;
	int imoving = 2;

	while (ileft < iright) {
		if (imoving == 2) {
			if (arr[iright] >= itmp) {
				iright--; continue;
			}
			arr[ileft] = arr[iright];
			ileft++;
			imoving = 1;
			continue;
		}

		if (imoving == 1) {
			if (arr[ileft] <= itmp) {
				ileft++; continue;
			}
			arr[iright] = arr[ileft];
			iright--;
			imoving = 2;
			continue;
		}
	}
		arr[ileft] = itmp;

		quicksort(arr, ileft);
		quicksort(arr + ileft + 1, n - ileft - 1);
	
}

//��������
int arrmax(int* arr, unsigned int len) {
	int i = 0;
	int imax = 0;
	for (i = 0; i < len; i++) {
		if (imax < arr[i]) imax = arr[i];
	}
	return imax;
}

void countsort(int* arr, unsigned int len) {
	if (len < 2)return;

	int imax = arrmax(arr, len);
	//int arrtmp[imax + 1];���ﱨ��˵ ���ʽ������г���ֵ���ǾͶ�̬����ռ�(ԭ����ָ�룬����Ҳ��ָ�룬��֪����ԭ���Ĵ�����û��ʲôӰ��)
	int *arrtmp = (int*)malloc((imax+1) * sizeof(int));
	if (arrtmp == NULL) {
		printf("�ڴ�����ʧ��\n");
		return 1;
	}

	memset(arrtmp, 0, (imax+1)*sizeof(int));

	int i, j, k = 0;
	for (i = 0; i < len; i++) arrtmp[arr[i]]++;

	i = 0;
	for (j = 0; j < imax + 1; j++) {
		for (k = 0; k < arrtmp[j]; k++) arr[i++] = j;
	}
}

//��������
void _radixsort(int* arr, unsigned int len, unsigned int exp) {
	int i=0;


	/*int result[len] = { 0 };*/
	int* result = (int*)malloc(len * sizeof(int));
	if (result == NULL) {
		printf("�ڴ�����ʧ��\n");
		return 1;
	}
	int buckets[10] = { 0 };

	for (i = 0; i < len; i++) 
		buckets[(arr[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		buckets[i] = buckets[i] + buckets[i - 1];
	


	for (i = len - 1; i >= 0; i--) {
		int iexp = (arr[i] / exp) % 10;
		result[buckets[iexp] - 1] = arr[i];
		buckets[iexp]--;
	}
	
	memcpy(arr, result, len * sizeof(int));
}

void radixsort(int* arr, unsigned int len) {
	int imax = arrmax(arr, len);
	int iexp;

	for (iexp = 1; imax / iexp > 0; iexp = iexp * 10) {
		_radixsort(arr, len, iexp);
	}
}








