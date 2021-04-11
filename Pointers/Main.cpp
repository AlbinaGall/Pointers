#include<iostream>

using namespace std;

//#define POINTERS_BASICS;
//#define POINTERS_AND_ARRAYS

void FillRand(int arr[], const int n);
void Print(int* arr, const int n);

void main()
{
	setlocale(LC_ALL, "Russian");
#ifdef POINTERS_BASICS
	int a = 2;
	int* pa = &a;
	cout << a << endl;
	a = 222;
	cout << &a << endl;//�������� ����� ���������� � ����� ��� ������
	cout << pa << endl;//������� ����� ���������� �, ���������� � ��������� ��
	cout << *pa << endl << endl;//�������������� ��������� �� � �������� �������� �� ������

	int* pb; //������ ��������� ���������, ��� �������������
	int b = 3;
	pb = &b;
	cout << pb << endl;
	cout << *pb << endl;
#endif // POINTERS_BASICS

#ifdef POINTERS_AND_ARRAYS
	const int n = 5;
	int arr[ n] = {3,5,8,13,21};
	cout << *arr << endl;
	for (int i = 0; i < n; i++) {
		cout << *(arr + i) << "\t";

	}
	cout << endl;
#endif // POINTERS_AND_ARRAYS

	int n; //������ �������
	cout << "������� ������ �������: "; cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		*(arr + i) = rand() % 100;
	}
	for (int i = 0; i < n; i++) {
		cout << arr[i] << "\t";
	}
	FillRand(arr,n);
	Print(arr, n);
	delete[] arr;
}