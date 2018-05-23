/*************************************************************************
	> File Name: LCSLength.cpp
	> Author: Zisheng Zou
	> Mail: zzshneuq@163.com
	> Created Time: 2018年05月23日 20:33:07
 ************************************************************************/

#include<iostream>
#include<vector>

using namespace std;

int **malloc2arr(int r,int c){
    int i;
    int **t = (int **)malloc( r*sizeof(int *));
    for(int i=0;i<r;++i){
        t[i] = (int *)malloc(c*sizeof(int));
    }
    return t;
}
void freeArr(int r,int c,int **t){
    for(int i=0;i<r;++i)
        free(t[i]);
    free(t);
}

void LcsLength(int m,int n,char* x,char* y,int **c,int **d){
    for(int i=0;i<=m;++i) c[i][0] = 0 ;
    for(int j=0;j<=n;++j) c[0][j] = 0 ;

    for(int i=1;i<=m;++i)
    for(int j=1;j<=n;++j){
        if(x[i-1]==y[j-1]) {
            c[i][j] = c[i-1][j-1] + 1;
            d[i][j] = 1;
        }else{
            if(c[i-1][j]>c[i][j-1]){
                c[i][j] = c[i-1][j];
                d[i][j] = 2 ;                
            }else{
                
                c[i][j] = c[i][j-1];
                d[i][j] = 3 ;                
            }
        } 
    }

}

void pp(int i,int j,char * x,int **d ){
    if(i==0 ||j==0) return; 
    if(d[i][j]==1){
        pp(i-1,j-1,x,d);
        cout << x[i-1];
    }else{
        if(d[i][j]==2){
            pp(i-1,j,x,d);
        }else{
            pp(i,j-1,x,d);
        }
    }
}


int main(){

    char x[5]={'a','t','d','c','e'} ;
    char y[4]={'b','d','c','e'} ;

    int m=5,n=4;
    int ** c = malloc2arr(m+1,n+1);
    int ** d = malloc2arr(m+1,n+1);
    LcsLength(m,n,x,y,c,d);
    pp(5,4,x,d);
    freeArr(m+1,n+1,c);
    freeArr(m+1,n+1,d);

    return 0 ;
}
