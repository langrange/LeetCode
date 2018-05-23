/*************************************************************************
	> File Name: QueueBorad.cpp
	> Author: Zisheng Zou
	> Mail: zzshneuq@163.com
	> Created Time: 2018年05月10日 20:05:47
 ************************************************************************/

#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<vector>
#include<queue>
#include<string>
#include<fstream>
#include<sstream>

using namespace std;

typedef struct board * Position ;
typedef struct board {
    int x=0;
    int y=0;
}Aposition ;

int **malloc2arr(int r,int c){
    int i;
    int **t = (int **)malloc( r*sizeof(int *));
    for(int i=0;i<r;++i){
        t[i] = (int *)malloc(c*sizeof(int));
    }
    return t;
}


Position NewPosition(){
    Position p ;
    if((p = (Position) malloc (sizeof(Aposition)))== 0) perror("Exhausted memory");
    else 
        return p ;
}

int MinDist(vector<vector<int>> &Matrix,Position start, Position finish,Position *& path){

    int len=0 ; 
    int row = Matrix.size();
    int col = Matrix[0].size();
    int ** FrontSide = malloc2arr(row+2,col+2);
    queue<Position> road ;
    vector<Position> offset(4);

    for(int i=0;i<4;++i)
        offset[i] = NewPosition() ;

        offset[0]->x =0;        offset[0]->y =1;
        offset[1]->x =1;        offset[1]->y =0;
        offset[2]->x =0;        offset[2]->y =-1;
        offset[3]->x =-1;       offset[3]->y =0;
    

    // init the FrontSide 

    for(int j=0;j<=col+1;++j){
        FrontSide[0][j] = 1;   //up and down set to 1
        FrontSide[row+1][j] = 1;
    }

    for(int j=0;j<=row+1;++j){
        FrontSide[j][0] = 1;  // left and right set to 1
        FrontSide[j][col+1] = 1;
    }

    for(int i=0;i<row;++i)
    for(int j=0;j<col;++j){
        FrontSide[i+1][j+1] = Matrix[i][j];
    }

    Position current =  NewPosition();
    current = start ;
    
    FrontSide[current->x][current->y] = 2 ;

    while(1){

        for(int i=0;i<4;++i){
            
            Position nb= NewPosition() ;
            nb->x = current->x + offset[i]->x ;
            nb->y = current->y + offset[i]->y ;
            if(!FrontSide[nb->x][nb->y]){
    
                FrontSide[nb->x][nb->y] = FrontSide[current->x][current->y] + 1 ;
                if(nb->x==finish->x && nb->y==finish->y){
                    break ;
                }
                road.push(nb) ;
            }

        }

        if(road.empty()) break ;
        current = road.front() ;
        road.pop() ;
        if(FrontSide[finish->x][finish->y]) break ;

    }

    len = FrontSide[finish->x][finish->y] - 2;
    // get the path from start point to finish point ;
    
    path = (Position *) malloc((len+1)*sizeof(Position)) ;

    path[len] = finish ;
    current = finish ;
    for(int i=len-1;i>=2;--i){
        Position nb = NewPosition();
        for(int j=0;j<4;++j){
            nb->x = current->x + offset[j]->x ;
            nb->y = current->y + offset[j]->y ;
            if(FrontSide[nb->x][nb->y]==i+2)
            path[i] = nb ;
            break ;
        }
        current = nb ;
        
    }

    return len ;

}

int main(){

    vector<vector<int>> matrix(8,vector<int>(8,0)) ;

    ifstream infile ;
    infile.open("Mat.txt");
    string line ;
    int word ;
    int i = 0 ;
    while(getline(infile,line)){

        if(line.empty()) break ;
        int j=0 ;
        istringstream record(line);
        while(record>>word) matrix[i][j++] = word;
        ++i;
    }
    
    Position* path = NULL ;
    Position start = NewPosition();
    start->x = 1;
    start->y = 1;
    Position finish = NewPosition();
    finish->x = 7;
    finish->y = 7;
    
    int len =  MinDist( matrix,start,finish,path) ;

    for (int i=0;i<8;++i){
        for (int k=0;k<8;++k){
        for (int j=0;j<len;++j){
            
            if ((path[j]->x== i+1)&&(path[j]->y==k+1))
            cout << '*' ;
            else
            cout << '0' ;
        }
        cout << ' '; 
    
        }
        cout << endl ;
    }


    free(path) ;

    return 0 ;
}
