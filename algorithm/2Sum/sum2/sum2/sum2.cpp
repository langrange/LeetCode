// sum2.cpp : 定义控制台应用程序的入口点。
//
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target){
	vector<int> numReturn;
	int sub1 = 0;
	int size = nums.size();
	vector<int> subArray(size, 0);

	unordered_set<int> mSet;

	for (int i = 0; i<size; ++i){
		subArray[i] = target - nums[i];
		mSet.insert(nums[i]);
	}
	//遍历较长的那个数组  
	for (int i = 0; i < size; i++)
	{
		//注意调用set的find方法，这个方法会通过计算Hash值来比较  
		if (mSet.end() != mSet.find(subArray[i]))
		{
			numReturn.push_back(i);
			sub1 = subArray[i];
			break;
		}

	}
	for (int i = 0; i<size; i++){
		if (sub1 == nums[i]){
			numReturn.push_back(i);
			break;
		}
	}
	return numReturn;

}
	
int main(){

	vector<int> input = { 3, 4, 5, 2, 9 };
	int target =8;
	auto result = twoSum(input, target);
	cout << result[0] << '\t' << result[1] << endl;;
	return 0;

}