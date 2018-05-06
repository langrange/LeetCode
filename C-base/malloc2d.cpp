/*************************************************************************
	> File Name: malloc2d.cpp
	> Author: Zisheng Zou
	> Mail: zzshneuq@163.com
	> Created Time: Thu May  3 21:16:55 2018
 ************************************************************************/

#include<iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int **malloc2arr(int r,int c){
    int i;
    int **t = (int **)malloc( r*sizeof(int *));
    for(int i=0;i<r;++i){
        t[i] = (int *)malloc(c*sizeof(int));
    }
    return t;
}

int main(){

    int ** arr = malloc2arr(3,4);
    arr[0][1] = 9;
    printf("the arr num is %d",arr[0][1]);

    return 0;
}
