/*
  Input : original:"good"; test:"go*"
  Output : 1 or 0 
  Interface£ºbool  isMatch(const char *s, const char *p)£»
  Date: 12/16/2017
  */
#include <iostream>
using namespace std;

bool  isMatch(const char *s, const char *p);

int main()
{
	const char str[] = "good";
	const char p[] = "go*";
	cout << isMatch(str, p) << endl ;
	return 0;
}

bool  isMatch(const char *s, const char *p){
	//ÅÐ¶ÏÊÇ·ñÊÇ¿Õ×Ö·û´®
	if (*p == '\0') return *s == '\0';

	if (*(p + 1) != '*'){
		if ((*p == *s) || (*p == '.'&&*s != '\0'))
			return isMatch(s + 1, p + 1);
		else
			return false;
	}
	else{
		if (*p == *s || (*p == '.'&&*s != '\0'))
			return isMatch(s + 1, p);
		else{
			return isMatch(s, p + 2);
		}
	}
}