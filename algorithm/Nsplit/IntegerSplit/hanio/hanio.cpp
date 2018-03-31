#include <iostream>

using namespace std;

// 声明整数划分函数
int IntSplit(int n);

int main(){
	
	int n;
	cout << "input integer is:";
	cin>>n;
	cout << "the devided result is :";
	cout << IntSplit(n) << endl;
	return 0;

}


int IntSplit2(int n ,int m){
     
	if (1 == m) return 1;

	if (n == m) return 1 + IntSplit2(n, n - 1);
	
	if (m > n){
		return IntSplit2(n, n);
	}else{
		return IntSplit2(n, m - 1) + IntSplit2(n - m, m);
	}

}

int IntSplit(int n){
	
	if (!(n > 0)){
		return 0;
	}
	else{
		return IntSplit2(n, n);
	}
}
