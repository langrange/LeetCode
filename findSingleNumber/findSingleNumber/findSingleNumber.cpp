// findSingleNumber.cpp : 定义控制台应用程序的入口点。
//

/***************************
function:
using bits to get the
single number ,other
numbers appear Even(dual)
times
time:
12/08/2017
***************************/

#include <iostream>
using namespace std;

int FindSingle(int A[], int n);
int FindSingleIN3(int A[], int n);

int main() {
	int A[7] = { 3, 3, 3, 3,7 };
   cout<<FindSingle(A,7)<<endl;
	//cout << FindSingleIN3(A, 7) << endl;
	return 0;
}
/***************************
	using bits to get the
	single number ,other
	numbers appear Even(dual)
	times
***************************/
int FindSingle(int A[], int n) {
	int x = A[0];
	for (int i = 1; i<n; i++){
		x ^= A[i];
	}
	return x;
}

/***************************
using bits to get the
single number ,other
numbers appear three
times,you can replace 3
with any number
***************************/
int FindSingleIN3(int *A, int n) {
	int result = 0;
	int sizeInt = sizeof(int);
	int Bits[4] = { 0 };
	for (int i = 0; i<n; i++){
		for (int j = 0; j<sizeInt; j++){
			Bits[j] += (A[i] >> j) % 2;
			Bits[j] %= 3;
		}
	}
	for (int i = 0; i<sizeInt; i++){
		result += Bits[i] << i;
	}
	return result;
}

