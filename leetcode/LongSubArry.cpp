/*************************************************************************
	> File Name: LongSubArry.cpp
	> Author: Zisheng Zou
	> Mail: zzshneuq@163.com
	> Created Time: 2018年05月23日 21:19:43
 ************************************************************************/

#include<iostream>
using namespace std;

int LongSubSum(int* a,int m){
    int result = a[0];
    int frontmax[m] = {0} ;
    frontmax[0] = a[0];
    int index = 0 ;
    for(int i=1;i<m;++i){
        if(frontmax[i-1]>0) frontmax[i] = frontmax[i-1] + a[i];
        else frontmax[i] = a[i];
        if(frontmax[i]>result){
            result = frontmax[i];
            index = i ;
        }
    }
    int begin = 0 ;
    int i=index ;
    while(i--)    
    if(frontmax[i]<=0) {
            begin = i+1 ;
            break;
    
        }

    for(int i=begin;i<=index;++i)
        cout << a[i] << ' ';
    return result ;
}




int main(){
    int a[] = {2,4,-3,-5,8,-5,3,2,9,2,5} ;
    cout << LongSubSum(a,11) << endl ;
    return 0 ;
}
