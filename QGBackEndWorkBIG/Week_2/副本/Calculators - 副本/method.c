#include"Calculators.h"
/*�����㷨����⣺
 1.��������һֱѹ��ȥ���ӷ��ŵĽǶ������У�������
 ��1��û��()���������㣬��/*��Ϊһ�࣬��-+��Ϊһ�࣬���ͬһ���һֱѹ�������ͬ��ͽ����жϣ�
 ������潫Ҫѹ��ȥ��+-���������ȼ����Ӹߵ�/*�����Ƚ���/*�����㣬�������ֻʣ��+-�ˣ���ջ��Ϊ#������һֱ����
 ���������������Ǵ��뻹�������⣬ֻ�ܽ��ж�Ԫ�ĳ˳���������a*b*c��
 ��2���У�����������(����ѹ��ȥ���������������Ǵ��뻹�ǲ����ƣ�ֻ��������������2���ģ�������2�����ϵģ�
  ����)�ͽ�������
 2.�����Ե
 �������#���ж��Ƿ��������
*/
int ln(char ch)//�ж��Ƿ��Ƿ���
{
	if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '(' || ch == ')' || ch == 'o')
		return 1;
	else
		return 0;
}


//���������������� 
int Operate(int a, char c, int b)
{
	int t=0;
	switch (c)
	{
	case '+':
		t = a + b; break;
	case '-':
		t = a - b; break;
	case '*':
		t = a * b; break;
	case '/':
		t = a / b; break;
	}
	return t;   //���ؼ����� 
}



char Precede(char t, char ch)//�Ƚ����ȼ��Ĵ�С 
{
	switch (ch)
	{
	case '(':
	{
		return '<';
		break; }
	case '*':
	{
		if (t == '+' || t == '(' || t == '-' || t == 'o')
			return '<';
		else
			return '>';
		break; }
	case '/':
	{
		if (t == '+' || t == '(' || t == '-' || t == 'o')
			return '<';
		else
			return '>';
		break; }

	case '+':
	{
		if (t == 'o' || t == '(')
			return '<';
		else
			return '>';
		break; }
	case '-':
	{
		if (t == 'o' || t == '(')
			return '<';
		else
			return '>';
		break; }
	case ')':
	{
		if (t != '(')
			return '=';
		break; }
	case 'o':
	{
		if (t != 'o')
			return '>';
		break; }

	}
}






int logicMain()
{
	char ch, theta, a, b='a';
	int a1, b1, t=0;
	//�������ʽ��ֵ���㷨�����㷨����OPTR��OPEN�ֱ�Ϊ�����վ�Ͳ�����ջ
	InitStack(OPND);//��ʼ��openջ!!!!!!!!!!������Ϊ���vs�Ƚ��ϸ񣬵��������ʼ����ȫû���ã���һ��Ԫ��Ҫ�Լ��ֶ�����
	InitStack(OPCH);//��ʼ��OPTRջ
	//Push(OPCH, '#');//�����ʽ��ʼ����#��ѹ��OPTRջ��
	//�״��� C �����У��㲻��ֱ�Ӵ��ݿ�ָ��������������������ڲ��ܹ���ȫ�ش�����
	// ����Ӧ���ڵ��ú���֮ǰȷ��ָ�벻Ϊ�գ������ں����ڲ�������Ӧ�Ĵ�����
	//����������Ƚ��ϸ����Ե�һ��#�Ͳ��ú����Ľ���ѹ��
	//��⣺ָ��Ҫָ��������ռ�ĵط�����NULL
	StackNode* pt1 = (StackNode*)malloc(sizeof(StackNode));
	if (pt1 == NULL) {
		printf("p�ռ�����ʧ��");
		return ERROR;
	}
	pt1->data = 'o';
	OPCH = pt1;


	StackNode* pt2 = (StackNode*)malloc(sizeof(StackNode));
	if (pt2 == NULL) {
		printf("p�ռ�����ʧ��");
		return ERROR;
	}
	//scanf("%c", &ch);
	ch = getchar();
	pt2->data = ch;
	OPND = pt2;
	
	int time = 1;




	
	//scanf("%c", &ch);
	while (ch != 'o' || GetTop(OPCH) != 'o')//�����ʽû��ɨ����ɵ�OPTR��ջ��Ԫ�ز�Ϊ��#��
	{
		if (!ln(ch))
		{	//------1------�����ֲ��Ƿ���ִ������
			if (time == 1) {//��һ���ֶ��ˣ����������
				ch = getchar();
				time++;
				continue;
			}
			else{
			//ch������������OPNDջ����ȡ��һ���ַ� 
			Push(&OPND, ch);
			ch = getchar();
			}
			
		}
		else {//---------1----------�Ƿ���ִ������
				switch (Precede(GetTop(OPCH), ch))
	{			
				
				case'<'://<��ѹ��ȥ��>�͵���	
				{
					Push(&OPCH, ch);//��ǰ�ַ�chѹ��OPTRջ��������һ���ַ�
					//scanf("%c", &ch);
					ch = getchar();
					break; }

				case'>'://������ǵ����Ĳ���
				{
					if ( ch != 'o') {//-------2--------������û��)�ܴ���+-*/ǰ��*/��
						Pop(&OPCH, &theta);
						Pop(&OPND, &a);
						Pop(&OPND, &b);
						a1 = a - '0';//���ַ�ת��Ϊʮ���� 
						b1 = b - '0';
						Push(&OPND, Operate(b1, theta, a1) + '0');//��ΪOPND�������Ϊ�ַ��ͣ����ٽ�������ת��Ϊ�ַ���
						Push(&OPCH, ch);
						ch=getchar();
					}  
					else {//-----------2------------������o,���Բ��ٽ���getchar()���и���,���Ҳ�������oѹ��ȥ
						Pop(&OPCH, &theta);
						Pop(&OPND, &a);
						Pop(&OPND, &b);
						a1 = a - '0'; 
						b1 = b - '0';
						Push(&OPND, Operate(b1, theta, a1) + '0');
					}
					break;
				}

				case'='://-----------2---------------�����ר����)
				{
					char temp;
					Pop(&OPND, &a);
					Pop(&OPND, &b);
					Pop(&OPCH, &theta);
					a1 = a - '0';
					b1 = b - '0';
					Push(&OPND, Operate(b1, theta, a1) + '0');
					//Pop(&OPCH, &temp);
					//ch = getchar();
					//scanf("%c", &ch);
					break; }
	}
			//}
	}
		time++;//����͵������Ե�һ����׼�ɣ���ʵûʲô�ã�ֻ�Ǽ�¼ѭ���˶��ٴ�

	}
	printf("������Ϊ��%d", GetTop(OPND) - '0');//��ΪOPND�������Ϊ�ַ��ͣ����ٽ���ת��Ϊ����			    
}





