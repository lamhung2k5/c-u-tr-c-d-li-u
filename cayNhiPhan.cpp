#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void nhap(int *a, int n){
	for(int i = 0; i < n; i++) {
		printf("a[%d] = ",i);
		scanf("%d",&a[i]);
	}
}

void xuat(int *a, int n) {
	for(int i = 0; i < n; i++) {
		printf("\t%d",a[i]);
	}
}

void swap(int *x, int *y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}

void sort(int *a, int n) {
	for(int i = 1; i < n; i++){
		
	}
}

int main() {
	int n = 7;
	int *a = (int*)malloc(n*sizeof(int));
	nhap(a,n);
	sort(a,n);
	xuat(a,n);
	return 0;
}