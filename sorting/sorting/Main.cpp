#include "Sorting.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int size, choose, i;
	int sort = 0, s, res_search;
	printf("Введите размер массива: ");
	size = test();
	int *arr = new int[size];
	while (1)
	{
		system("cls");
		puts("Выберите действие:");
		puts("1)Сортировка методом выбора наименьшего значения");
		puts("2)Сортировка методом пузырька");
		puts("3)Шейкерная сортировка");
		puts("4)Сортировка методом Шелла");
		puts("5)Сортировка методом Хоара");
		puts("6)Вывод массива");
		puts("7)Поиск значения в массиве");
		puts("0)Выход\n");
		choose = test();
		system("cls");
		clock_t t1, t2;
		double search_time;
		if (choose == 0) break;
		else
		{
			switch (choose)
			{
			case 1: input(size, arr, sort);
				choice_min_value(size, arr);
				puts("Отсортировано.");
					break;
			case 2: input(size, arr, sort);
				bubble(size, arr);
				puts("Отсортировано.");
					break;
			case 3: input(size, arr, sort);
				shaker(size, arr);
				puts("Отсортировано.");
				break;

			case 4: input(size, arr, sort);
				shell(size, arr);
				puts("Отсортировано.");
				sort++;
					break;
			case 5: input(size, arr, sort);
				t1 = clock();
				quickSort(0, size - 1, arr);
				t2 = clock();
				search_time = (t2 - t1 + .0) / CLOCKS_PER_SEC;
				printf("%lf\n", search_time);
				puts("Отсортировано.");
				break;
			case 6: if (sort != 0)
				{
					for (i = 0; i < size; i++)
					{
						printf("%d ", arr[i]);
					}
				}
					else
					{
						puts("Сначала необходимо отсортировать массив");
						_getch();
					}
				break;
			case 7: printf("Введите искомый элемент: ");
				s = test();
				res_search = search(s, size, arr);
				if (res_search == -1) printf("Такого элемента нет");
				else printf("Нашли: arr[%d] = %d", res_search, s);
				break;

			default: puts("Выберите действие от 0 до 7");
			}
		}
		_getch();
	}
	delete [] arr;
	return 0;
}

