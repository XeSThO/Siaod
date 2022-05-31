#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <iostream>
using namespace std;

void merge(int* array, int start, int middle, int end)
{
    int *arrayB =(int*)malloc(sizeof(int) * (end-start+2));                                
    int k = start;                                                  
    int m = middle +1;                     
    int i = 1;                                      
    int j = 1;
 
    while(k<=middle && m <=end){
        if(array[k]<=array[m]){             
            arrayB[i] = array[k];
            k++;
        }
        else{
            arrayB[i] = array[m];
            m++;
        }
        i++;
    }
    while(k<=middle){
        arrayB[i] = array[k];
        k++;
        i++;
    }
    while(m<= end){
        arrayB[i] = array[m];
        m++;
        i++;
    }
  
    while(j<i){
        array[start+j-1] = arrayB[j];
        j++;
    }
return;
}
 
void merge_sort(int* array, int first, int last)
{
 
    if(first<last){
        int middle = (first+last)/2;
        merge_sort(array, first, middle);
        merge_sort(array, middle+1, last);
        merge(array, first, middle, last);
    }
}
int main()
{
	setlocale(LC_ALL, "Rus");
	int i, n;
	cout <<  "Введите размер массива: "; 
	cin >> n;
	int* a = new int[n];
	clock_t start, end;
	start = clock();
	for (int i = 0; i < n; i++){
		a[i] = rand() % 100; // заполняем массив случайными числами
		cout << a[i] << "  "; // вывод массива на экран
	}
	merge_sort(a, 0, n); //вызов сортирующей процедуры
	cout << endl; //вывод упорядоченного массива
	for (i = 1; i <= n; i++) cout << a[i] << "  ";
	cout << endl;
	end = clock();
	printf("Время выполнение программы %.4f\n", ((double)end - start) / ((double)CLOCKS_PER_SEC));
}
