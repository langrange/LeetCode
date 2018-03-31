	/*Given an array of strings, return all groups of strings that are anagrams.
	   Note: All inputs will be in lower - case.
	   For example :
	   Input : ["tea", "and", "ate", "eat", "den"]
	   Output : ["tea", "ate", "eat"]
	   Interface : vector<string>anagrams(vector<string>&strs);   */

# include <iostream>
# include <vector>
# include <unordered_map>
# include <algorithm>
#include <iterator>
#include <string>

using namespace std;

vector<string> anagrams(vector<string> & strs);
int main(){
	vector <string > testStr = { "fuck", "eat", "teta", "good", "doog" };
	vector <string> outStr = anagrams(testStr) ;
	copy(outStr.begin(), outStr.end(), ostream_iterator<string>(cout, " "));
	return 0;
}

vector<string> anagrams(vector<string> & strs){
	unordered_map <string, vector<string>> group;
	for (auto &s : strs){
		string key = s;
		sort(key.begin(), key.end());
		group[key].push_back(s);
	}

	vector < string > reString;
	for (auto it = group.cbegin(); it != group.cend(); it++){
		if (it->second.size() > 1){ 
			reString.insert(reString.end(), it->second.cbegin(), it->second.cend());
		}
	}
	return reString;
}