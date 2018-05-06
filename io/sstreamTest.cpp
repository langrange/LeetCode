/*************************************************************************
	> File Name: sstreamTest.cpp
	> Author: Zisheng Zou
	> Mail: zzshneuq@163.com
	> Created Time: Sat May  5 17:30:45 2018
 ************************************************************************/

#include<iostream>
#include <sstream>
#include "personInfo.h" 
#include <fstream>
using namespace std;

int main(){
    ifstream infile; 
    infile.open("Tel"); 
    
    string line,word;
    vector <personInfo> people ;
    while(getline(infile,line)){
        
        if (line.empty())
            break;
        
        personInfo p;
        istringstream record(line) ;
        record >> p.name;
        while(record>>word){
            p.phones.push_back(word) ;
        }
        people.push_back(p);
        cout << p.phones.size() << endl ;
    }
    cout << people.size() << endl ;
    return  0;

}
