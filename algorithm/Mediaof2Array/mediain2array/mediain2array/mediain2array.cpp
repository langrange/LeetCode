// mediain2array.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
#include <vector>

using namespace std;

double findMedianSortedArrays( vector<int>& a, vector<int>& b) {

	int n = a.size(), m = b.size();
	int result = 0;
	int media = (n + m + 1) / 2;
	vector<int> c(n + m);

	int i = 0, j = 0, k = 0;

	while ((i < n) && (j < m))
	if (a[i] <= b[j])

		c[k++] = a[i++];

	else
		c[k++] = b[j++];

	if ( i>= n){

		for (int p = j; p < m; ++p){
			c[k++] = b[p];
		}
	}
	else{
		for (int q = i; q <n; ++q) {
			c[k++] = a[q];
		}
	}

	if ((n + m) % 2)
		return c[media-1] * 1.0;
	else
		return (c[media-1] + c[media]) / 2.0;

}

int main(){
	vector<int>  a = { 1, 3, 5 };
	vector<int>  b = { 3, 4,5 };

	cout << findMedianSortedArrays(a,b) << endl;

	return 0;
}
