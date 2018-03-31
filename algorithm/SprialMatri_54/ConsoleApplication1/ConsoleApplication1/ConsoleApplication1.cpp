#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		int row = matrix.size();
		int column = matrix[0].size();

		vector<int> result;
		bool *seen = new bool[row*column];
		for (int i = 0; i < row*column; i++){
			seen[i] = false;
		}
		int dr[4] = { 0, 1, 0, -1 };
		int dc[4] = { 1, 0, -1, 0 };
		// init the condition
		int rr = 0, rc = 0, di = 0;
		for (int i = 0; i<row*column; i++){
			cout << i << endl;
			result.push_back(matrix[rr][rc]);
			seen[rr*column+rc] = true;
			int rtemp = rr + dr[di];
			int ctemp = rc + dc[di];
			if (rtemp >= 0 && rtemp<row&ctemp >= 0 && ctemp<column&&!seen[rtemp*column+ctemp]){
				rc = ctemp;
				rr = rtemp;
			}
			else{
				di = (di + 1) % 4;
				rr += dr[di];
				rc += dc[di];
			}
		}

		return result;

	}

};

int main(){

	vector<vector<int> > matrix = {
		{ {1,2,3,4,5,6,7,8,9} }
	};

	Solution *solv = new Solution;
	vector<int> result = solv->spiralOrder(matrix);
	cout << result[1] << endl;
	return 0;
}

