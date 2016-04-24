#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
 
bool cmp(string s1, string s2){
	int i = 0,j = 0;
	while(i < s1.length() && j < s2.length()){
		if(s1[i] == s2[j]){
			i++; j++;
			continue;
		}
		else return (s1[i] < s2[j]);
	}
	return (s1.length() <= s2.length());
}
 
int main() {
	int t;
	vector<string> V;
	string input;
	cin >> input;
	int l1 = input.length();
	cin >> t;
	getchar();
	while(t--){
		string checkstr;
		getline(cin, checkstr);
		int l2 = checkstr.length();
		if (l2 >= l1 && checkstr.substr(l2 - l1, l2) == input){
			V.push_back(checkstr);
		}
	}
	if(!V.size()){
		cout << "Wrong fingerprints!" << endl;
	}
	else{
		sort(V.begin(), V.end(), cmp);
		cout << V.size() << endl;
		for(vector<string>::iterator it = V.begin(); it!=V.end(); it++){
			cout << *it << endl;
		}
	}
	return 0;
} 
