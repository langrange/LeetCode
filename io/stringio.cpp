/*************************************************************************
	> File Name: stringio.cpp
	> Author: Zisheng Zou
	> Mail: zzshneuq@163.com
	> Created Time: Sat May  5 16:40:08 2018
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;

int main(){
    string s ;
    // it can ignore the space at the head, and stop when meet  
    // a space
    cin >> s;
    cout << "the input string is : "<< s << endl ;
    // input two string at once
    string s1,s2;
    cin >> s1 >> s2 ;
    cout << "the input string is : "<< s1 << ' '<< s2 << endl ;
    string word;
    while(cin>>word)
        cout << word << '\t' ;
    return 0;
}

