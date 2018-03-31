// longPalindrmoicString(Manacher).cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
string ManacherAlgorithm(string s);

int main()
{
	string s = "acbcd121dc";
	cout << "the longest palindromic substring is : "<< ManacherAlgorithm(s) << endl;
	return 0;
} 

string s2T(string s){
	int n = s.size();
	string T = "^";
	if (0 == n)  return T + "$";
	// transform s to T with style"^#a#b#a#$"
	for (int i = 0; i < n; i++){
		T += "#" + s.substr(i,1);
	}
	T += "#$";
	return T;
}

string ManacherAlgorithm(string s){
	string T = s2T(s);
	int center = 1; int Right = 0;
	int n = T.size();
	int *p = new int[n]; //extend p[i] characters by the center (i)
	for (int i = 1; i < n; i++){
		p[i] = Right>i?min(p[2 * center - i], Right-i):0;
		while (T[i + 1 + p[i]] == T[i - 1 - p[i]] )  p[i]++;
		if (Right < i + p[i]){
			Right = i + p[i];
			center = i;
		}
	}
		int mxLen = 1;
		for (int i = 0; i < n; i++){
			if (p[i]>mxLen){
				mxLen = p[i];
				center = i;
			}
		}
		return s.substr((center - 1 - mxLen) / 2, mxLen);
}