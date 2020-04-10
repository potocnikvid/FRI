#include <stdio.h>
#include <stdlib.h>

int main(){
	int n = getchar() - '0';
	getchar();

	int najvecje = -1;
	int drugoNajvecje = -1;
	for(int i = 0; i < n; i++){
		int stevilo = getchar() -'0';
		getchar();
		if(stevilo > najvecje){
			najvecje = stevilo;
			
		}else if(stevilo > drugoNajvecje){
			drugoNajvecje = stevilo;
		}
	}
	putchar(drugoNajvecje + '0');
	putchar('\n');
	return 0;
}
