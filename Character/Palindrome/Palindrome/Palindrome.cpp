// Palindrome.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool isPalindrome(string s);

int main( )
{
	string sentence = "wH1atA31hw";
	cout <<"Judge the sentence is a  Palindrome or not , and the result is: "<< isPalindrome(sentence)<<endl;
	return 0;
}

bool isPalindrome(string s){
	
	transform(s.begin(), s.end(),s.begin(),tolower);
	auto left = s.begin(), right = prev(s.end());
	while (left < right){
		if (*left != *right) {
			return false;
			break;		
		}
		++left;
		--right;
	}
	return true;
}