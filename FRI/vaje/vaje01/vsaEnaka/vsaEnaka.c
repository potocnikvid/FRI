#include <stdio.h>
#include <stdlib.h>

int main(){
	int n = getchar() - '0';
	getchar();
	int a = getchar() -'0';
	getchar();
	int stevec = 0;
	
	for(int i = 0; i < n - 1; i++){
		int b = getchar() - '0';
		getchar();
		if(a == b){
			stevec = stevec + 1;
		}
		b = a;
	}
	printf("%d" ,stevec);
	printf("%d", n);
	int c = stevec + 1;
	if(c == stevec){
		putchar('1');
		putchar('\n');
	}else {
		putchar('0');
		putchar('\n');
	}
	return 0;
}
