// longPalindromicSubstring.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

string longPalindromicSubstring(string s);
int _tmain(int argc, _TCHAR* argv[])
{
	string s = "womenshiyigehxoaoxhuesheng";
	string fuck = longPalindromicSubstring(s);
	cout << longPalindromicSubstring(s)<<endl;
	return 0;
}


string longPalindromicSubstring(string s){
	bool **full = nullptr;
	int n = s.size();
	full = new bool*[n];
	int maxLen = 1;
	int startIndex = 0;
	for (int i = 0; i < n; i++){
		full[i] = new bool[n];
		for (int j = 0; j < n; j++)
			full[i][j] = false;
	}
	for (int i = 0; i < n; i++){
		full[i][i] = true;
		for (int j = 0; j < i; j++){
			full[j][i] = (s[i] == s[j] && (i ==j + 1 || full[j + 1][i - 1]));  //dynamic plan 
			if (full[j][i])
			if (maxLen < i - j + 1){
				maxLen = i - j + 1;
				startIndex = j;
			}
		}
	}
	return s.substr(startIndex,maxLen);
} 


