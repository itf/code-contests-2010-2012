#include <stdio.h>
//ordeno os lados dos colchoes por ordem de tamanho, e comparo os menores com os lados da porta
int main(){
int a,b,c,x,y;

scanf("%d", &a);
scanf("%d", &b);
scanf("%d", &c);
scanf("%d", &x);
scanf("%d", &y);

if( a>b){
	a^=b;
	b^=a;
	a^=b;
}

if (b>c){
	c^=b;
	b^=c;
	c^=b;
}

if( a>b){
	a^=b;
	b^=a;
	a^=b;
}

if(x>y){
	x^=y;
	y^=x;
	x^=y;
}

if (a <=x && b<= y){

printf("S");
}else
printf("N");




return 0;
}
