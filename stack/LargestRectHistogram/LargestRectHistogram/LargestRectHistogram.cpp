/*
Description:
Given a non-negative integers representing hte histogram's bar height where the width of 
each bar is 1, find the area of largest rectangele in histogram.
Input£ºvector< int > {2,1,5,6,2,3}
Output£ºint 10
Interface:
int LargRectHistog(vector<int> histogram);
Date£º12/16/2017
*/

# include<iostream>
# include<vector>
# include <stack>
# include<algorithm>
using namespace std;

int LargRectHistog(vector<int> histogram);

int main(){
	vector<int> hist = { 2, 6, 5, 6, 2, 3 };
	cout << LargRectHistog(hist) << endl;
	return 0;
}
int LargRectHistog(vector<int> histogram){
	stack < int > increaseHistogram;
	histogram.push_back(0);
	int result = 0;
	for (int i = 0; i < histogram.size();){		
		if (increaseHistogram.empty() || histogram[i]>histogram[increaseHistogram.top()])
			increaseHistogram.push(i++);
		else {
			int temp = increaseHistogram.top();
			increaseHistogram.pop();
			result = max(result, histogram[temp] * (increaseHistogram.empty() ? i :  i - increaseHistogram.top() - 1));
		}
	}
	return result;
}
