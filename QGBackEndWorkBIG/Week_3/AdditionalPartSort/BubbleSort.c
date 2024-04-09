#include"AdditionnalPartSort.h"



//---------------ð��������Ż�1
//����˼�룺��һ�α����У����û�з���Ԫ�ؽ���������������Ѿ����򣬿�����ǰ����������̡�
void bubbleSort1(int arr[], int n) {
    int i, j=0;
    int change=0; // ���ڱ�־�Ƿ��н�������

    for (i = 0; i < n - 1; i++) {
        change = 0;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                change = 1; //�����Ϊ�Ƿ���иı�ı�־
            }
        }
        // ���û�н���������˵�������Ѿ�������ǰ����
        if (change==0) break;
           
    }
}


//-----------------ð��������Ż�2
//����˼�룺��ÿһ�������У�ͨ����¼��һ�ν�����λ�ã�����ȷ����������ķ�Χ���Ӷ�������ѭ���ı���������(���Ż�1�Ļ����ϵ��Ż�)
void bubbleSort2(int arr[], int n) {
    int i, j=0;
    int FinalChange = n - 1; //���ı��λ�ã�������λ��
    int change = 0;

    for (i = 0; i < n - 1; i++) {
        int CurrentChange = 0; // ��ǰ����������λ��,������������һ����������¼j����Ϊ���һ���жϵ�ʱ���ִ��j=0�������޷���forѭ��֮������j��

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

//-----------------ð��������Ż�3
//����˼�룺��1��2�Ļ����Ͻ����Ż���2���Ż���ʡȥβ���Ѿ���������䣬��������ټ���ʡȥ��ͷ�Ѿ����������
void bubbleSort3(int arr[], int n) {
    int i, j=0;
    int FinalIndex = n - 1; // ���һ�ν�����λ��
    int StartIndex = 0; // ��һ�������λ��

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



