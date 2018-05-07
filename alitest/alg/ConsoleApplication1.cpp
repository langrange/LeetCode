#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		int row = matrix.size();
		int column = matrix[0].size();

		vector<int> result(100,0);
		
        bool *seen = new bool[row*column];
		
        for (int i = 0; i < row*column; i++){
			seen[i] = false;
		}
		
        int dr[4] = { 0, 1, 0, -1 };
		int dc[4] = { 1, 0, -1, 0 };
		
        // init the condition
		int rr = 0, rc = 0, di = 0;

        for (int i = 0; i<row*column; i++){
		//	cout << i << endl;
			result[rr*column + rc] = matrix[i/row][i%column] ;
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

	vector<vector<int> > matrix(10,vector<int>(10,0));

    for(int i=0;i<100;++i)
        matrix[i/10][i%10] = i+1 ;

   /* for(int i=0;i<10;++i){
        cout << matrix[i/10][i%10] ;
        if(i%10==10)
        cout << endl ;
        else
        cout << '\t' ;

    }*/
    Solution *solv = new Solution;
	vector<int> result = solv->spiralOrder(matrix);
	//cout << result[1] << endl;
    // cout << result.size() << endl ;
    int count = 0;
    
    for(int i=0;i<100;++i){
        if((i/10)==(i%10))
        count += result[i] ;
        cout << result[i] ;
        if ((i%10)==9)
            cout << endl;
        else
            cout << '\t';
    }

    cout << "the result is : " << count << endl ;
    
    return 0;
}

