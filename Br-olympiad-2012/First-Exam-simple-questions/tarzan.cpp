#include <stdio.h>
#define max 1001

int arvore[max][2], valores[max];

void DFS(int a, int n, int k){//busca em profundidade pelas arvores. max n x n = 10^6 operacoes
int i;
	for (i=0; i<n; i++){
		if ((valores[i]==0) && ((arvore[a][0]-arvore[i][0])*(arvore[a][0]-arvore[i][0]) +(arvore[a][1]-arvore[i][1])*(arvore[a][1]-arvore[i][1])<=k)){
			valores[i]=1;
			DFS(i,n,k);
		}
	}
}
	

int main(){

int i, j, d, n;

scanf("%d %d",&n, &d);

for (i=0; i<n; i++){
	valores[i]=0;
	scanf("%d %d",&arvore[i][0], &arvore[i][1]);
	//arvores[i][0]*=arvores[i][0];
	//arvores[i][1]*=arvores[i][1];
}
int k= d*d;
valores[0]=1;
j=1;
DFS(0,n,k);
for (i=0; i<n; i++){
	if (valores[i]==0){
		printf("N");
		j=0;
		break;
	}
	
}

if (j==1)
	printf("S");

return 0;
}
