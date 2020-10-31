#include <stdio.h>

#define N 10

void InsertSort(int *arr, int n);
void Print(int* arr, int n);

int main(void) {
	int arr[N] = { 0,3,6,7,2,5,1,4,9,8 };
	Print(arr, N);
	InsertSort(arr, N);
	Print(arr, N);
}

void InsertSort(int* arr, int n) {//÷±Ω”≤Â»Î≈≈–Ú
	int temp,i,j;
	for (i = 1; i < N; i++) {
		temp = arr[i];
		for (j = i-1; temp<arr[j] ; j--) {
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = temp;
	}
}

void Print(int* arr,int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}