#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<Windows.h>
#include"matrix.h"
/*�ֲ�����ģ��*/
void xiaoyuan(float *p, int m,int n , int h);
int read(float * p, int m, int n);
float * copy(const float * p, int m, int n);
//��ֹ���ݱ��ƻ�
float * neicheng(float *p, int m, int n, float *q, int a, int b);
//ʵ�������ڳ�
float deleteline(const float * p, int m, int n, int i, int j);
//���� ȥ����i�е�J�к�Ĵ�������ʽ��ֵ


/*�ӿں���*/

void MenuPrint(void)
{
	system("title �������");
	system("color 70");
	/*
	0=��ɫ 1=��ɫ 2=��ɫ 3=����ɫ 4=��ɫ 5=��ɫ
	6=��ɫ 7=��ɫ 8=��ɫ 9=����ɫ
	A=����ɫ B=��ǳ��ɫ C=����ɫ
	D=����ɫ E=����ɫ F=����ɫ
	*/
	puts("\n\n");
	puts("              1.�������       2.�������ʽ");
	puts("              3.����ʽ��ֵ     4.�����");
	puts("              5.����˷�       6. ������� ");
	//puts("              7.Ax=0�Ľ�       8.Ax=b���ؽ�");
	puts("              7.ת��           8.��ӡ����");
	puts("              9.���          10.About Us         ");
	puts("              q.�˳�");
	puts("\n");
}

float * InitializeMatrix(int * m,int *n)//û��
{
	float * p;
	puts("Input you matrix:(m*n)");
	while (scanf("%d*%d", m, n) != 2){
		puts("�ǵ��м���Ǻ���!");
		fflush(stdin);
		puts("Input you matrix:(m*n)");
	}
	p = (float *)calloc((*m)*(*n), sizeof(float));
	return p;
}

int read(float * p, int m, int n)
{
	puts("input you matrix");
	puts("//ÿ��Ԫ��֮ǰ�ո������ÿ��֮���û��з�����");
	for (int i = 0; i < m; i++)
	{
		printf("��%d��: ", i + 1);
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
		puts("��淶���룡\n\a");
	puts("I got it\n");
}

void xiaoyuan(float *p, int m, int n, int h)
{
	float k;
	int z;
	for (size_t i = h+1; i < m; i++)
	{
		for (z = 0; z < n; z++)//�ҵ�z
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
//		for (int j = 0; j < n; j++)//ɨ����
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
			for (size_t j = h; j < m; j++)//ɨ���� �ҵ���������
			{
				if (p[(j)*n + h + z]!=0)//ȷ��������һ��
				{
					for (size_t i = 0; i < n; i++)//������
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
	for (size_t z = 0; z < m-1; z++)//���ÿһ�� �Ѿ�������һ��
	{
		for (size_t k = 0; k < n; k++)//���������ķ�����,������findѡ��
		{
			for (size_t j = 0; j < m - 1; j++)//�ҵ�������
			{
				if (p[(h + j + z)*n + h + k] != 0)
				{
					find = 1;
					for (size_t i = 0; i < n; i++)//������ı仯
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
//	for (size_t y = 0; y < m-1; y++)//�����У���
//	{
//		for (int z = 0; z < m - 1; z++)//�����еķ�����
//		{
//			if (p[(h+y)*n + h+z ] == 0)
//			{
//				for (int k = h; k < m; k++)//ɨ�������
//				{
//					if (p[(k)*m + h] != 0)
//					{
//						int j = k;
//						for (int i = 1; i < n; i++)//������
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
//����h�к���һ������
//�ҵ��ͽ��� ����1
//û�ҵ� ����0

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
		//printf("��%d��: ", i + 1);
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
		//printf("�������ʽ��ֵΪ%f\n", sum);
		//putchar('\n');
		return sum;
	}
	else{
		puts("����ɲ��Ƿ��󣬲��Ƿ���Ļ����㲻������ʽ��ֵ�ģ�");
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
	puts("   1.�ҳ�     2.���");
	scanf("%d", &z);
	ren = copy(p, m, n);
	if (z==1)
	{
		zhi = InitializeMatrix(&a, &b);
		ReadMatrix(zhi, a, b);
		if (a != n)
		{
			puts("�˲��ã�");
			return -1;
		}
		he = (float *)calloc((m)*(b), sizeof(float));//�ҳ�
		he = neicheng(ren, m, n, zhi, a, b);
		Print(he, m, b);
	}
	else if (z == 2)
	{
		zhi = InitializeMatrix(&a, &b);
		ReadMatrix(zhi, a, b);
		if (b != m)
		{
			puts("�˲��ã�");
			return -1;
		}
		he = (float *)calloc((n)*(a), sizeof(float));//�ҳ�
		he = neicheng(zhi, a, b, ren, m, n);
		Print(he, m, b);
	}
	else
		puts("����ȷѡ�����\n//�ѷ������˵�\a");
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
		puts("�����棡");
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
		printf("���\n");
	}
	else if (r==n)
	{
		printf("���\n");
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
		printf("\n\n%d��󷵻�\n",i);
		Sleep(1000);
	}
	system("cls");
	MenuPrint();
	//2017.1.1 ��ȡ���� �����б仯(1.0)
	//2017.1.2 ���о�����б仯 ����ֵ�ļ���(2.0)
	//2017.1.2 ���봦�� �ӿڵ���(3.0)
	//2017.1.2 ����˷�(4.0)
	//2017.1.2 �����(4.1)
	//2017.1.2 Rank(4.2)
	//2017.1.3 ת��(4.3)
	//2017.1.4 Ax=0
	//2017.2.8 �������Ҵ����ҵ����ϴ����bug~   
}