/*
 Description:
 Given a string s constists of upper/lower-case alphabets and space ' ', return the length of last word in the string .
 Example:
 Input: "Hi World"
 Output: 5
 Interface£ºint lengthofLastWord(const char *s) ;
 Date: 12/16/2017
*/

#include<iostream>
using namespace std;

int lengthofLastWord(const char  *s);


int main(){
	cout << lengthofLastWord("fuck what are you    iokll");
	return 0;
}
int lengthofLastWord(const char  *s){
	int len = 0;
	while (*s){
		if (*s++ != ' ')
			++len;
		else if (*s&&*s != ' ')
			len = 0;
	}
	return len;
}