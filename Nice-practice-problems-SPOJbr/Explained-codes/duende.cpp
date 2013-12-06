#include <stdio.h>

int visitado[12][12], filax[101], filay[101], tamanhox, tamanhoy, distancia;

void BFS(int y, int x){
	int i,j,atualx,atualy;
	
	distancia=110;
	filax[1]= x;
	filay[1]= y;
	
	//faz uma barreira de "110"s pro cara não passar da borda
	for (i=1;i<=tamanhox; i++){
		visitado[tamanhoy+1][i] = 110;
		visitado[0][i]=110;
	}
	
	for (i=1;i<=tamanhoy; i++){
		visitado[i][tamanhox+1] = 110;
		visitado[i][0]=110;
	}
		
	//onde tem 1 fica -1, onde tem 0, fica 111
	for (i=1;i<=tamanhoy ;i++)
		for (j=1;j<=tamanhox;j++){
			if (visitado[i][j] == 1)
				visitado[i][j] =-1;
			else if (visitado[i][j] == 0)
				visitado[i][j] =111;
		//printf("%d ", visitado[i][j]);
		}
	visitado[y][x]=1;
	
	i=1;
	j=2;
	while(j>=i){
		atualx=filax[i];
		atualy=filay[i++];
		
		if (visitado[atualy-1][atualx] <0 ){
			filay[j] = atualy-1;
			filax[j++] = atualx;
			visitado[atualy-1][atualx] = visitado[atualy][atualx]+1;
		} 
		else if (visitado[atualy-1][atualx] == 111 &&  visitado[atualy][atualx]+1< distancia){
			 distancia = visitado[atualy][atualx]+1;
			//j++;//printf("%d\n", distancia);
		
			}
		if (visitado[atualy][atualx-1] <0 ){
			filay[j] = atualy;
			filax[j++] = atualx-1;
			visitado[atualy][atualx-1] = visitado[atualy][atualx]+1;
		}
		else if (visitado[atualy][atualx-1] == 111 &&  visitado[atualy][atualx]+1< distancia){
			 distancia = visitado[atualy][atualx]+1;
			
			//j++;//printf("%d\n", distancia);
		}

		if (visitado[atualy][atualx+1] <0 ){
			filay[j] = atualy;
			filax[j++] = atualx+1;
			visitado[atualy][atualx+1] = visitado[atualy][atualx]+1;
		}
		else if (visitado[atualy][atualx+1] == 111 &&  visitado[atualy][atualx]+1< distancia){
			 distancia = visitado[atualy][atualx]+1;
			//j++;//printf("%d\n", distancia);
			}

		if (visitado[atualy+1][atualx] <0 ){
			filay[j] = atualy+1;
			filax[j++] = atualx;
			visitado[atualy+1][atualx] = visitado[atualy][atualx]+1;
		}
		else if (visitado[atualy+1][atualx] == 111 &&  visitado[atualy][atualx]+1< distancia){
			 distancia = visitado[atualy][atualx]+1;
			//j++; //printf("%d\n", distancia-1);
		}
		//printf("(%d %d %d)", visitado[atualy][atualx], atualy, atualx);
	}
}

int main(){
	int i,j,comecox,comecoy;
	scanf("%d %d", &tamanhoy, &tamanhox);


	for (i=1;i<=tamanhoy;i++)
		for (j=1;j<=tamanhox;j++){
			scanf("%d",&visitado[i][j]);
			if(visitado[i][j] ==3){
				comecoy=i;
				comecox=j;
			}
		}

	BFS(comecoy,comecox);
	printf("%d\n", distancia-1);
return 0;
}
