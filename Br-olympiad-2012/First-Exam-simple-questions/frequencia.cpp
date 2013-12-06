#include <stdio.h>
#define max 1000001
int main(){
int V[max], total, n, i, aux;

for (i=0;i<max;i++) // sempre 10^6 operacoes
V[i]=0;

scanf("%d",&n);
total=0;

for (i=0;i<n;i++){

	scanf("%d",&aux);

	if (V[aux]==0){
		total++;
		V[aux]=1;
	}
}
printf("%d", total);


return 0;
}
