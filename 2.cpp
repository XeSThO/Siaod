#include <iostream>
#include <time.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "Введите размер массива: ";
	int n; // длинна массива
	cin >> n;
	clock_t start, end;
	start = clock();
	int* a = new int[n];
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 100; // заполняем массив случайными числами
		cout << a[i] << "  "; // вывод массива на экран
	}
	cout << "\n";
	int i,j,step,tmp;
	/************* Начало сортировки *******************/
	for (step = n / 2; step > 0; step /= 2)
        for (i = step; i < n; i++)
        {
            tmp = a[i];
            for (j = i; j >= step; j -= step)
            {
                if (tmp < a[j - step])
                    a[j] = a[j - step];
                else
                    break;
            }
            a[j] = tmp;
        }
	/************* Конец сортировки *******************/
	end = clock();
	for (int i = 0; i < n; i++) // вывод отсортированного массива
		cout << a[i] << "  ";
		cout << endl;
	printf("Время выполнения программы %.4f(s)\n", ((double)end - start) / ((double)CLOCKS_PER_SEC));
} 
