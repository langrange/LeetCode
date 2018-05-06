/*************************************************************************
	> File Name: getlinestring.cpp
	> Author: Zisheng Zou
	> Mail: zzshneuq@163.com
	> Created Time: Sat May  5 16:54:40 2018
 ************************************************************************/

#include<iostream>
#include <string>
using namespace std;

int main(){
 
    string line ;
    // note : the line don not include the '\n' symbol ENTER
    int a = -1;
    while(getline(cin,line))
        if(!line.empty()&&line.size()<a)
            cout << line << endl ;
    return 0;
}
