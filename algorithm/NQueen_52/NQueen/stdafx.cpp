# include<iostream>
# include<vector>
using namespace std;
	
void Queen(int k, int n, int *x, int &sum){

		if (k == n + 1)
		{
			sum++;
			return;
		}

		for (int i = 1; i<n + 1; i++){

			bool flag = false;
			for (int j = 1; j<k; j++){
				if (i == x[j] || abs(i - x[j]) == abs(k - j)) break;
				if (j == (k - 1)) flag = true;
			}

			if (flag || k == 1){
				x[k] = i;
				Queen(k + 1, n, x, sum);
			}

		}
	}

	int totalNQueens(int n) {
		int sum = 0;
		//vector<int> x(n+1);
		int * x = new int[n+1];
		for (int i = 0; i<n + 1; i++) x[i] = -2;
		Queen(1, n, x, sum);
		delete x;
		return sum;
	}

	int main(){
		int n = 8;
		cout << totalNQueens(n) << endl;

	}