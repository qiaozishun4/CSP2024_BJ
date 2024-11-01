#include<bits/stdc++.h>
using namespace std;
set<string> s;
int main() {
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	int n;
	cin >> n;
	string c;
	for (int i = 1; i <= n; i++) {
		cin >> c;
		s.insert(c);
	}
	cout << 52 - s.size();
	return 0;
}
