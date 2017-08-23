#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0

int my_random(int bound)
{
	return rand()%bound;
}


int* generate_random_array(int size, int max)
{
	if (size < 1)
	{
		printf("size error\n");
		return NULL;
	}
	int *array = (int*)malloc(size*sizeof(int));
	int i;
	for(i = 0; i < size; i++)
	{
		array[i] = my_random(max);
	}
	return array;
}


void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void reverse(int *array, int n)
{
	if (n < 1)
	{
		printf("array size error\n");
		return;
	}
	int i;
	for (i =0; i < n/2; i++)
		swap(&array[i], &array[n-i-1]);
}

// 分类 -------------- 内部比较排序
// 数据结构 ---------- 数组
// 最差时间复杂度 ---- O(n^2)
// 最优时间复杂度 ---- 如果能在内部循环第一次运行时,使用一个旗标来表示有无需要交换的可能,可以把最优时间复杂度降低到O(n)
// 平均时间复杂度 ---- O(n^2)
// 所需辅助空间 ------ O(1)
// 稳定性 ------------ 稳定
void bubble_sort(int *array, int n)
{
	if (n < 1)
	{
		printf("array size error\n");
		return;
	}

	int i, j;
	for (i = n-1; i >= 0; i--)
	{
		int flag = 0;
		for (j = 0; j < i; j++)
		{
			if (array[j] > array[j+1])
			{
				flag = 1;
				swap(&array[j], &array[j+1]);
			}
		}
		if (!flag) break;
	}
}


// 分类 -------------- 内部比较排序
// 数据结构 ---------- 数组
// 最差时间复杂度 ---- O(n^2)
// 最优时间复杂度 ---- 如果序列在一开始已经大部分排序过的话,会接近O(n)
// 平均时间复杂度 ---- O(n^2)
// 所需辅助空间 ------ O(1)
// 稳定性 ------------ 稳定
void cocktail_sort(int *array, int n)
{
	if (n < 1)
	{
		printf("array size error\n");
		return;
	}

	int left = 0;
	int right = n-1;
	int i;
	while (left < right)
	{
		for (i = left; i < right; i++)
		{
			if (array[i] > array[i+1])
				swap(&array[i], &array[i+1]);
		}
		right--;
		for (i = right; i > left; i--)
		{
			if (array[i-1] > array[i])
				swap(&array[i-1], &array[i]);
		}
		left++;
	}
}


void merge_sort(int *array, int n)
{

}


// 分类 ------------- 内部比较排序
// 数据结构 ---------- 数组
// 最差时间复杂度 ---- 最坏情况为输入序列是降序排列的,此时时间复杂度O(n^2)
// 最优时间复杂度 ---- 最好情况为输入序列是升序排列的,此时时间复杂度O(n)
// 平均时间复杂度 ---- O(n^2)
// 所需辅助空间 ------ O(1)
// 稳定性 ------------ 稳定
void insertion_sort(int *array, int n)
{
	if (n < 1)
	{
		printf("array size error\n");
		return;
	}
	int i, j;
	for (i = 1; i < n; i++)
	{
		int cur = array[i];
		j = i - 1;
		while(j >= 0 && array[j] > cur)
		{
			array[j+1] = array[j];
			j--;
		}
		array[j+1] = cur;
	}
}


// 分类 -------------- 内部比较排序
// 数据结构 ---------- 数组
// 最差时间复杂度 ---- O(n^2)
// 最优时间复杂度 ---- O(nlogn)
// 平均时间复杂度 ---- O(n^2)
// 所需辅助空间 ------ O(1)
// 稳定性 ------------ 稳定
void insertion_binary_search_sort(int *array, int n)
{
	if (n < 1)
	{
		printf("array size error\n");
		return;
	}
	int i, j;
	for (i = 1; i < n; i++)
	{
		int cur = array[i];
		int left = 0;
		int right = i - 1;

		while (left <= right)
		{
			int mid = (left + right)/2;
			//printf("left: %d, right: %d, mid: %d\n", left, right, mid);
			if (array[mid] > cur)
				right = mid - 1;
			else
				left = mid + 1;
		}
		for (j = i - 1; j >= left; j--)
			array[j+1] = array[j];
		array[left] = cur;
	}
}



// 分类 -------------- 内部比较排序
// 数据结构 ---------- 数组
// 最差时间复杂度 ---- 根据步长序列的不同而不同。已知最好的为O(n(logn)^2)
// 最优时间复杂度 ---- O(n)
// 平均时间复杂度 ---- 根据步长序列的不同而不同。
// 所需辅助空间 ------ O(1)
// 稳定性 ------------ 不稳定
void shell_sort(int *array, int n)
{
	if (n < 1)
	{
		printf("array size error\n");
		return;
	}
	//generate initial 
	int h = 0;
	while (h <= n)
	{
		h = 3*h + 1;
	}
	while( h >= 1)
	{
		int i, j;
		for (i = h; i < n; i++)
		{
			int cur = array[i];
			j = i - h;
			while(j >= 0 && array[j] > cur)
			{
				array[j+h] = array[j];
				j-=h;
			}
			array[j+h] = cur;
		}
		h = (h-1)/3;
	}

}

// 分类 -------------- 内部比较排序
// 数据结构 ---------- 数组
// 最差时间复杂度 ---- O(n^2)
// 最优时间复杂度 ---- O(n^2)
// 平均时间复杂度 ---- O(n^2)
// 所需辅助空间 ------ O(1)
// 稳定性 ------------ 不稳定
void selection_sort(int *array, int n)
{
	if (n < 1)
	{
		printf("array size error\n");
		return;
	}
	int i, j;
	for (i = 0; i < n; i++)
	{
		int min = i;
		for (j = i+1; j < n; j++)
		{
			if(array[j]<array[min])
				min = j;
		}
		if(min != i)
			swap(&array[min], &array[i]);
	}
}

void heap_sort(int *array, int n)
{

}

void quick_sort(int *array, int n)
{

}





void print_array(int *array, int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("%d ",array[i]);
	printf("\n");
}



int main()
{
	//int b[]={1,3,63,5,78,9,12,52,23};//测试样例；
	int n = 20;
	int *b = generate_random_array(n, 100);
	int* a = malloc(n*sizeof(int));

	// bubble
	memcpy(a, b, n*sizeof(int));
	print_array(a, n);
	bubble_sort(a, n);
	printf("bubble sort result: \n");
	print_array(a, n);

	// cocktail
	memcpy(a, b, n*sizeof(int));
	print_array(a, n);
	cocktail_sort(a, n);
	printf("cocktail sort result: \n");
	print_array(a, n);

	//selection
	memcpy(a, b, n*sizeof(int));
	print_array(a, n);
	selection_sort(a, n);
	printf("selection sort result: \n");
	print_array(a, n);

	//insertion
	memcpy(a, b, n*sizeof(int));
	print_array(a, n);
	insertion_sort(a, n);
	printf("insertion sort result: \n");
	print_array(a, n);

	//insertion binary search
	memcpy(a, b, n*sizeof(int));
	print_array(a, n);
	insertion_binary_search_sort(a, n);
	printf("insertion binary search sort result: \n");
	print_array(a, n);

	//shell search
	memcpy(a, b, n*sizeof(int));
	print_array(a, n);
	shell_sort(a, n);
	printf("shell sort result: \n");
	print_array(a, n);

	free(a);
	free(b);


	return 0;
}
