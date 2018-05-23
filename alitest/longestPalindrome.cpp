/*************************************************************************
	> File Name: longestPalindrome.cpp
	> Author: Zisheng Zou
	> Mail: zzshneuq@163.com
	> Created Time: 2018年05月12日 11:19:40
 ************************************************************************/

#include<iostream>
#include <vector>
#include <string>

using namespace std;


class Solution {
public:
    string longestPalindrome(string s) {
   int sizenum = s.size();
        int Tsize = 2*sizenum + 1 ;
        vector<int> length(Tsize,0) ; 
        string T(Tsize,0) ;
        
        for(int i=0;i<T.size();++i){
            if(i%2==0) T[i]='#';
            else T[i] = s[i/2] ;
        }
        
        for(int i=0;i<sizenum;++i){
            int offset = 0 ;         
            int right = i;
            while(1){
                    ++offset ;                    
                    if(T[i+offset]!=T[i-offset] || (i-offset)<0 || (i+offset)>=Tsize ) break ;
            }            
            length[i] = offset - 1;
        }
        
       vector<int> lengS(sizenum,0) ;
        
       for(int i=0;i<sizenum;++i){
           lengS[i] = max((length[2*i+1]-1)/2, ;
       }
       int maxleng = 0;
       int index = 0;
        
        for(int i=0;i<lengS.size();++i){
            if(lengS[i]>maxleng){
                index = i ;
            }
        }
        string output = s.substr( index-lengS[index], 2*lengS[index]+1);
        return  output; 
    }
};

int main(){
    
  Solution instance ;
    string s ;
    cin >> s ;
    cout << instance.longestPalindrome(s) << endl ;
    return 0 ;
}
