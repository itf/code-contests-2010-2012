/*Estrategia de solucao
fazendo-se uso que as casas estão ordenadas
o programa percorre da esquerda para a direita a
procura da menor casa, e da direita para a esquerda pela maior casa, 
ate que passe pelos valores
*/

#include <stdio.h>
#define max 100002

int N[max];

int main(){
	int a, i,j, soma, Ra, Rb, aux;
	scanf("%d",&a);
	for (i=0;i<a;i++){
		scanf("%d", &N[i]); 
	}
	
	scanf("%d",&soma);
	

	i=0;
	j=a-1; 
	
	while ((aux=N[i]+N[j]) !=soma){
		if (aux>soma){ //se a soma das casa deu maior,
				// a casa maior é muio grande
			j--;
		}else{		//e vice e versa
			i++;
		}
	}
	Ra=N[i];
	Rb=N[j];	
	printf("%d %d", Ra, Rb);
	
return 0;
}
