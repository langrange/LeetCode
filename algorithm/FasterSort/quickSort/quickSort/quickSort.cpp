/*
Description:
Given a string s constists of upper/lower-case alphabets and space ' ', return the length of last word in the string .
Example:
Input: "Hi World"
Output: 5
Interface£ºint lengthofLastWord(const char *s) ;
Date: 12/16/2017
*/

#include <iostream>

using namespace std;
void quickSort(int *a, int p, int r);


int main(){
	int a[] = { 2, 5, 1, 9, 3, 0, 4 };
	quickSort(a, 0, 6);
	for (int i = 0; i < 7; ++i){
		cout << a[i] << ' '; 
	}
}

int Partion(int *a, int p, int r){
	//int result;
	int i = p, j = r + 1;
	int x = a[p];
	while (1){
		while (a[++i] < x &&i < r);
		while (a[--j]>x);
		if (i >= j)break;
		int tep = a[i];
		a[i] = a[j];
		a[j] = tep;
	}
	a[p] = a[j];
	a[j] = x;
	return j;
}

void quickSort(int *a, int p, int r){
	if (p < r){
		int q = Partion(a, p, r);
		quickSort(a, p, q-1);
		quickSort(a, q+1,r);
	}
}
