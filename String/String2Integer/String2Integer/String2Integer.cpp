/********************************
funtion:
	The function first discards as many whitespace characters as necessary until the non-whitesapce character is found.
	Then, starting from this character,takes an optional initial plus or minus sign followed by as many numerical digits as 
	possible ,and interprets them as a numerical value.
time:
	12/09/2017	
********************************/

#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int String2Integer(const char *str);
string addBinary(string a, string b);

int _tmain(int argc, _TCHAR* argv[])
{
	const char str[] = "-8345";
	const char a[] = "101";
	const char b[] = "1";

	cout << "addBinary:" << addBinary(a,b) << endl;
	cout << String2Integer(str) << endl;
	return 0;
}

int String2Integer(const char *str){
	int num = 0;
	int sign = 1;
	const int n = strlen(str);
	int i = 0;
	while (i < n&&str[i] == ' ')  i++;   // begin conversion from first non-whitespace
	if (str[i] == '+') i++;
	if (str[i] == '-'){
		sign = -1;
		i++;
	}
	for (; i < n; i++){
		if (str[i]<'0' || str[i]>'9') break;
		if (num>INT_MAX / 10 || (num == INT_MAX / 10 && (str[i] - '0')>INT_MAX % 10))
			return sign == -1 ? INT_MIN : INT_MAX;
		num = num * 10 + str[i] - '0';
	}
	return num*sign;
}

// 二进制相加
string addBinary(string a, string b){
	string result;
	const int n = a.size() > b.size() ? a.size() : b.size();
	reverse(a.begin(),a.end());
	reverse(b.begin(), b.end());
	int carry = 0;
	for (int i = 0; i < n; i++){
		int ai = i < a.size() ? a[i] - '0':  0;
		int bi = i < b.size() ? b[i] - '0' : 0;
		int val = (ai + bi + carry) % 2;
		carry = (ai + bi + carry) /2;
		result.insert(result.begin(),val + '0');
	}
	if (carry == 1)
		result.insert(result.begin(), '1');
	return result;
}