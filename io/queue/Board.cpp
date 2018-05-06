/*************************************************************************
	> File Name: Board.cpp
	> Author: Zisheng Zou
	> Mail: zzshneuq@163.com
	> Created Time: Sat May  5 22:06:50 2018
 ************************************************************************/

#include<iostream>
#include "position.h"
#include<errno.h>
#include<queue>
#include<stdlib.h>
#include<stdlib.h>

using namespace std;

int **malloc2arr(int r,int c){
    int i;
    int **t = (int **)malloc( r*sizeof(int *));
    for(int i=0;i<r;++i){
        t[i] = (int *)malloc(c*sizeof(int));
    }
    return t;
}

position NewPosition(){
    position p ;
    if((p = (position) malloc (sizeof(Pnode)))== 0) perror("Exhausted memory");
    else 
        return p ;
}

int FindPath(position start,position finish,position* path){
    int m=5,n=5;
    position here,nbr,offset[4];
    queue<position>* Q = new queue<position>;
    if((start->row==finish->row)&&(start->col==finish->col))
        return 0 ;
    int** grid = malloc2arr(m+2,n+2);
    for(int i=0;i<=m+1;++i){
        grid[i][0] == 1;
        grid[i][n+1] == 1;
    }

    for(int i=0;i<=n+1;++i){
        grid[0][i] == 1;
        grid[m+1][i] == 1;
    }
    for(int i=0;i<4;++i) offset[i]=NewPosition();
    offset[0]->row=0;offset[0]->col=1; //right
    offset[1]->row=1;offset[1]->col=0; //down
    offset[2]->row=0;offset[2]->col=-1; //left
    offset[3]->row=-1;offset[3]->col=0; //up
    here = NewPosition();
    here->row = start->row;
    here->col = start->col ;
    grid[start->row][start->col] = 2;
    while(1){
        for(int i=0;i<4;++i){
            nbr = NewPosition();
            nbr->row = here->row + offset[i]->row ;
            nbr->col = here->col + offset[i]->col ;
            if(grid[nbr->row][nbr->col]==0){
                grid[nbr->row][nbr->col] = grid[here->row][here->col] + 1;
                if((nbr->row==finish->row)&&(nbr->col==finish->col)) break ;
                Q->push(nbr);
                
            }
        }
        if((nbr->row==finish->row)&&(nbr->col==finish->col)) break ;
        if(Q->empty()) return 0 ;
        here = Q->front();
        Q->pop();

    }
    len = grid[finish->row][finish->col] - 2;
    for(int i=0;i<len;++i) path[i] = NewPosition();

    here = finish ;
    for(int j=len-1;j>=0;--j){
        path[j] = here ;
        //find the last one position
        for (int i=0;i<4;++i){
            nbr = NewPosition();
            nbr->row = here->row + offset[i]->row ;
            nbr->col = here->col + offset[i]->col ;
            if(grid[nbr->row][nbr->col]==j+2) break;
        }
        here = nbr ;
    }
    return len ;
}

int main(){

    return 0;
}
