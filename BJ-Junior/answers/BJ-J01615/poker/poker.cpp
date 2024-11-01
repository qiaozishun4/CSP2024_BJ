#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const char color[] = "DCSH";
const char num[] = "A23456789TJQK";

bool st[256][256];

int main() {
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	int n;
	cin >> n;
	while (n -- ) {
		string s;
		cin >> s;
		st[s[0]][s[1]] = 1;
	}
	int cnt = 0;
	for (int i = 0; i < 4; i ++ ) {
		for (int j = 0; j < 13; j ++ ) {
			if (!st[color[i]][num[j]]) {
				cnt ++ ;
			}
		}
	}
	cout << cnt << endl;
	return 0;
}
