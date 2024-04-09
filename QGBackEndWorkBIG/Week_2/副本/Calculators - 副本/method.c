#include"Calculators.h"
/*这种算法的理解：
 1.对于数字一直压进去，从符号的角度来进行，分两种
 （1）没有()的四则运算，则将/*分为一类，将-+分为一类，如果同一类就一直压。如果不同类就进行判断，
 如果后面将要压进去的+-碰上了优先级更加高的/*，则先进行/*的运算，这样最后只剩下+-了，用栈顶为#来进行一直运算
 （！！！！！但是代码还是有问题，只能进行二元的乘除，不能算a*b*c）
 （2）有（）：则碰到(就先压进去，（！！！！但是代码还是不完善，只能算括号里面有2个的，不能算2个以上的）
  碰到)就进行运算
 2.处理边缘
 最后面用#来判断是否输入完成
*/
int ln(char ch)//判断是否是符号
{
	if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '(' || ch == ')' || ch == 'o')
		return 1;
	else
		return 0;
}


//对两个数进行运算 
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
	return t;   //返回计算结果 
}



char Precede(char t, char ch)//比较优先级的大小 
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
	//算术表达式求值的算法优先算法，设OPTR和OPEN分别为运算符站和操作数栈
	InitStack(OPND);//初始化open栈!!!!!!!!!!好像因为这个vs比较严格，导致这个初始化完全没有用，第一个元素要自己手动加入
	InitStack(OPCH);//初始化OPTR栈
	//Push(OPCH, '#');//将表达式起始符“#”压入OPTR栈底
	//易错：在 C 语言中，你不能直接传递空指针给函数，并期望函数内部能够安全地处理它
	// 。你应该在调用函数之前确保指针不为空，或者在函数内部进行相应的错误处理。
	//这个编译器比较严格，所以第一个#就不用函数的进行压入
	//理解：指针要指到有申请空间的地方或者NULL
	StackNode* pt1 = (StackNode*)malloc(sizeof(StackNode));
	if (pt1 == NULL) {
		printf("p空间申请失败");
		return ERROR;
	}
	pt1->data = 'o';
	OPCH = pt1;


	StackNode* pt2 = (StackNode*)malloc(sizeof(StackNode));
	if (pt2 == NULL) {
		printf("p空间申请失败");
		return ERROR;
	}
	//scanf("%c", &ch);
	ch = getchar();
	pt2->data = ch;
	OPND = pt2;
	
	int time = 1;




	
	//scanf("%c", &ch);
	while (ch != 'o' || GetTop(OPCH) != 'o')//将表达式没有扫描完成的OPTR的栈顶元素不为“#”
	{
		if (!ln(ch))
		{	//------1------是数字不是符号执行这里
			if (time == 1) {//第一次手动了，这里就跳过
				ch = getchar();
				time++;
				continue;
			}
			else{
			//ch不是运算符则进OPND栈并读取下一个字符 
			Push(&OPND, ch);
			ch = getchar();
			}
			
		}
		else {//---------1----------是符号执行这里
				switch (Precede(GetTop(OPCH), ch))
	{			
				
				case'<'://<就压进去，>就弹出	
				{
					Push(&OPCH, ch);//当前字符ch压入OPTR栈，读入下一个字符
					//scanf("%c", &ch);
					ch = getchar();
					break; }

				case'>'://这个就是弹出的操作
				{
					if ( ch != 'o') {//-------2--------这里在没有)能处理。+-*/前是*/，
						Pop(&OPCH, &theta);
						Pop(&OPND, &a);
						Pop(&OPND, &b);
						a1 = a - '0';//将字符转化为十进制 
						b1 = b - '0';
						Push(&OPND, Operate(b1, theta, a1) + '0');//因为OPND里的数据为字符型，则再将计算结果转化为字符型
						Push(&OPCH, ch);
						ch=getchar();
					}  
					else {//-----------2------------这里是o,所以不再进行getchar()进行更新,并且不将最后的o压进去
						Pop(&OPCH, &theta);
						Pop(&OPND, &a);
						Pop(&OPND, &b);
						a1 = a - '0'; 
						b1 = b - '0';
						Push(&OPND, Operate(b1, theta, a1) + '0');
					}
					break;
				}

				case'='://-----------2---------------这个是专属的)
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
		time++;//这个就当作测试的一个标准吧，其实没什么用，只是记录循环了多少次

	}
	printf("计算结果为：%d", GetTop(OPND) - '0');//因为OPND里的数据为字符型，则再将其转化为整型			    
}





