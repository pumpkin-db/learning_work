#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
void test(int (*p)[5], int r, int c)
{
	//使用p打印出来二维数组
	int i = 0;
	int j = 0;
	for (i = 0; i < r; i++)
	{
		for (j = 0; j < c; j++)
		{
			//如何使用p,p本身是第1行的地址
			//p+i是第i+1行的地址，要解引用后，即*(p+i)就是第i行的第一个元素的地址，那*((*p+i)+j)就是i行j列的数
			printf("%d ", *(*(p+i)+j));
		}
		printf("\n");
	}
	//写一个冒泡排序
	//按照第二列降序
	for (i = 0; i < c - 1; i++)
	{
		for(j =0; j < c - i - 1; j++)
		{
			//p是首行的地址，要比较的是第2行的地址，也就是p+1,*(p+1)就是p+1行第一个元素的地址，
			//需要比较的就是*(p+1)+j和*(p+1)+j+1的值，分别解引用即可
			if (*(*(p + 1) + j) < *(*(p + 1) + j + 1))
			{
				int tmp = *(*(p + 1) + j);
				*(*(p + 1) + j) = *(*(p + 1) + j + 1);
				*(*(p + 1) + j + 1) = tmp;
				//交换完成
			}
		}
	}
	printf("\n");
	//再次打印
	for (i = 0; i < r; i++)
	{
		for (j = 0; j < c; j++)
		{
			printf("%d ", *(*(p + i) + j));
		}
		printf("\n");
	}
}
int main()
{
	int arr[3][5] = { {1,2,3,4,5}, {2,3,6,3,7}, {2,8,5,4,7} };
	test(arr, 3, 5);
	return 0;
}
//二维数组直接传的就是一个数组地址，所以在使用数组指针的时候，直接传入arr即可，而不是&arr
//二维数组传参，传的是第一行数组的地址
//&数组名，取出的是整个数组的地址，用于数组指针，这个地址+1，就会跳过整个数组
//int main()
//{
//	int arr[10] = { 0 };
//	int (*p)[10] = &arr;
//	//p的类型是int (*)[10]
//	return 0;
//}
//int main()
//{
//	int arr1[4] = { 1,2,3,4 };
//	int arr2[4] = { 5,6,7,8 };
//	int arr3[4] = { 9,3,6,7 };
//	int* parr[3] = {arr1,arr2,arr3};
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < 3; i++)
//	{
//		for (j = 0; j < 4; j++)
//		{
//			printf("%d ", *(parr[i] + j));
//		}
//		printf("\n");
//	}
//
//	//int a = 10;
//	//int* pa = &a;
//	//int** ppa = &pa;
//
//	return 0;
//}

////数组：一组相同类型元素的集合
////指针变量：是一个变量，存放的是地址
//int my_strlen(char* str)
//{
//	//指针-指针,返回之间的元素个数
//	char* a = str;
//	while (*str != '\0')
//	{
//		str++;
//	}
//	return (str - a);
//	//int count = 0;
//	//while (*str != '\0')
//	//{
//	//	count++;
//	//	str++;
//	//}
//	//return count;
//}
//int main()
//{
//	int a = my_strlen("abcdef");
//	printf("%d", a);
//	return 0;
//}

//int main()
//{
//	int arr[10] = { 0 };
//	printf("%d", &arr[9] - &arr[0]);
//	return 0;
//}

//int main()
//{
//	//下面使用指针初始化一个数组
//	int arr[5] = { 0 };
//	int* p = arr;
//	for (int i = 0; i < 5; i++)
//	{
//		*p = i;
//		//p++;
//		if (i < 4)
//		{
//			p++;
//		}
//	}
//	printf("%d\n", arr[4]);
//	printf("%p\n", &arr[0]);
//	printf("%p\n", &arr[4]);
//	printf("%p\n", p);
//	printf("%d\n", *p);
//	return 0;
//}