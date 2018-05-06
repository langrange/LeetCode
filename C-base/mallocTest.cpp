/*************************************************************************
	> File Name: mallocTest.cpp
	> Author: Zisheng Zou
	> Mail: zzshneuq@163.com
	> Created Time: Thu May  3 21:03:05 2018
 ************************************************************************/

#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>

using namespace std;

int main(){

    char *str;
    if((str=(char *)malloc(10*sizeof(char)))==0){
        printf("the memory is not enough\n");
        exit(1);
    }
    strcpy(str,"Hello");
    printf("String is %s\n",str);
    // free the space 
    free(str) ;
}
