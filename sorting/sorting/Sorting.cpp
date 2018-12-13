#include "Sorting.h"

int test()
{
	int res2, i;
	do {
		res2 = scanf_s("%d", &i);
		while (getchar() != '\n');
		if (res2 != 1) printf("Введите число!\n");
	} while (res2 != 1);
	return i;
}

void input(int size, int *arr, int &sort)
{
	srand(time(NULL));
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 1000; // диапазон случайных чисед от 0 до 1000
	}
	sort++;
}

void swap(int i, int j, int *arr)
{
	int buff;
	buff = arr[i];
	arr[i] = arr[j];
	arr[j] = buff;
}

void choice_min_value(int size, int *arr)
{
	clock_t t1 = clock();
	int min;
	for (int i = 0; i < size; i++)
	{
		min = i;
		for (int j = i + 1; j < size; j++)
		{
			if (arr[min] > arr[j]) min = j;
		}
		swap(i, min, arr);
	}
	clock_t t2 = clock();
	double search_time = (t2 - t1 + .0) / CLOCKS_PER_SEC;
	printf("%lf\n", search_time);
}

void bubble(int size, int *arr)
{
	clock_t t1 = clock();
	int i, j;
	for (i = 0; i < size; ++i) {
		for (j = size - 1; j > i; --j)
		{
			if (arr[j - 1] > arr[j]) swap(j, j - 1, arr);
		}
	}
	clock_t t2 = clock();
	double search_time = (t2 - t1 + .0) / CLOCKS_PER_SEC;
	printf("%lf\n", search_time);
}

void shaker(int size, int *arr)
{
	clock_t t1 = clock();
	int leftMark = 1;
	int rightMark = size - 1;
	while (leftMark <= rightMark)
	{
		for (int i = rightMark; i >= leftMark; i--)
		{
			if (arr[i - 1] > arr[i])  swap(i, i - 1, arr);
		}
		leftMark++;

		for (int i = leftMark; i <= rightMark; i++)
		{
			if (arr[i - 1] > arr[i]) swap(i, i - 1, arr);
		}
		rightMark--;
	}
	clock_t t2 = clock();
	double search_time = (t2 - t1 + .0) / CLOCKS_PER_SEC;
	printf("%lf\n", search_time);
}

void shell(int size, int *arr)
{
	clock_t t1 = clock();
	int gap; // Расстояние между элементами
	int i, j;
	for (gap = size / 2; gap > 0; gap /= 2)
	{
		for (i = gap; i < size; i++)
		{
			for (j = i - gap; j >= 0 && arr[j] > arr[j + gap]; j -= gap)
			{
				swap(j, i + gap, arr);
			}
		}
	}
	clock_t t2 = clock();
	double search_time = (t2 - t1 + .0) / CLOCKS_PER_SEC;
	printf("%lf\n", search_time);
}

void quickSort(int left, int right, int *arr)
{
	int i = left, j = right; 
	int central = arr[(left + right) / 2];
	do
	{
		while (arr[i] < central) i++; 
		while (arr[j] > central) j--; 
		if (i <= j)
		{
			swap(i, j, arr);
			i++; 
			j--;
		}
	}
	while (i <= j);

	/*рекурсивно вызываем алгоритм для правого и левого подмассива*/
	if (i < right) quickSort(i, right, arr);
	if (j > left) quickSort(left, j, arr);
}

int search(int x,int size, int *arr)
{
	int L = 0, R = size - 1, m, flag = 0;
	while (L <= R)
	{
		m = (L + R) / 2;  
		if (arr[m] == x)
		{
			flag = 1;
			break;
		}
		if (x < arr[m]) R = m - 1;
		else L = m + 1;
	}
	if (flag) return m;
	else return -1;
}