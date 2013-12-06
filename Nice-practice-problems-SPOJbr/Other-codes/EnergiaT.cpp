//http://br.spoj.com/problems/ENERGIAT/
#include <stdio.h>

int edpprog[5001][21],edpprogtotal[2][21];


int main(){
	int frequencia, programas,aux1,aux2,i,j,k, edptroca,melhor;
		scanf("%d %d %d %d", &frequencia, &programas, &aux1, &aux2);
		while (aux2!=0){

			edptroca=aux1*aux2;
			
			for (i=1;i<=programas;i++)
				for (j=1;j<=frequencia;j++){
					scanf("%d %d", &aux1, &aux2);
					edpprog[i][j] = aux1*aux2;
					//edpprogtotal[1][j]=0;
				}

			
			edpprogtotal[1][1] = edpprog[1][1];

			for (i=2;i<=frequencia;i++)
				edpprogtotal[1][i] = edpprog[1][i]+edptroca;
	
			
			aux1=-1;
			aux2 = 1;
			for (i=2;i<=programas;i++){
					aux1=aux1*-1;
					aux2=aux2-aux1;
					for (j=1;j<=frequencia;j++){
						edpprogtotal[aux2][j] = edpprogtotal[aux2+aux1][j] + edpprog[i][j];
						for (k=1;k<=frequencia;k++)
							if (edpprogtotal[aux2][j] > edpprogtotal[aux2+aux1][k] + edpprog[i][j] + edptroca)
								edpprogtotal[aux2][j] = edpprogtotal[aux2+aux1][k] + edpprog[i][j] + edptroca;
					}
			}
			
			melhor = edpprogtotal[aux2][1];
			for (i=2;i<=frequencia;i++)
				if (edpprogtotal[aux2][i] < melhor)
					melhor = edpprogtotal[aux2][i];
	
			printf("%d\n", melhor);
			scanf("%d %d %d %d", &frequencia, &programas, &aux1, &aux2);
		}
	return 0;
}

