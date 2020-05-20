#include <iostream>
#include <string>

using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	string word;
	string Croatia[8] = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };
	int rst = 0;
	cin >> word;

	for (int i = 0; i < 8; i++) {
		if (word.find(Croatia[i]) != string::npos) {
			word.replace(word.find(Croatia[i]), Croatia[i].size(), ".");
			i--;rst++;
		}
	}
	for (int i = 0; i < word.size(); i++) {
		if (word[i] != '.') rst++;
	}
	cout << rst;
}