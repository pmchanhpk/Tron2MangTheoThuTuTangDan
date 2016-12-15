#include<stdio.h>

void nhapMang(int arr[], int length)
{
	for (int i=0; i<length; i++)
	{
	printf("Nhap phan tu thu %d: ", i+1);
	scanf("%d",&arr[i]);	
	}	
}

void xuatMang(int arr[], int length)
{
	for (int i=0; i<length; i++)
	{
	printf("%d ",arr[i]);
	}
}

void ghepMang(int A[], int phan_tu_A, int B[], int phan_tu_B, int C[])
{
	for (int i=0;i<phan_tu_A;i++)
	{
		C[i]=A[i];
	}

	for (int i=phan_tu_A;i<phan_tu_A+phan_tu_B;i++)
	{
		C[i]=B[i-phan_tu_A];
	}
}

int Max(int C[], int length)
{
	int max=C[0];
	for (int i=1;i<length;i++)
	{	
	if(C[i]>max)
		max=C[i];
	}
	return max;
}

bool kiemTraso0(int C[], int length)
{
	bool do_have_0 = false;
	int max = Max(C,length) + 1;
	for (int i=0; i<length; i++)
	{
		if (C[i] == 0)
		{
			C[i] = max;
			do_have_0 = true;
		}
		
	}
	return do_have_0;
}

void Hoanvi(int&a, int&b)
{
	int temp = a;
	a = b;
	b = temp;
}

void sapXepTang(int arr[], int length)
{
	for (int i = 0; i < length - 1 ; i++)
	{
		for (int j = i+1; j<length; j++)
		{
			if (arr[i] > arr[j])
			Hoanvi(arr[i], arr[j]);
		}
	}
}

void doiMaxThanh0(int C[], int length)
{
	int max = Max(C,length);
	for (int i = 0; i < length; i++)
	{
		if (C[i] == max)
			C[i] = 0;
	}
}

int main()
{
	int  A[100], B[100], C[200], kq, so_ptA, so_ptB;
	bool doi = false;
 	printf("Nhap so luong phan tu A:"); 	
 	scanf("%d",&so_ptA);
 	nhapMang(A,so_ptA);	
	printf("Nhap so luong phan tu B:"); 
	scanf("%d",&so_ptB);
 	nhapMang(B,so_ptB);     	
	ghepMang(A, so_ptA, B, so_ptB, C);
	doi = kiemTraso0(C,so_ptA+so_ptB);
	sapXepTang(C,so_ptA+so_ptB);	
	if (doi)
		doiMaxThanh0(C,so_ptA + so_ptB);
		
		
	xuatMang(C, so_ptA + so_ptB);
	return 0;
}

