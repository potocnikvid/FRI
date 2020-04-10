#include <stdio.h>
#include <stdlib.h>

int main(){
	int a = getchar() - '0';
	getchar();
	int b = getchar() - '0';
	
	putchar((a+b)%10 + '0');
	printf('\n');
	return 0;
}
