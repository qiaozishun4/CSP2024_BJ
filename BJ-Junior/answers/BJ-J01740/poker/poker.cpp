#include <iostream>
#include <cstdio>
#include <map>
#include <string>
using namespace std;

int n, cnt;
map <string, bool> mp;
string s;

int main() {
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> s;
		if (!mp[s]) {
			cnt++;
			mp[s] = 1;
		}
	}
	cout << 52 - cnt;
	return 0;
}
