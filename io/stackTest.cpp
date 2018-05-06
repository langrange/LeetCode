/*************************************************************************
	> File Name: stackTest.cpp
	> Author: Zisheng Zou
	> Mail: zzshneuq@163.com
	> Created Time: Sat May  5 19:28:29 2018
 ************************************************************************/

#include<iostream>
#include<stack>
#include<string>
#include<stdio.h>
#include<fstream>

using namespace std;

bool isValidParentheses(const char* exp){
    stack<char> st ;
    string leftstring = "{[(";
    string rightstring = "}])";
    while(*exp){
        if(leftstring.find(*exp)!=string::npos)
            st.push(*exp) ;
        else{
            if(rightstring.find(*exp)!=string::npos)
                if(st.empty() || st.top()!=leftstring[rightstring.find(*exp)])
                    return false ;
                 else
                    st.pop();
        }
        ++exp ;
    }
    if(st.empty()) return true ;
}

int main(){

    ifstream infile ;
    infile.open("testParanthese.txt");
    string word ;
    //cin >> word ;
    infile >> word ;
    const char * exp = word.data();
    printf("the input patheses is %s",isValidParentheses(exp)?"Valid":"invalid");

    return 0;
}
