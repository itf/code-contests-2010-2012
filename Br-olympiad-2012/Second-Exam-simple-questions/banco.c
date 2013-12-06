/* Estrategia de solucao
como as pessoas vao para o primeiro caixa livre
nos armazenamos nos "caxas" em que momento ele estara livre
a pessoa que entrar na fila, irah para o que for liberado primeiro

se o tempo entre a chegada da pessoa e o tempo do primeiro caixa liberar for maio que 20, aidiconamos 1 a quantidade de pessoas mal atendidas

o valor do caixa eh atualizado para (tempo que ficou livre+ tempo do atendimento dessa pessoa) 
*/
#include <stdio.h>
#define maxcaxa 11

int caxa[maxcaxa];
int main(){
	int C, N, i, j, total, cliente[2], livre;
	
	total=0;
	scanf("%d %d", &C, &N);
	
	for (i=0;i<C;i++)
		caxa[i]=0;
	
	for (i=0;i<N;i++){
		scanf("%d %d", &cliente[0], &cliente[1]);
		livre=0;
		for(j=1;j<C;j++){
			if (caxa[livre]>caxa[j])
				livre=j;
		}
		if (caxa[livre]-cliente[0]>20)
			total++;
		caxa[livre]+=cliente[1];
	}
	
	printf("%d", total);
	
return 0;
}
