/* Estrategia de solucao

ordenar os lados da folha
combinar as fotos de todas (4) as maneiras possiveis
ver se uma combinacao da certo na folha
*/
#include <stdio.h>

int main(){
	int x,y,l1,l2,h1,h2,i, certo=0;
	int figura[4][2];
	scanf("%d %d", &x, &y);
	scanf("%d %d", &l1, &h1);
	scanf("%d %d", &l2, &h2);
	
	if (x<y){ //ordena os lados, x>y
		x^=y;
		y^=x;
		x^=y;
	}

	// combina as folhas de 2x2=4 maneiras diferentes

	if(l1>l2){
		figura[0][0]=l1;
		figura[0][1]=h1+h2;
	}else {
		figura[0][0]=l2;
		figura[0][1]=h1+h2;
	}
	if(h1>l2){
		figura[1][0]=h1;
		figura[1][1]=l1+h2;
	}else {
		figura[1][0]=l2;
		figura[1][1]=l1+h2;
	}
	if(l1>h2){
		figura[2][0]=l1;
		figura[2][1]=h1+l2;
	}else {
		figura[2][0]=h2;
		figura[2][1]=h1+l2;
	}
	if(h1>h2){
		figura[3][0]=h1;
		figura[3][1]=l1+l2;
	}else {
		figura[3][0]=h2;
		figura[3][1]=l1+l2;
	}
	for(i=0;i<4;i++){
		if (figura[i][0]<figura[i][1]){ //ordena o formato das figuras formadas
			figura[i][0]^=figura[i][1];
			figura[i][1]^=figura[i][0];
			figura[i][0]^=figura[i][1];
			
		}
		//printf("%d %d\n", figura[i][0],figura[i][1] ); //debug
		if (x>=figura[i][0] && y>=figura[i][1]){ //compara o maior lado das figuras com o maior lado da folha, e menor com menor
			certo=1;
			break;
		}
	}

	if (certo){
		printf("S");
	}else{
		printf("N");
	}
	
return 0;
}
