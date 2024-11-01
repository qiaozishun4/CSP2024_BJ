#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	int T;
	cin >> T;
	while (T -- ) {
		int n;
		cin >> n;
		string ans;
		if (n <= 49) {
			char tmp[100][9] = {"-1", "-1", "1", "7", "4", "2", "6", "8", "10", "18", "22", "20", "28", "68", "88", "108", "188", "200", "208", "288", "688", "888", "1088", "1888", "2008", "2088", "2888", "6888", "8888", "10888", "18888", "20088", "20888", "28888", "68888", "88888", "108888", "188888", "200888", "208888", "288888", "688888", "888888", "1088888", "1888888", "2008888", "2088888", "2888888", "6888888", "8888888"};
			ans = tmp[n];
			reverse(ans.begin(), ans.end());
		} else {
			for (int i = 0; i < (n / 7); i ++ ) ans += "8";
			int x = n % 7;
			ans.erase(ans.end() - 1);
			char tmp[7][3] = {"8", "01", "81", "22", "02", "82", "86"};
			ans.append(tmp[x], strlen(tmp[x]));
		}
		reverse(ans.begin(), ans.end());
		cout << ans << endl;
	}
	return 0;
}
