#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int rst = n;
	vector<string> words(n);

	for (int i = 0; i < n; i++) {
		cin >> words[i];
	}
	for (int i = 0; i < words.size(); i++) {
		if (words[i].size() == 1) continue;
		map<char, int> check;
		check[words[i].at(0)] = 1;
		for (int j = 1; j < words[i].size(); j++) {
			if (words[i].at(j) == words[i].at(j - 1)) {
				continue;
			}
			else {
				if (check.find(words[i].at(j)) == check.end()) {
					check[words[i].at(j)] = 1;
				}
				else {
					rst--;
					break;
				}
			}
		}
	}
	cout << rst;
}