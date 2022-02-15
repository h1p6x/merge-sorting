#include <iostream>
#include <fstream>
#include <locale.h>
#include <string.h>
#define max1 100
#define max2 1000
#define max3 10000

using namespace std;

int cmp = 0;
/// Выполняет слияние
int Merge(double *arr,int first,int last)
{
    int middle, start, final, j;
    double *d = new double[10000];
    middle = (first + last) / 2;  /// Вычисление среднего элемента
    start = first;                /// Начало левой части
    final = middle + 1;           /// Начало правой части

        for (j = first; j <= last; j++) /// Выполнять от начала до конца
        {
            cmp++;
            if ((start <= middle) && ((final > last) || (arr[start] < arr[final]))) /// Если левая часть, то
            {
                d[j] = arr[start]; /// записываем в новый массив левую часть
                start++;
            }
            else /// Иначе
            {
                d[j] = arr[final]; /// Записываем в правую часть
                final++;
            }
        }
  ///возвращение результата в список
    for (j = first; j <= last; j++)
    {
        arr[j] = d[j];
    }
  delete[] d;
}

int MergeSort(double *arr, int first, int last)
{
   if (first < last)
    {
        MergeSort(arr, first, (first + last) / 2); /// сортировка левой части
        MergeSort(arr, (first + last) / 2 + 1, last);  /// сортировка правой части
        Merge(arr, first, last);  /// слияние двух частей
    }
}


int main()
{
    setlocale(0, "");
    int n;
    double *arr = new double[max1];
    double* arr2 = new double[max2];
    double* arr3 = new double[max3];
    int i=0;
    ifstream FileIn_1("Input1.txt"); ///создание файла для считывания данных (входной файл)
    ifstream FileIn_2("Input2.txt"); ///создание файла для считывания данных (входной файл)
    ifstream FileIn_3("Input3.txt"); ///создание файла для считывания данных (входной файл)
    double k1, k2, k3;
    if (!FileIn_1.is_open())  ///если не получилось открыть файл
    {
        cout << "Файл не найден!";
        return -1;   ///завершаем программу с выводом ошибки
    }
    else
    {
        while (FileIn_1 >> k1)
        {
            if(i < max1)
            {
                arr[i++] = k1;
            }
        }
    }
    cout << endl <<" Вещественные числа из первого файла: "<< endl;
    for (int i = 0; i < max1; i++)
     {
         cout << arr[i] << " ";
     }
    cout << endl<<"----------------------------------------------------------------------------------------------------------------------" << endl;
    MergeSort(arr, 0, max1 - 1);
    cout << endl << "Отсортированные числа из первого файла: " << endl;
    for (int i = 0; i < max1; i++)
     {
         cout << arr[i] << " ";
     }
    cout << endl;
    cout << "\nКоличество сравнений для первого файла: " << cmp << endl;
    i = 0;
    delete[] arr;
    cout << endl << "----------------------------------------------------------------------------------------------------------------------" << endl;
    if (!FileIn_2.is_open())  ///если не получилось открыть файл
    {
        cout << "Файл не найден!";
        return -1;   ///завершаем программу с выводом ошибки
    }
    else
    {
        while (FileIn_2 >> k2)
        {
            if (i < max2)
            {
                arr2[i++] = k2;
            }
        }
    }
    cout << endl << " Вещественные числа из второго файла: " << endl;
    for (int i = 0; i < max2; i++)
     {
         cout << arr2[i] << " ";
     }
    cout << endl << "----------------------------------------------------------------------------------------------------------------------" << endl;
    MergeSort(arr2, 0, max2 - 1);
    cout << endl << "Отсортированные числа из второго файла: " << endl;
    for (int i = 0; i < max2; i++)
     {
         cout << arr2[i] << " ";
     }
     cout << endl;
     cout << "\nКоличество сравнений для второго файла: " << cmp << endl;
    i = 0;
    delete[] arr2;
    cout << endl << "----------------------------------------------------------------------------------------------------------------------" << endl;
    if (!FileIn_3.is_open())  ///если не получилось открыть файл
    {
        cout << "Файл не найден!";
        return -1;   ///завершаем программу с выводом ошибки
    }
    else
    {
        while (FileIn_3 >> k3)
        {
            if (i < max3)
            {
                arr3[i++] = k3;
            }
        }
    }
    cout << endl << " Вещественные числа из второго файла: " << endl;
    for (int i = 0; i < max3; i++)
     {
         cout << arr3[i] << " ";
     }
    cout << endl << "----------------------------------------------------------------------------------------------------------------------" << endl;
    MergeSort(arr3, 0, max3 - 1);
    cout << endl << "Отсортированные числа из второго файла: " << endl;
    for (int i = 0; i < max3; i++)
     {
         cout << arr3[i] << " ";
     }
     cout << endl;
     cout << "\nКоличество сравнений для третьего файла: " << cmp << endl;
     delete[] arr3;
}
