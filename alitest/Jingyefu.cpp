#include <iostream>
#include <vector>
#include <algorithm>

using namespace std ;

double calMinValue(int* c,double* v,int N){

    double retValue=0 ;
    if(0==N) return retValue ;

    for(int i=0;i<5;++i){
      retValue += float(N)/float(c[i])*v[i];
    }

    
    return retValue;
}

int main() {
    
    int c[5];
    double v[5];

    for(int i=0;i<5;++i)
        cin >> c[i];

    
    int N ;
    cin >> N ;
    
    for(int i=0;i<5;++i)
        cin >> v[i];
    
    
    std::cout<<calMinValue(c,v,N)<<std::endl;
   
    return 0;
}
