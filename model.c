/* model.c
 * Emirhan YILMAZ
 * provides the grid (model) 
 * and functions to handle the grid for the game of life
 */

#include "gameoflife.h"
int grid[M][N] = {0}; 	/*M and N are constants defined in gameOfLife.h*/

/*This function adds blinker to every 10x10 lower-grid*/
int initGridWithBlinker(){
int a=10,b=10;
	while(a<=2*M && b<=2*N){
		grid[a/2][b/2]=1;
		grid[(a/2)-1][b/2]=1;
		grid[(a/2)+1][b/2]=1;
		a=a+20;
		b=b+20;
	}
	return 0;
}

/*This function adds glider to every 10x10 lower-grid*/
int initGridWithGlider(){
	int a=10,b=10;
	while((a<=2*M) && (b<=2*N)){
		grid[a/2][b/2]=1;
		grid[a/2-1][b/2]=1;
		grid[a/2+1][b/2]=1;
		grid[a/2+1][b/2-1]=1;
		grid[a/2-1][b/2-2]=1;
		a=a+20;
		b=b+20;
	}
	return 0;
}
/**
 * initializes the grid with the chosen initial state
 */		
int initGrid(int initialState){
	if(initialState==1)
		initGridWithBlinker();
	else if(initialState==2)
		initGridWithGlider();
	return 0;
}
	

/**
 * returns the number of live neighbors of the cell
 * at position (x, y) on the grid
 */
int getNumberOfLiveNeighbors(int x, int y){
	int neighbors=0;
	for(int i=x-1; i<=x+1; i++){
		for(int j=y-1; j<=y+1; j++){
			if(!(i==x && j==y) && (i>=0) && (i<=M) && (j>=0) && (j<=N)){
				if(grid[i][j]==1){
					neighbors++;
				}
			}
		}
	}
	return neighbors;
}

/**
 * updates each cell by following the update rules of the game of life
 */
int updateGrid(){
	int neighbor[M][N]={0};
	for(int x=0; x<M; x++){
		for(int y=0; y<N; y++){
			neighbor[x][y]=getNumberOfLiveNeighbors(x,y);	
		}
	}
	for(int a=0; a<M; a++){
		for(int b=0; b<N; b++){
			if(grid[a][b]==1){
				if(neighbor[a][b]==1 || neighbor[a][b]>3 || neighbor[a][b]==0)
					grid[a][b]=0;
				else if(neighbor[a][b]==2 || neighbor[a][b]==3)
					grid[a][b]=1;
			}
			else{
				if(neighbor[a][b]==3)
					grid[a][b]=1;
			}
		}
	}
	return 0;
}


