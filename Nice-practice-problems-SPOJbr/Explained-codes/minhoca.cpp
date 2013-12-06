//Dynamic programming — search for the path with maximal sum in a field of integer numbers. It is not allowed to move in the direction -y, nor pass through the same spot twice
//http://br.spoj.com/problems/MINHOCA2/
#include <stdio.h>
#include <stdlib.h>
#define tammax 1001 
int V[tammax][tammax][5],M[tammax][tammax];

int maxvalue(int y, int x, int direcao,int M[tammax][tammax],int Y,int X, int V[tammax][tammax][5] ) {
    if( V[y][x][(direcao+3)] !=(-100000000 ))
	{
	return  V[y][x][direcao+3];
	}
	else{
	if(x==1 && y==1){
		if (direcao == 1){
		return M[1][1];
		}
		else{ return -10000000;
		}
	}
	else {
		if (y==1){
			if (direcao == 1){
			V[y][x][direcao+3] = maxvalue(y,x-1,direcao,M,Y,X,V) + M[1][x];
			return V[y][x][direcao+3];
			}
			else{ return -10000000;
			}
		}
		else{
			if (((x-direcao) < 1) || (x-direcao) > X){
				if  ( maxvalue(y-1,x,direcao*(-1),M,Y,X,V) > maxvalue(y-1,x,direcao,M,Y,X,V) ){
				V[y][x][direcao+3] = maxvalue(y-1,x,direcao*(-1),M,Y,X,V) + M[y][x];
				}
				else{
					V[y][x][direcao+3] = maxvalue(y-1,x,direcao,M,Y,X,V) + M[y][x];
				}
				return V[y][x][direcao+3];
			}

			else {
				if ( maxvalue(y-1,x,direcao,M,Y,X,V) > maxvalue(y-1,x,direcao*(-1),M,Y,X,V) ) {
					if ( maxvalue(y-1,x,direcao,M,Y,X,V) > maxvalue(y,(x-direcao),direcao,M,Y,X,V) ) {
						V[y][x][direcao+3] =maxvalue(y-1,x,direcao,M,Y,X,V ) + M[y][x] ;
						return V[y][x][direcao+3];
					}
					else{
						V[y][x][direcao+3] =maxvalue(y,(x-direcao),direcao,M,Y,X,V)+ M[y][x];
						return V[y][x][direcao+3];
					}
				}
			
				else{
					if ( maxvalue(y-1,x,direcao*(-1),M,Y,X,V) > maxvalue(y,(x-direcao),direcao,M,Y,X,V) ) {
						V[y][x][direcao+3] = maxvalue(y-1,x,direcao*(-1),M,Y,X,V) + M[y][x];
						return V[y][x][direcao+3];
					}
					else{
						V[y][x][direcao+3] = maxvalue(y,(x-direcao),direcao,M,Y,X,V)+ M[y][x];
						return V[y][x][direcao+3] ;
					}
				}
			}
		}
	}
	}
}

int main()
{
	int i,j,k,y,x,teste;
	scanf("%d %d", &y, &x);
	teste=1;
	while (x!=0){
	
	for (i=1;i<=y;i++){
		for (j =1;j<=x;j++){
			scanf("%d", &M[i][j]);
			V[i][j][2] = (-100000000 );
			V[i][j][4] =(-100000000 );
		}
	}
	for (i=1;i<=y;i++){
		for (j =1;j<=x;j++){
			for (k=1; k>=(-1); k-=2){
					maxvalue(i,j,k,M,y,x,V);
		
			}
		}
	}
	printf("Teste %d\n", teste);
	printf("%d\n\n", V[y][x][4]);//maxvalue(y,x,1,M,y,x,V));
	scanf("%d %d",&y,&x);
	teste++;
	}	

return 0;
}
Close
