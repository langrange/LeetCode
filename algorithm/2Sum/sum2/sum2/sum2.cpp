// sum2.cpp : �������̨Ӧ�ó������ڵ㡣
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
	//�����ϳ����Ǹ�����  
	for (int i = 0; i < size; i++)
	{
		//ע�����set��find���������������ͨ������Hashֵ���Ƚ�  
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