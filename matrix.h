/*这是矩阵计算器的头文件*/


#ifndef MATRIX_H_
#define MATRIX_H_

void MenuPrint(void);
//打印菜单

float * InitializeMatrix(int *m,int *n);
//操作：初始化一个可变数组
//操作前：p为空
//操作后：p指向一个数组

void ReadMatrix(float * p, int m, int n);
//操作：读入一个矩阵

float * Hangzuijian(const float *p, int m, int n);
//操作：使矩阵化为行最简
//操作前：p指向一个二维数组
//操作后：该数组变为行最简

int Rank(const float *p, int m, int n);
//操作：返回矩阵的秩
//操作前：p指向一个矩阵
//操作后：返回这个矩阵的秩

void Print(const float *p, int m, int n);
//操作：打印一个矩阵
//操作前：p指向一个二维数组
//操作后：打印p指向的数组

float Det(const float * p, int m, int n);
//操作：计算行列式的值
//操作前：p指向一个矩阵
//操作后：如果该矩阵是方阵，返回行列式的值
//            否则报错并提示，返回0

int Multiple(const float * p, int m, int n);
//操作：输入第二个矩阵，使两个矩阵相乘
//操作前：p是已初始化的矩阵
//操作后：输出相乘后的矩阵

float * Reverse(const float * p, int m, int n);
//操作：输入一个方阵，打印这个方阵的逆矩阵
//操作前：p指向一个方阵
//操作后：返回一个float类型的指针，指针指向该方阵的逆矩阵

void GeneralSolution(const float * p, int m, int n);
//操作：输入一个矩阵 ,求Ax=0的解
//操作前：p指向一个矩阵
//操作后：如果有解输出这个解或者通解
//            如果无解 提示无解 返回

void SpecialSolution(const float * p, int m, int n);
//操作：输入一个矩阵, 求Ax=b的特解
//操作前：p指向一个矩阵
//操作后：如果有解 输出该特解
//            如果没有 提示无解 返回

float * Transposition(const float * p,int m,int n);
//操作：输入一个矩阵，返回其转置
//操作前：p指向一个已初始化的矩阵
//操作后：返回其转置

void AboutUs(void);

#endif