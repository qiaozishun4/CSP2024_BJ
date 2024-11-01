#include <iostream>
#include <cstdio>
#include <set>
using namespace std;
set<string> s;
int n;
int main(void) {
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (string ss;n--;) {
		cin >> ss;
		s.insert(ss);
	}
	cout << 52-s.size();
	return 0;
}