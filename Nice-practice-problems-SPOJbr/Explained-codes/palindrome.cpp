//Calculates the least amount of pieces a word must be divided so that all of its parts are palindroms. Dynamic Programming
//http://br.spoj.com/problems/PAL/

#include <stdio.h>

int palindromo[3001][3001],quantidade[3001],nletras;
char letra[3001];

//ver se é palindromo
void achapalindromo(int inicio, int fim){
	//checa se a ultima letra é igual a primeira
	if (letra[inicio] == letra[fim]){
		palindromo[inicio][fim] =1;
		//se for, checa se de "inicio" -1 a "fim"+1 eh palindromo
		if (inicio >0 && fim < nletras-1)
			achapalindromo(inicio-1,fim+1);
	}
}



int main(){

	int i,j,teste=0;
	
	//le a quantidade de letras
	scanf("%d", &nletras);
	
	while(nletras>0){
		teste++;

		//transforma as posicoes palindromo em falsas
		for (i=0;i<nletras;i++){
			for (j=i;j<nletras;j++)
				palindromo[i][j] = 0;
		}


		//le as letras		
		/*for(i=0;i<nletras;i++){
			scanf(" %c", &letra[i]);
			
		}*/

		scanf("%s",letra);

		//letra[nletras]='\0';


		//acha as posicoes com palindromo
		for(i=0;i<nletras;i++)	{
				achapalindromo(i,i);
			if(i< nletras-1)
				achapalindromo(i,i+1);//os palindromos podem ter quantidade "pares" ou impares de caracteres
		}

		//caso base, com a primeira letra, o minimo eh 1
		quantidade[0] =1;


		for (i=1;i<nletras;i++){
		//a quantidade maxima ocorre quando naum ha palindromo
			quantidade[i]= quantidade[i-1] +1;
			for (j=0;j<i;j++){
			//checa se ha algum com menos
				if (j==0  && palindromo[j][i])
					quantidade[i]=1;
				
				else if ( palindromo[j][i] && quantidade[i]>quantidade[j-1]+1)
					quantidade[i]=quantidade[j-1]+1;
			}
		}

		//imprime a resposta
		printf("Teste %d\n%d\n\n", teste,quantidade[nletras-1]);
		scanf("%d", &nletras);
	}
	return 0;
}
