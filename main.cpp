#include <iostream>
#include <fstream>
#include <locale.h>
#include <string.h>
#define max1 100
#define max2 1000
#define max3 10000

using namespace std;

int cmp = 0;
/// ��������� �������
int Merge(double *arr,int first,int last)
{
    int middle, start, final, j;
    double *d = new double[10000];
    middle = (first + last) / 2;  /// ���������� �������� ��������
    start = first;                /// ������ ����� �����
    final = middle + 1;           /// ������ ������ �����

        for (j = first; j <= last; j++) /// ��������� �� ������ �� �����
        {
            cmp++;
            if ((start <= middle) && ((final > last) || (arr[start] < arr[final]))) /// ���� ����� �����, ��
            {
                d[j] = arr[start]; /// ���������� � ����� ������ ����� �����
                start++;
            }
            else /// �����
            {
                d[j] = arr[final]; /// ���������� � ������ �����
                final++;
            }
        }
  ///����������� ���������� � ������
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
        MergeSort(arr, first, (first + last) / 2); /// ���������� ����� �����
        MergeSort(arr, (first + last) / 2 + 1, last);  /// ���������� ������ �����
        Merge(arr, first, last);  /// ������� ���� ������
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
    ifstream FileIn_1("Input1.txt"); ///�������� ����� ��� ���������� ������ (������� ����)
    ifstream FileIn_2("Input2.txt"); ///�������� ����� ��� ���������� ������ (������� ����)
    ifstream FileIn_3("Input3.txt"); ///�������� ����� ��� ���������� ������ (������� ����)
    double k1, k2, k3;
    if (!FileIn_1.is_open())  ///���� �� ���������� ������� ����
    {
        cout << "���� �� ������!";
        return -1;   ///��������� ��������� � ������� ������
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
    cout << endl <<" ������������ ����� �� ������� �����: "<< endl;
    for (int i = 0; i < max1; i++)
     {
         cout << arr[i] << " ";
     }
    cout << endl<<"----------------------------------------------------------------------------------------------------------------------" << endl;
    MergeSort(arr, 0, max1 - 1);
    cout << endl << "��������������� ����� �� ������� �����: " << endl;
    for (int i = 0; i < max1; i++)
     {
         cout << arr[i] << " ";
     }
    cout << endl;
    cout << "\n���������� ��������� ��� ������� �����: " << cmp << endl;
    i = 0;
    delete[] arr;
    cout << endl << "----------------------------------------------------------------------------------------------------------------------" << endl;
    if (!FileIn_2.is_open())  ///���� �� ���������� ������� ����
    {
        cout << "���� �� ������!";
        return -1;   ///��������� ��������� � ������� ������
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
    cout << endl << " ������������ ����� �� ������� �����: " << endl;
    for (int i = 0; i < max2; i++)
     {
         cout << arr2[i] << " ";
     }
    cout << endl << "----------------------------------------------------------------------------------------------------------------------" << endl;
    MergeSort(arr2, 0, max2 - 1);
    cout << endl << "��������������� ����� �� ������� �����: " << endl;
    for (int i = 0; i < max2; i++)
     {
         cout << arr2[i] << " ";
     }
     cout << endl;
     cout << "\n���������� ��������� ��� ������� �����: " << cmp << endl;
    i = 0;
    delete[] arr2;
    cout << endl << "----------------------------------------------------------------------------------------------------------------------" << endl;
    if (!FileIn_3.is_open())  ///���� �� ���������� ������� ����
    {
        cout << "���� �� ������!";
        return -1;   ///��������� ��������� � ������� ������
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
    cout << endl << " ������������ ����� �� ������� �����: " << endl;
    for (int i = 0; i < max3; i++)
     {
         cout << arr3[i] << " ";
     }
    cout << endl << "----------------------------------------------------------------------------------------------------------------------" << endl;
    MergeSort(arr3, 0, max3 - 1);
    cout << endl << "��������������� ����� �� ������� �����: " << endl;
    for (int i = 0; i < max3; i++)
     {
         cout << arr3[i] << " ";
     }
     cout << endl;
     cout << "\n���������� ��������� ��� �������� �����: " << cmp << endl;
     delete[] arr3;
}
