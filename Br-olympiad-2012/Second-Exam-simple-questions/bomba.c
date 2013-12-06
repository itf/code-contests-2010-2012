/*estrategia de solucao
fazer uma função de busca em largura
em que se armazene 3 tempos minimos para chegar
na casa, um quando t %3 =0, t%3=1, t%3=2

Nessa busca em largura as arestas são dependentes do tempo (variavel t), podendo estar "abertas" ou "fechadas".

Após chegar na rotatória final, a busca em profundidade para, retornando o valor do tempo que demora para chegar

caso ela já tenha passado por todas as rotatórias possíveis para cada um dos t (==0, ==1, ==2) e não chegue na rotatória final, ela retorna -1
*/

#include <stdio.h>
#define max 502

int rot[max][max][3], foi[max][3], tempo[max][3], proximo[3*max], tempoaux[3*max];

int BFS(int ini, int n, int fim){ //vertice de inicio, quantidade de vertices, vertice de fim
	int  i, time, K, pont, b, t;
	time=0;
	t=2; //como ele sai dessa rotatoria no tempo %3 = 0, ele chega nela em um tempo %3 =2
	foi[ini][t]=1; 
	tempo[ini][t]=0;
	proximo[0]=ini;
	tempoaux[0]=0;
	pont=0;
	b=0;
	while( (!foi[fim][0]) && (!foi[fim][1]) && (!foi[fim][2]) && (b<=pont)){
		K=proximo[b];
		time = tempoaux[b++];
		t=(time)%3;
/*//debug{
		printf("K = %d ", K); 
		printf("b = %d ", b);
		printf("time =%d ", time);
		printf("pont= %d ", pont);
		printf("t= %d \n", t);  
//					*/ //  }debug
		for (i=0;i<n; i++){
			if (!foi[i][t]){
				if(rot[K][i][t]){
					proximo[++pont]=i;
					tempo[i][t]=time+1;
					tempoaux[pont]=time+1;
					foi[i][t]=1;
				}
			}
		}
	}
	if(foi[fim][0])
		return tempo[fim][0];
	else if(foi[fim][1])
		return tempo[fim][1];
	else if(foi[fim][2])
		return tempo[fim][2];
	else return -1;
}		
int main(){
	int N,E,S,M,i,j,k, A,B,t;
	scanf("%d %d %d %d", &N, &E, &S, &M);
	
	//inicializando vetores e matrizes	
	for(i=0;i<N;i++){
		for(k=0;k<3;k++){
			foi[i][k]=0;
			tempo[i][k]=0;
		}
		for(j=0;j<N;j++){
			for(k=0;k<3;k++){
			rot[i][j][k]=0;
			}
		}
	}
	//inicializados
	
	//ler as arestas e colocar a dependencia temporal
	for(i=0;i<M;i++){
		scanf("%d %d %d", &A, &B, &t);
		if (t==0){
			rot[A][B][1]=rot[A][B][2]=1;
			//rot[B][A][1]=rot[B][A][2]=1; //as ruas sao de mao unica
		}else{
			rot[A][B][0]=1;//rot[B][A][0]=1; //as ruas sao de mao unica
		}
	}

	
	int x;
	x=BFS(E, N, S);
	if (x!=-1)
		printf("%d",x );
	else
		printf("*");
	
	//printf("passou");
return 0;
}


