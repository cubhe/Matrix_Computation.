//源代码
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"matrix.h"

int main(){
	float * p = NULL;
	int m, n,he;
	MenuPrint();
	while (scanf("%d",&he)!=0&&he!='q')
	{
		switch (he)
		{
		case 1:
			p=InitializeMatrix(&m, &n);
			ReadMatrix(p, m, n);
			break;
		case 2:
		{
			float * q = Hangzuijian(p, m, n);
			Print(q, m, n);
			free(q);
			break;
		}
		case 3:
			printf("这个行列式的值为：%.3f\n",Det(p, m, n));
			break;
		case 4:
			Print(Reverse(p, m, n), m, n);
			break;
		case 5:
			Multiple(p, m, n);
			break;
		case 6:
			printf("矩阵的秩为：%d\n", Rank(p, m, n));
			break;
		/*case 7:
			GeneralSolution(p, m, n);
			break;
		case 8:
			puts("开发中....");
			break;*/  
		case 7:
			Print(Transposition(p,m,n), m, n);
			break;
		case 8:
			Print(p, m, n);
			break;
		case 9:
			system("cls");
			MenuPrint();
			break;
		case 10:
			AboutUs();
			break;
		default:
			puts("似乎...输错了呢");
			break;
		}
	}
	puts("さようなら");
	puts("熊本熊祝你早日脱单\n\a");
	free(p);
	system("pause");
	return 0;
}


//2017.1.1 读取矩阵 方阵行变化(1.0)
//2017.1.2 所有矩阵的行变化 行列值的计算(2.0)
//2017.1.2 输入处理 接口调整(3.0)
//2017.1.2 矩阵乘法(4.0)
//2017.1.2 逆矩阵(4.1)
//2017.1.2 Rank(4.2)
//2017.1.3 转置(4.3)
//2017.1.4 Ax=0

