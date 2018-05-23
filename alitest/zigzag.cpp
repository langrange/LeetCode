/*************************************************************************
	> File Name: zigzag.cpp
	> Author: Zisheng Zou
	> Mail: zzshneuq@163.com
	> Created Time: 2018年05月12日 17:07:59
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
        if (s.length()<=numRows) return s ;        
        int periodLen = numRows + numRows - 2 ;
        int periodCol = numRows - 1 ;
        int length = s.length();
        int Num = length/periodLen ;
        vector <int> mapArray(length%periodLen,0);
        int left = length%periodLen;
        
        for(int i=0;i<left;++i){
            if(0==left) mapArray[i] = 0;
            else if(left<=numRows) mapArray[i]=1;
            else mapArray[i] = left - periodCol ;
        }
        
        int col = Num*periodCol + mapArray[left];
        
        vector<vector<char>> sArray(numRows,vector<char>(col,0));
        
        int foward=0;
        int i=0,j=0;
        while(1){
            while(i<numRows){
                if(foward>=length) break;
                    sArray[i++][j] = s[foward++] ;
            }
            
            i = i - 2;
            ++j;

            while(i){
                if(foward>=length) break ;
                   sArray[i--][j++] = s[foward++] ;
            }
            if (foward>=length) break ;
        }

        string sout ;
        for(int i=0;i<numRows;++i)
            for(int j=0;j<col;++j){
                cout << sArray[i][j] ;
                if((j+1)%col==0) cout << endl ;
                else cout << ' ' ;
                if(sArray[i][j]!=0)
                sout = sout + sArray[i][j] ;
            }
        

    return sout ;

}
};

    int main(){
        string s = "whatadoing";
        int num = 4 ;
        Solution instance ;
        cout << instance.convert(s,num) ;

    }
