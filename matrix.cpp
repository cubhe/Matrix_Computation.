#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<Windows.h>
#include"matrix.h"
/*局部函数模型*/
void xiaoyuan(float *p, int m,int n , int h);
int read(float * p, int m, int n);
float * copy(const float * p, int m, int n);
//防止数据被破坏
float * neicheng(float *p, int m, int n, float *q, int a, int b);
//实现向量内乘
float deleteline(const float * p, int m, int n, int i, int j);
//返回 去掉第i行第J列后的代数余子式的值


/*接口函数*/

void MenuPrint(void)
{
	system("title 矩阵计算");
	system("color 70");
	/*
	0=黑色 1=蓝色 2=绿色 3=湖蓝色 4=红色 5=紫色
	6=黄色 7=白色 8=灰色 9=淡蓝色
	A=淡绿色 B=淡浅绿色 C=淡红色
	D=淡紫色 E=淡黄色 F=亮白色
	*/
	puts("\n\n");
	puts("              1.输入矩阵       2.行最简形式");
	puts("              3.行列式的值     4.逆矩阵");
	puts("              5.矩阵乘法       6. 矩阵的秩 ");
	//puts("              7.Ax=0的解       8.Ax=b的特解");
	puts("              7.转置           8.打印矩阵");
	puts("              9.清空          10.About Us         ");
	puts("              q.退出");
	puts("\n");
}

float * InitializeMatrix(int * m,int *n)//没用
{
	float * p;
	puts("Input you matrix:(m*n)");
	while (scanf("%d*%d", m, n) != 2){
		puts("记得中间的星号噢!");
		fflush(stdin);
		puts("Input you matrix:(m*n)");
	}
	p = (float *)calloc((*m)*(*n), sizeof(float));
	return p;
}

int read(float * p, int m, int n)
{
	puts("input you matrix");
	puts("//每个元素之前空格隔开，每行之间用换行符隔开");
	for (int i = 0; i < m; i++)
	{
		printf("第%d行: ", i + 1);
		for (int j = 0; j < n; j++)
			if (scanf("%f", &p[i*n + j]) == 0)
			{
				fflush(stdin);
				return -1;
			}
	}
	putchar('\n');
	return 1;
}

void ReadMatrix(float * p, int m, int n) 
{
	while (read(p, m, n) == -1)
		puts("请规范输入！\n\a");
	puts("I got it\n");
}

void xiaoyuan(float *p, int m, int n, int h)
{
	float k;
	int z;
	for (size_t i = h+1; i < m; i++)
	{
		for (z = 0; z < n; z++)//找到z
		{
			if (p[h*n + h + z])
				break;
			if (z == m - 1)
				return;
		}
		k = p[i*n + h + z] / p[h*n + h + z];
		for (size_t j = h; j < n; j++)
		{
			p[i*n + j] -= p[h*n + j]*k;
		}
	}
}
//for (size_t z = h; z < n; z++)
//	//0 0 1 1
//	//0 0 2 3
//{
//	if (p[(i)*n + z]&&p[(h)*n + z])
//	{
//		//k = p[(i)*n + z] / p[(h)*n + z];
//		//k = p[(i)*n + h] / p[(h)*n + h];
//		for (int j = 0; j < n; j++)//扫描行
//			p[(i)* n + j] -= p[(h)*n + j] * k;
//		break;
//	}
//}

void  hangjiaohuan(float * p, int m, int n, int h)
{
	for (size_t z = 0; z < n; z++)
	{
		if (p[h*n + z + h] == 0)
		{
			for (size_t j = h; j < m; j++)//扫描行 找到交换的行
			{
				if (p[(j)*n + h + z]!=0)//确定交换哪一行
				{
					for (size_t i = 0; i < n; i++)//交换行
					{
						float temp = p[h*n + i];
						p[h*n + i] = p[j*n + i];
						p[j*n + i] = temp;
					}
					break;
				}
			}
		}
		else
			break;
	}
}
/*int beishu, find = 0;
	for (size_t z = 0; z < m-1; z++)//检查每一行 把矩阵整理一遍
	{
		for (size_t k = 0; k < n; k++)//检查行里面的非零项,依赖于find选项
		{
			for (size_t j = 0; j < m - 1; j++)//找到非零行
			{
				if (p[(h + j + z)*n + h + k] != 0)
				{
					find = 1;
					for (size_t i = 0; i < n; i++)//行里面的变化
					{
						float temp = p[h*n + h + i];
						p[(h + z)*n + h + i] = p[(h + j + z)*n + h + i];
						p[(h + j + z)*n + h + i] = temp;
					}
				}
			}
			if (find)
				break;
		}
	}*/
//	for (size_t y = 0; y < m-1; y++)//所有行！！
//	{
//		for (int z = 0; z < m - 1; z++)//检测该行的非零项
//		{
//			if (p[(h+y)*n + h+z ] == 0)
//			{
//				for (int k = h; k < m; k++)//扫描非零行
//				{
//					if (p[(k)*m + h] != 0)
//					{
//						int j = k;
//						for (int i = 1; i < n; i++)//交换行
//						{
//							float temp = p[h*n + i];
//							p[h*m + i] = p[j*n + i];
//							p[j*m + i] = temp;
//						}
//						//float bei = p[(h + 1)*n + h + i] / p[(h)*n + h + i];
//						//xiaoyuan(p, m, n, h,bei);
//					}
//				}
//				break;
//			}
//		}
//		xiaoyuan(p, m, n, h,bei);
//	}
//}
//交换h行和下一非零行
//找到就交换 返回1
//没找到 返回0

float * Hangzuijian(const float *p, int m, int n) 
{
	float * q = copy(p, m, n);
	for (int h = 0; h < m-1 ; h++){
		hangjiaohuan(q, m, n, h);
		xiaoyuan(q, m, n, h);
	}
	return q;
}

void Print(const float *p, int m, int n)
{
	if (p == NULL)
		return;
	putchar('\n');
	for (int i = 0; i < m; i++)
	{
		//printf("第%d行: ", i + 1);
		for (int j = 0; j < n; j++)
		{
			printf("%2.2f ", p[i*n + j]);
		}
		printf("\n");
	}
	putchar('\n');
	//printf("\a");
}

float Det(const float * p, int m, int n)
{
	float sum = 1;
	float * q = copy(p, m, n);
	if (m == n){
		q=Hangzuijian(q, m, n);
		for (int i = 0; i < m; i++)
			sum *= q[i*n + i];
		//printf("这个行列式的值为%f\n", sum);
		//putchar('\n');
		return sum;
	}
	else{
		puts("这个可不是方阵，不是方阵的话是算不好行列式的值的！");
		putchar('\n');
		return 0.;
	}
}

int Rank(const float *p, int m, int n)
{
	int count = 0;
	float * q = Hangzuijian(p, m, n);
	for (size_t i = 0; i < m; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			if (q[i*m + j] != 0)
			{
				count++;
				break;
			}
		}
	}
	return count;
}
 
int Multiple(const float * p, int m, int n)
{
	int a, b, z;
	float *he=NULL,* ren = NULL,*zhi=NULL;
	puts("   1.右乘     2.左乘");
	scanf("%d", &z);
	ren = copy(p, m, n);
	if (z==1)
	{
		zhi = InitializeMatrix(&a, &b);
		ReadMatrix(zhi, a, b);
		if (a != n)
		{
			puts("乘不好！");
			return -1;
		}
		he = (float *)calloc((m)*(b), sizeof(float));//右乘
		he = neicheng(ren, m, n, zhi, a, b);
		Print(he, m, b);
	}
	else if (z == 2)
	{
		zhi = InitializeMatrix(&a, &b);
		ReadMatrix(zhi, a, b);
		if (b != m)
		{
			puts("乘不好！");
			return -1;
		}
		he = (float *)calloc((n)*(a), sizeof(float));//右乘
		he = neicheng(zhi, a, b, ren, m, n);
		Print(he, m, b);
	}
	else
		puts("请正确选择操作\n//已返回主菜单\a");
	return 0;
}

float * neicheng(float *p, int m, int n, float *q, int a, int b)
{
	float * he = (float *)calloc(m*b, sizeof(float));
	he[0] = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < b; j++)
		{
			for (size_t k = 0; k < n; k++)
			{
				he[i*b + j] += p[i*b + k] * q[k*b + j];
			}
		}
	}
	return he;
}

float * copy(const float * p, int m, int n)
{
	float * he = NULL;
	he = (float *)calloc(m*n, sizeof(float));
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			he[i*n + j] = p[i*n + j];
		}
	}
	return he;
}

float * Reverse(const float * p, int m, int n)
{
	if (m != n || Det(p, m, n) == 0)
	{
		puts("不可逆！");
		return 0;
	}
	float * he = (float *)calloc(m*n, sizeof(float));
	float sum = Det(p, m, n);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			//printf("%d %d\n", i, j);
			he[i*n + j] = pow((double)(-1.), i + j)*deleteline(p, m, n, i, j) / sum;
		}
	}
	//Print(he, m, n);
	return Transposition(he, m, n);
}

float deleteline(const float * p, int m, int n, int i, int j)
{
	float * q = copy(p, m, n);
	for (size_t z = 0; z < m; z++)
		for (size_t y = j; y < m-1; y++)
			q[z*m + y] = q[z*m + y + 1];
	for (size_t z = 0; z < m - 1; z++)
		for (size_t y = i; y < m-1; y++)
			q[y*(m-1) + z] = q[(y + 1) * m + z];
	//Print(q, m-1, n -1);
	return Det(q, m - 1, n - 1);
} 

float * Transposition(const float * p, int m, int n){
	float * q = (float *)calloc(n*m, sizeof(float));
	for (size_t i = 0; i < m; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			q[j*m + i] = p[i*n + j];
		}
	}
	return q;
}

void GeneralSolution(const float * p, int m, int n)
{
	float *q = Hangzuijian(p, m, n);
	int r = Rank(q, m, n);
	if (r<m)
	{
		printf("零解\n");
	}
	else if (r==n)
	{
		printf("零解\n");
	}
	/*else
	{
		int h = n - r;
		float * x = (float *)calloc(n*h, sizeof(float));
		//for (size_t y = 0; y < h; y++)
		{
			x[n - 1] = 1;
			for (int z = n-2; z>= 0; z--){
				for (size_t r = z,int l=m-1; r < n; r++,l--){
					x[z] -= x[r]*q[(l)*n+r];
				}
			}
		}
		Print(Transposition(x, n, h),n,h);
	}*/
}

void AboutUs(void)
{
	int i;
	for (i = 5; i >0; i--)
	{
		system("cls");
		puts("\n\n");
		puts("If you have any question,please contact us.");
		puts("             herenzhie@gmail.com");
		printf("\n\n%d秒后返回\n",i);
		Sleep(1000);
	}
	system("cls");
	MenuPrint();
	//2017.1.1 读取矩阵 方阵行变化(1.0)
	//2017.1.2 所有矩阵的行变化 行列值的计算(2.0)
	//2017.1.2 输入处理 接口调整(3.0)
	//2017.1.2 矩阵乘法(4.0)
	//2017.1.2 逆矩阵(4.1)
	//2017.1.2 Rank(4.2)
	//2017.1.3 转置(4.3)
	//2017.1.4 Ax=0
	//2017.2.8 躺在仙桃床上找到以上代码的bug~   
}