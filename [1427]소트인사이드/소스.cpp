#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;
bool desc(int a, int b) {
	return a > b;
}
int main() {
	ios_base::sync_with_stdio(false);
	int n;
	stack<char> s;
	vector<int> v;
	cin >> n;
	while (n > 0) {
		s.push(n % 10);
		n /= 10;
	}
	while (!s.empty()) {
		v.push_back(s.top());
		s.pop();
	}
	sort(v.begin(), v.end(), desc);
	for (int i = 0; i < v.size(); i++) {
		cout << v[i];
	}
}