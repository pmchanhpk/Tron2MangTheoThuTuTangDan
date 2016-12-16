#include<stdio.h>

void nhapMang(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
	printf("Nhap phan tu thu %d: ", i+1);
	scanf("%d", &a[i]);	
	}	
}

void xuatMang(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
	printf("%d ", a[i]);
	}
}


void delete_vt(int a[], int &n, int vt)
{
	if(vt >= 0 && vt < n)
	{
		for (int i=vt; i < n-1; i++)
		a[i] = a[i + 1];
		n--;
	}
}

int delete_so_can_xoa(int a[], int &n, int so_can_xoa)
{
	int so_so_0 = 0;
	for (int i=0; i < n; i++)
	{
		if (a[i] == so_can_xoa)
		{
			delete_vt(a, n, i);
			i--;
			so_so_0++;
		}
	}
	return so_so_0;
}

void insert(int a[], int &do_dai, int so_so_0)
{
	for (int i = 0; i < so_so_0; i++)
	{
		a[do_dai] = 0;
		do_dai ++;
	}
}

void ghepMang(int A[], int ptA, int B[], int ptB, int C[])
{
	for (int i = 0; i < ptA; i++)
	{
		C[i] = A[i];
	}

	for (int i=ptA;i< ptA + ptB; i++)
	{
		C[i] = B[i - ptA];
	}
}

void hoanVi(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void sapXepTang(int a[], int n)
{
	for (int i = 0; i < n - 1 ; i++)
	{
		for (int j = i+1; j<n; j++)
		{
			if (a[i] > a[j])
			hoanVi(a[i], a[j]);
		}
	}
}

int main()
{
	int A[100], B[100], C[200], so_pt_A, so_pt_B, so_pt_C, so_so_0_A, so_so_0_B ;
	
	printf("Nhap so phan tu mang A: ");
	scanf("%d",&so_pt_A);
	nhapMang(A, so_pt_A);
	
	printf("Nhap so phan tu mang B: ");
	scanf("%d", &so_pt_B);
	nhapMang(B, so_pt_B);
	
	so_so_0_A = delete_so_can_xoa(A, so_pt_A, 0);
	so_so_0_B =	delete_so_can_xoa(B, so_pt_B, 0);
	
	ghepMang(A, so_pt_A, B, so_pt_B, C);
	
	sapXepTang(C, so_pt_A + so_pt_B);
	
	so_pt_C = so_pt_A + so_pt_B;
	
	
	insert(C, so_pt_C , so_so_0_A + so_so_0_B);
	xuatMang(C, so_pt_C);
	return 0;	
}
