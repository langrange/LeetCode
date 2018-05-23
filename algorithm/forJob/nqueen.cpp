/*************************************************************************
	> File Name: nqueen.cpp
	> Author: Zisheng Zou
	> Mail: zzshneuq@163.com
	> Created Time: Tue May  8 22:35:54 2018
 ************************************************************************/

#include<iostream>
#include<vector>

using namespace std;


void nqueen(int N,int maxN,int &sum,vector<int>& x){
    
    --N ;
    
    for(int i=0;i<=maxN;++i){
        bool flag = true ;
        for(int j=maxN;j>N;--j){
            flag = flag && (i!=x[j]) ;
            flag = flag && (abs(N-j)!=abs(x[j]-i));
            if(!flag) break ;
        }

        if(flag){
            x[N] = i ;
            if(0==N){
                ++sum ; 
                return ;
            }
            nqueen(N,maxN,sum,x);
        }

    }
    
}

int Queen(int N){
    
    int sum =0 ;
    vector<int > x(N,-1) ;
    int maxN = N -1 ;
    nqueen(N,maxN,sum,x) ;
    return sum ;
}

int main(){
    int N ;
    cin >> N ;
    cout << Queen(N) << endl; 
    return 0;
}
