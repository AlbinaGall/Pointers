#include<iostream>
using namespace std;

#define tab "\t"

void FillRand(int arr[], const int n);
void Print(int* arr, const int n);

int* PushBack(int arr[], int& n, const int value);
int* PushFront(int arr[], int& n, const int value);
int* Insert(int arr[], int& n, const int value, const int index);

int* PopBack(int arr[], int& n, const int index);
int* PopFront(int arr[], int& n, const int index);
int* Erase(int arr[], int& n, const int index);


void main()
{
	setlocale(LC_ALL, "Russian");
	int n; //������ �������
	cout << "������� ������ �������: "; cin >> n;
	int* arr = new int[n];
	
	FillRand(arr, n);
	Print(arr, n);

	//���������� ��������� ������� �� ������ � ��������
	int count1=0, count2=0;
	int* even = new int[n];
	int* odd = new int[n];
	
	for (int i = 0; i < n; i++)
	{
		if (arr[i] % 2 == 0)
		{
			even[count1++] = arr[i];
			
		}
		else {
			odd[count2++] = arr[i];
			
		}

	}
	cout << "������ ������ �����: "; Print(even, n); cout << endl;
	cout << "������ �������� �����: "; Print(odd, n); cout << endl;

	//���������� �������� � ����� �������
	int value;
	cout << "������� ����������� ��������: "; cin >> value;

	arr = PushBack(arr, n, value);
	cout << "������ � ����������� ��������� � �����: "; Print(arr, n);

	//���������� �������� � ������ �������
	arr = PushFront(arr, n, value);
	cout << "������ � ����������� ��������� � ������: "; Print(arr, n);

	//���������� �������� �� ���������� �������
	
	int index;
	cout << "������� ������ ��� �������: "; cin >> index;
	arr = Insert(arr, n, value, index);
	cout << "������ � ����������� ��������� � ��������� �������: "; Print(arr, n);

	//�������� ���������� ��������
	arr = PopBack(arr, n, index);
	cout << "������ � ��������� � �����: "; Print(arr, n);

	//�������� ������� ��������
	arr = PopFront(arr, n, index);
	cout << "������ � ��������� � ������: "; Print(arr, n);

	//�������� �������� �� ���������� �������
	arr = Erase(arr, n, index);
	cout << "�������� �������� �� �������: "; Print(arr, n);

	delete[] arr;
	delete[] even;
	delete[] odd;
	
}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++) {
		*(arr + i) = rand() % 100;
	}
}

void Print(int* arr, const int n)
{
	for (int i = 0; i < n; i++) {
		cout << arr[i] << tab;
	}
	cout << endl;
}

int* PushBack(int arr[], int& n, const int value)
{
	int* bufarr = new int[n + 1]{};//�������� ���������� ������
	for (int i = 0; i < n; i++)
	{
		bufarr[i] = arr[i];
	}
	delete[] arr;
	arr = bufarr;
	arr[n] = value;
	n++;
	return arr;
}

int* PushFront(int arr[], int& n, const int value) {
	int* bufarr = new int[n + 1]{};//�������� ���������� ������
	for (int i = 0; i < (n+1); i++)
	{
		bufarr[i+1] = arr[i];
	}
	delete[] arr;
	arr = bufarr;
	arr[0] = value;
	n++;
	return arr;
}

int* Insert(int arr[], int& n, const int value, const int index) {
	int* bufarr = new int[n + 1]{};//�������� ���������� ������
	for (int i = 0; i < n; i++)
	{
		bufarr[i < index ? i : i + 1] = arr[i];
	}
	delete[] arr;
	arr = bufarr;
	arr[index] = value;
	n++;
	return arr;
}

int* PopBack(int arr[], int& n, const int index){
	int* bufarr = new int[n - 1]{};//�������� ���������� ������
	for (int i = 0; i < (n-1); i++)
	{
		bufarr[i] = arr[i];
	}
	delete[] arr;
	arr = bufarr;
	n++;
	return arr;
}

int* PopFront(int arr[], int& n, const int index){
	int* bufarr = new int[n - 1]{};//�������� ���������� ������
	for (int i = 0; i < (n - 1); i++)
	{
		bufarr[i] = arr[i+1];
	}
	delete[] arr;
	arr = bufarr;
	n++;
	return arr;
}
int* Erase(int arr[], int& n, const int index){
	int* bufarr = new int[n - 1]{};//�������� ���������� ������
	for (int i = 0; i < n; i++)
	{
		bufarr[i < index ? i : i + 1] = arr[i];
	}
	delete[] arr;
	arr = bufarr;
	n++;
	return arr;
}
