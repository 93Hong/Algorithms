#include <iostream>
#include <memory.h>
#include <cstdio>
#include <stdlib.h>
using namespace std;


int N;
int arr[21][21];

void tmp(int (*ar)[21]) {
	int a[21][21];
	
	memcpy(a[0], ar[0], sizeof(int) * 21 * 21);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}

int main() {
	
	int N = 10;
	tmp(arr);
	printf("1\n");

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}
