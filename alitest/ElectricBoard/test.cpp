/*************************************************************************
	> File Name: test.cpp
	> Author: Zisheng Zou
	> Mail: zzshneuq@163.com
	> Created Time: 2018年05月11日 20:38:09
*/
#include <math.h>
#include <string.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
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

void getMilitaryStrength(int ** &Matrix,int rowin,int colin,int & maxValue, int & minValue){

    int row = rowin;
    int col = colin;
    int ** FrontSide = malloc2arr(row,col);
    vector<Position> offset(9);

    for(int i=0;i<row;++i)
    for(int j=0;j<col;++j){
        FrontSide[i][j] = 1 ;
    }

    for(int i=0;i<9;++i)
        offset[i] = NewPosition() ;

        offset[0]->x =0;        offset[0]->y =1;
        offset[1]->x =1;        offset[1]->y =0;
        offset[2]->x =0;        offset[2]->y =-1;
        offset[3]->x =-1;       offset[3]->y =0;
        offset[4]->x =-1;       offset[4]->y =1;
        offset[5]->x =1;        offset[5]->y =1;
        offset[6]->x =1;        offset[6]->y =-1;
        offset[7]->x =-1;       offset[7]->y =-1;
    
    Position current =  NewPosition();

    vector<int> value ;
    for(int m=0;m<row;++m){
        for(int n=0;n<col;++n){
  
    current->x=m;current->y=n;

    if(Matrix[current->x][current->y]!=0 && FrontSide[current->x][current->y]){
    
        queue<Position> Group ;
        
        FrontSide[current->x][current->y] = 0;
        int sum = Matrix[current->x][current->y] ;

        while(1){
        for(int i=0;i<9;++i){
            
            Position nb= NewPosition() ;
            nb->x = current->x + offset[i]->x ;
            nb->y = current->y + offset[i]->y ;
            if(nb->x>=0 && nb->x<row && 
               nb->y>=0 && nb->y<col &&
               Matrix[nb->x][nb->y]!=0 && FrontSide[nb->x][nb->y]){
                Group.push(nb);
                FrontSide[nb->x][nb->y] = 0;
                sum += Matrix[nb->x][nb->y] ;
            }
        }
        if(Group.empty()) break;
        current = Group.front();
        Group.pop();
        
        }
        value.push_back(sum) ;

    }
}
    }

for(int i=0;i<value.size();++i){
    maxValue = max(maxValue,value[i]);
    minValue = min(minValue,value[i]);
}

}

int main() {
    int res_size;
    int* res;

    int _A_rows = 0;
    int _A_cols = 0;
    scanf("%d", &_A_rows);
    scanf("%d", &_A_cols);
    
    int** _A = (int**)malloc(_A_rows*sizeof(int*));
    int _A_init_i=0;
    for(_A_init_i=0 ; _A_init_i<_A_rows ; ++_A_init_i)
    {
        _A[_A_init_i] = (int*)malloc(_A_cols*(sizeof(int)));
    }
    
    int _A_i, _A_j;
    for(_A_i = 0; _A_i < _A_rows; _A_i++) {
        for(_A_j = 0; _A_j < _A_cols; _A_j++) {
            int _A_item;
            scanf("%d", &_A_item);
            
            _A[_A_i][_A_j] = _A_item;
        }
    }   
 
    int maxValue = 0; int minValue = INT_MAX;
    
    getMilitaryStrength( _A, _A_rows ,_A_cols ,maxValue,minValue);

    cout << maxValue << endl ;
    cout << minValue << endl ;

    return 0;
}
