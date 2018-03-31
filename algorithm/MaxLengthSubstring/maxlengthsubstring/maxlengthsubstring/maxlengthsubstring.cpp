/*****************************

Input : string s
Output : int result 
Interface: int lengthoflongstsrubstring(string s)
Data: 03/31/2018

*******************************/
#include<iostream>
#include<deque>
#include<string>
#include<unordered_set>

using namespace std;

int lengthOfLongestSubstring(string s) {

	int result = 0;
	int count = 0;
	int size_before = 0;

	unordered_set<int> setArray;

	deque<int> vecArray;

	for (int i = 0; i<s.size(); ++i){

		setArray.insert(s[i]);

		vecArray.push_back(s[i]);

		if (setArray.size() == size_before){

			result = result>setArray.size() ? result : setArray.size();

			while (1){

				if (s[i] == vecArray[0])
					break;

				setArray.erase(vecArray[0]);
				vecArray.pop_front();

			}
			vecArray.pop_front();
		}

		if ( i == s.size() - 1) result = result>setArray.size() ? result : setArray.size();
		size_before = setArray.size();

	}
	return result;
}

int main()
{
	string s = "abcagbacefhijkzxy";

	cout << lengthOfLongestSubstring(s) << endl; 

	return 0;
}