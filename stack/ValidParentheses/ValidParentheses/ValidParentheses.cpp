/*
Interface:
bool isValidParentheses(const char s[]);
Date:12/16/2017
*/
# include <iostream>
# include <stack>
using namespace std;

bool isValidParentheses(const char s[]);

int main(){
	const char s[] = "fuck[{]ok}";
	cout << isValidParentheses(s)<< endl ;
	return 0;
}

bool isValidParentheses(const char s[]){
	string leftString = "{[(";
	string rightString= "}])";
	stack <char> stk;
	while (*s){
		if (leftString.find(*s) != string::npos){
			stk.push(*s);
		}
		else{
			if ( rightString.find(*s)!=string::npos){
				if (stk.empty() || stk.top() != leftString[rightString.find(*s)])
					return false;
				else
					stk.pop();
			}
		}
		++s;
	}	
	return stk.empty();
}