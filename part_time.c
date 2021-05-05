#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAX 101
int main() {
	
	int num[MAX];
	int m,n,p,q,x,y;
	int sum=0;
	scanf("%d %d", &m,&n);
	int i;
	for(i=0; i<m; i++) {
		scanf("%d %d", &p,&q);
		if (p != i+1) {
			printf("ID harus urut\n");
			return 0;
		}
		num[p] = q;
	}
	
	for(i=0; i<n; i++) {
		scanf("%d %d", &x,&y);
		if (y<1 || y>m) {
			printf("Maaf barang tidak tersedia\n");
			continue;
		}
		sum += x * num[y];
	}
	
	printf("%d\n", sum);
    return 0;
}
