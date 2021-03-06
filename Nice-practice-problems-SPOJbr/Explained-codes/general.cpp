//Question about sorting N lines of people, by swapping their places
//http://br.spoj.com/problems/GENERAL/
#include <stdio.h>

int V[100001],aux[100001]; 
long long int quantidade;
int k;

void troca(int &A, int &B){
	int aux;
	aux =A;
	A=B;
	B=aux;
}

int ultraquicksort(int inicio,int fim,int mod){
	
	int meio,i,j,aux1;

		meio= (inicio +fim)/2;

		//caso base = vetor unitario
		if(inicio!= fim){
			ultraquicksort(inicio,meio,mod);
			ultraquicksort(meio+1,fim,mod);
		}


		i =inicio;
		j= meio+1;
		aux1= inicio;

		//juntar os vetores e somar a quantidade de operacoes
		while (i<=meio && j<=fim){
			if(V[(j-1)*k+mod] < V[(i-1)*k+mod]){
				aux[aux1] = V[(j-1)*k+mod];
				quantidade = quantidade+1+ (meio-i);
				j++;
				aux1++;
			}
			else{
				aux[aux1] = V[(i-1)*k + mod];
				i++;
				aux1++;
			}
		}

		//acabar de juntar os vetores, agora nao soma mais a quantidade de operacoes, pois so sobrou um dos lados
		//if (i<=meio)
		for (;i<=meio;i++){
				aux[aux1] = V[(i-1)*k + mod];
				aux1++;
				
			}
		
		//if (j<=fim)
		for (;j<=fim;j++){
			aux[aux1] = V[(j-1)*k+mod];
				aux1++;
				
			}
		
		//juntar o vetor auxiliar de ordenacao ao vetor original
		for (i=inicio; i<=fim; i++)
			V[(i-1)*k+mod] = aux[i];

	return 0;
}
		

int main(){
	int i,aux2,instancias,fim,auxfim,deucerto;
	scanf("%d",&instancias);
	
	for(aux2=1;aux2<=instancias;aux2++) {

		scanf("%d %d",&fim, &k);
		
		for (i=1;i<=fim;i++)
			scanf("%d",&V[i]);
			
		quantidade =0;
		
		for (i=1;i<=k;i++){
			if ((fim+k-i)/k >=0){
				auxfim= (fim+k-i)/k;
				ultraquicksort(1, auxfim, i);
			}		
		}
		
		deucerto=1;
		

		
		for (i=1;i<=fim-1;i++)
			if (V[i]>V[i+1]){
				deucerto=0;
				break;
		}
		
		if (deucerto)
			printf("%lld\n", quantidade);
		else
			printf("impossivel\n");
	}
return 0;
}



