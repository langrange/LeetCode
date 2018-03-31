/*
example:
Input : "  -4e-9   " or "4e9.4"
Output : 1 or 0
Interface：bool isValidNumber(const char s[]);
Date: 12/16/2017
*/
#include <iostream>
using namespace std;

bool isValidNumber(const char s[]);

int  main(){

	const char testStr[] = "  -4e-9   ";
	cout << isValidNumber(testStr) << endl ;
	return 0;
}

bool isValidNumber(const char s[]){
	enum InputType {
		Invaild,
		space,
		sign,
		digits,
		dot,
		exponent
	};
	int status = 0;
	const int statusConversion[][6] = {
		-1, 0, 3, 1, 2, -1,
		-1, 8, -1, 1, 4, 5,
		-1, -1, -1, 4, -1, -1,
		-1, -1, -1, 1, 2, -1,
		-1, 8, -1, 4, -1, 5,
		-1, -1, 6, 7, -1, -1,
		-1, -1, -1, 7, -1, -1,
		-1, 8, -1, 7, -1, -1,
		-1, 8, -1, -1, -1, -1,
	};

	for (; *s != '\0'; ++s){
		InputType charType = Invaild;
		if (isspace(*s))
			charType = space;
		else if (*s == '+' || *s == '-')
			charType = sign;
		else if (isdigit(*s))
			charType = digits;
		else if (*s == '.')
			charType = dot;
		else if (*s == 'e' || *s == 'E')
			charType = exponent;

		//下一个状态
		status = statusConversion[status][charType];
		//如果状态返回-1，则结束，不是有效数字
		if (-1 == status) return false;
	}
	return (1 == status || 4 == status || 7 == status || 8 == status);
}