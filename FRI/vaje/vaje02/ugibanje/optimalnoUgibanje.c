#include <stdio.h>
#include <stdbool.h>

int main(){
	int a;
	int b;
	scanf("%d %d", &a, &b);
	
	int ugib;
	int mirko = 4;
	while(mirko != 0 && a < b){
		ugib = (int)(a+b)/2;
		scanf("%d", &mirko);
		if(mirko == 1){
			a = ugib + 1;
		}else if(mirko == -1){
			b = ugib - 1;
		}
	}
	if(a == b){
		printf("%d\n", a);	
	}else if(a < b){
		printf("%d %d", a, b);	
	}else{
		printf("PROTISLOVJE");
	}
	return 0;
}

