#include "Sorting.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int size, choose, i;
	int sort = 0, s, res_search;
	printf("������� ������ �������: ");
	size = test();
	int *arr = new int[size];
	while (1)
	{
		system("cls");
		puts("�������� ��������:");
		puts("1)���������� ������� ������ ����������� ��������");
		puts("2)���������� ������� ��������");
		puts("3)��������� ����������");
		puts("4)���������� ������� �����");
		puts("5)���������� ������� �����");
		puts("6)����� �������");
		puts("7)����� �������� � �������");
		puts("0)�����\n");
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
				puts("�������������.");
					break;
			case 2: input(size, arr, sort);
				bubble(size, arr);
				puts("�������������.");
					break;
			case 3: input(size, arr, sort);
				shaker(size, arr);
				puts("�������������.");
				break;

			case 4: input(size, arr, sort);
				shell(size, arr);
				puts("�������������.");
				sort++;
					break;
			case 5: input(size, arr, sort);
				t1 = clock();
				quickSort(0, size - 1, arr);
				t2 = clock();
				search_time = (t2 - t1 + .0) / CLOCKS_PER_SEC;
				printf("%lf\n", search_time);
				puts("�������������.");
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
						puts("������� ���������� ������������� ������");
						_getch();
					}
				break;
			case 7: printf("������� ������� �������: ");
				s = test();
				res_search = search(s, size, arr);
				if (res_search == -1) printf("������ �������� ���");
				else printf("�����: arr[%d] = %d", res_search, s);
				break;

			default: puts("�������� �������� �� 0 �� 7");
			}
		}
		_getch();
	}
	delete [] arr;
	return 0;
}

