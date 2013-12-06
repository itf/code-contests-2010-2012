#include <stdio.h>
#define max 101
typedef struct{ //posicoes do cavalo
int a;
int b;
} typecavalo;

int main(){

typecavalo cavalo;
int n,i, j;
int N[max];
cavalo.a=4;
cavalo.b=3;

scanf("%d",&n);
j=0;
for (i=0;i<n;i++)
	scanf("%d",&N[i]);

for (i=0;i<n;i++){ //movimento do cavalo
	if (N[i]==1){
		cavalo.a+=1;
		cavalo.b+=2;
	}else if (N[i]==2){
		cavalo.a+=2;
		cavalo.b+=1;
	}else if (N[i]==3){
		cavalo.a+=2;
		cavalo.b-=1;
	}else if (N[i]==4){
		cavalo.a+=1;
		cavalo.b-=2;
	}else if (N[i]==5){
		cavalo.a-=1;
		cavalo.b-=2;
	}else if (N[i]==6){
		cavalo.a-=2;
		cavalo.b-=1;
	}else if (N[i]==7){
		cavalo.a-=2;
		cavalo.b+=1;
	}else if (N[i]==8){
		cavalo.a-=1;
		cavalo.b+=2;
	}
	j=i+1;
	//printf("a= %d, b= %d \n", cavalo.a, cavalo.b);
	if((cavalo.a==1 &&cavalo.b==3)|(cavalo.a==2 &&cavalo.b==3)|(cavalo.a==2 &&cavalo.b==5)|(cavalo.a==5 &&cavalo.b==4)){
		break;//caiu no buraco
	}
}
printf("%d",j);

return 0;
}
