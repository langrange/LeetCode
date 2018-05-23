/*************************************************************************
	> File Name: reverseint.cpp
	> Author: Zisheng Zou
	> Mail: zzshneuq@163.com
	> Created Time: 2018年05月23日 19:26:46
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<limits.h>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int symbol = 1 ;
        if(x<0){
            symbol = -1 ;
            x = -1*x ;
        }
        if(!x) return x ;
        long result = 0;
        
        while(x){

            result = result*10 + x%10 ;
            x = x/10 ; 
        }
        result = result * symbol ;
        
        if(result<INT_MIN || result>INT_MAX) return 0 ;
        
        return result ;
    }
};

int main(){
    Solution sol ;
    cout << sol.reverse(1534236469) << endl ;
    return 0 ;
}
