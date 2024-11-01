#include <iostream>
#include <map>
using namespace std;
int main() {
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	int n;
	cin >> n;
	string cnt[52] = {
		"DA", "D2", "D3", "D4", "D5", "D6", "D7", "D8", "D9", "DT", "DJ", "DQ", "DK",
		"CA", "C2", "C3", "C4", "C5", "C6", "C7", "C8", "C9", "CT", "CJ", "CQ", "CK",
		"HA", "H2", "H3", "H4", "H5", "H6", "H7", "H8", "H9", "HT", "HJ", "HQ", "HK",
		"SA", "S2", "S3", "S4", "S5", "S6", "S7", "S8", "S9", "ST", "SJ", "SQ", "SK"
	};
	string s;
	int sum = 0;
	map <string, int> ma;
	for (int i = 0; i < n; i++) {
		cin >> s;
		ma[s]++;	
	}
	for (int i = 0; i < 52; i++) {
		if(ma[cnt[i]] == 0) {
			sum += 1;
		}
	}
	cout << sum << endl;
	return 0;
}

