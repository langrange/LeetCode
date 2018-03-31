/*
Description:
Given a array ,and return this array sorted
Example:
Input: [1,5,3,9,4]
Output: [1,3,4,5,9]
Interface£ºvoid mergesort(Type a[], int left, int right) ;
Date: 12/16/2017
*/

#include<iostream>
using namespace std;

template <class Type>
class MyClass
{
public:
	void Mergesort(Type *a, int left, int right);

	void Merge(Type *a,Type *b, int left, int i, int right);

	void Copy(Type *a, Type *b, int left, int right);
	
	int *b = new int[5]();

	~MyClass(){
		delete[] b;
	}
private:


};

template <class Type>
void MyClass<Type> ::Mergesort(Type *a, int left, int right){
	
	if (left < right){
		int i;
		i = (left + right) / 2 ;
		Mergesort(a, left, i) ;
		Mergesort(a, i + 1, right);	
		Merge(a, b, left, i, right);
		Copy(a, b, left, right);
		//delete [] b;
	}
}

template<class Type>
void MyClass<Type>::Merge(Type *a, Type *b, int le, int m, int r){

	int i = le, j = m + 1, k = le;

	while ((i <= m) && (j <= r))
	if (a[i] < a[j])
		b[k++] = a[i++];
	else
		b[k++] = a[j++];

	if (i>m){

		for (int p = j; p <= r; ++p){
			b[k++] = a[p];
		}
	}
	else{
		for (int q = i; q <= m; ++q) {
			b[k++] = a[q];
		}
	}
}

template<class Type>
void MyClass<Type>::Copy(Type *a, Type *b, int left, int right){

	memcpy( a + left, b + left ,(right - left + 1)*sizeof(Type));

}
int main(){

	int a[5] = { 4, 3, 13, 6, 5 };

	MyClass<int> solution;

	solution.Mergesort(a, 0, 4);

	for (int i = 0; i < 5; ++i)
		printf("%d\n", a[i]);

	return 0;
}