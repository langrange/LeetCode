/*************************************************************************
> File Name: 0-1back.cpp
> Author: Zisheng Zou
> Mail: zzshneuq@163.com
> Created Time: Tue May  8 20:21:50 2018
************************************************************************/

#include<iostream>
#include <vector>
using namespace std;


template <typename T>
T calMaxValue( vector<T> &w, vector<T> &v, int sizeNum ,T N){
    
    if (0 == sizeNum)
        return 0 ;

    --sizeNum;

    if(w[sizeNum]>N) return calMaxValue(w,v,sizeNum,N);
    else{
        return max(calMaxValue(w,v,sizeNum,N),calMaxValue(w,v,sizeNum,N-w[sizeNum]) + 
                  v[sizeNum]);
    }

}


template <typename T>
T calMaxV( vector<T> &w, vector<T> &v,T N){

    int sizeNum = w.size() ;

    return calMaxValue( w, v, sizeNum,N) ;

}


int main(){

    vector<int > w = {2,3,5,7};
    vector<int > v = {1,2,6,7};
    int N = 12 ;

    cout << calMaxV(w,v,N) << endl ;

    return 0;
}
