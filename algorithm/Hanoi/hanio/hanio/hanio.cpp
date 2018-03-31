#include <iostream>

using namespace std;

// ÉùÃ÷ººÅµËşº¯Êı 
void hanio(int n, int a, int b, int c);

int main(){
	unsigned int n = 4;
	int a = 1, b = 2, c = 3;
	hanio(n, a, b, c);
	return 0;
}
void hanio(int n, int a, int b, int c){
    char charb = a + 'a'-1;
	char chare = b + 'a'-1;

	if (1 == n){
		//cout << charb << chare << endl;
		printf("%c-->%c\n", charb, chare);
		return;
	}
	
	hanio(n - 1, a, c, b);
	//cout << charb << chare << endl ;
	printf("%c-->%c\n", charb, chare);
	hanio(n - 1, c, b, a);
}


