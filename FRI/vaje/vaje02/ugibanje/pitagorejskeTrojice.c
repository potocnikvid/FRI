#include <stdio.h>
#include <stdbool.h>

int main(){
	int m;
	int n;
	scanf("%d %d", &m , &n);
	
	int stevec = 0;
	for(int c = m; c <= n; c++){
		bool vsajEno = false;
		
		for(int a = 1; a < c; a++){
			for(int b = a; b < c; b++){
				if(a*a + b*b == c*c){
					stevec = stevec + 1;
					break;
				}
			}
			if(vsajEno){
				break;
			}
		}
	}
	
	printf("%d\n", stevec);
	return 0;
}
