#include<stdio.h>

void getArray(int arr[], int len);
void delElement(int arr[], int &len, int location);
int NumberNeedDel(int arr[], int len, int number_need_del);
void joinArray(int arrA[], int lenA, int arrB[], int lenB, int arrC[]);
void ascendingOrder(int arr[], int len);
void insert(int arr[], int &len, int count_number_0);
void printArray(int arr[], int len);

int main()
{
	int arrA[100], arrB[100], arrC[200], lenA, lenB, lenC, location, count_number_0_arrC, lenC_drop0;
	printf("Nhap so luong phan tu mang A: ");
	scanf("%d", &lenA);
	getArray(arrA, lenA);
	
	printf("Nhap so luong phan tu mang B: ");
	scanf("%d", &lenB);
	getArray(arrB, lenB);	
	
	joinArray(arrA, lenA, arrB, lenB, arrC);	
	lenC = lenA + lenB;
	count_number_0_arrC = NumberNeedDel(arrC, lenC, 0);	
	lenC_drop0 = lenC - count_number_0_arrC;
	ascendingOrder(arrC, lenC_drop0);	
	insert(arrC, lenC_drop0, count_number_0_arrC);

	printArray(arrC, lenC);
	return 0;
}

void getArray(int arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("phan tu thu %d la: ", i+1);
		scanf("%d", &arr[i]);
	}
}

void delElement(int arr[], int &len, int location)
{
	if (location >= 0 && location < len)
	{
		for (int i = location; i < len - 1; i++)	
			arr[i] = arr[i + 1];
		len--;
	}	
}

int NumberNeedDel(int arr[], int len, int number_need_del)
{ 
	int count_number_0 = 0;
	for (int i = 0; i < len; i++)
	{
		if (arr[i] == number_need_del)
		{
			delElement(arr, len, i);
			i--;
			count_number_0++;
		}
	}
	return count_number_0;
}

void joinArray(int arrA[], int lenA, int arrB[], int lenB, int arrC[])
{
	for (int i = 0; i < lenA; i++)
	{
		arrC[i] = arrA[i];
	}

	for (int i = lenA; i < lenA + lenB; i++)
	{
		arrC[i] = arrB[i - lenA];
	}
}

void ascendingOrder(int arr[], int len)
{
	for (int i = 0; i <  len - 1; i++)
		for (int j = i + 1; j < len; j++)
		{
			if (arr[i] > arr[j])
			{
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
}

void insert(int arr[], int &len, int count_number_0)
{
	for (int i = 0; i < count_number_0; i++)
	{
		arr[len] = 0;
		len++;
	}
}

void printArray(int arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);		
	}
}
