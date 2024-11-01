#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
//const int num_to_cnt[11] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
//pos is num, num is cnt    0, 1, 2, 3, 4, 5, 6, 7, 8, 9
//const int cnt_to_num[11] = {0, 0, 1, 7, 4, 2, 0, 8, 0, 0};
//pos is cnt, num is num    0, 1, 2, 3, 4, 5, 6, 7, 8, 9
int T, n;
//string dp[N + 1];
//string s, minn;
int main() {
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	/*/dp[0] = "-1";
	dp[1] = "-1";
	dp[2] = "1";
	dp[3] = "7";
	dp[4] = "4";
	dp[5] = "2";
	dp[6] = "6";
	dp[7] = "8";
	for(int i = 8; i <= N; i++) {
		int len;
		if(i % 7 == 0) {
			len = i / 7;
			for(int j = 1; j <= len; j++) {
				dp[i].push_back('8');
			}
		} else if(i % 7 == 1) {
			len = i / 7 + 1;
			dp[i].push_back('1');
			dp[i].push_back('0');
			for(int j = 3; j <= len; j++) {
				dp[i].push_back('8');
			}
		} else if(i % 7 == 2) {
			len = i / 7 + 1;
			dp[i].push_back('1');
			for(int j = 2; j <= len; j++) {
				dp[i].push_back('8');
			}
		} else if(i % 7 == 3) {
			len = i / 7 + 1;
			dp[i].push_back('2');
			dp[i].push_back('0');
			dp[i].push_back('0');
			for(int j = 4; j <= len; j++) {
				dp[i].push_back('8');
			}
		} else if(i % 7 == 4) {
			len = i / 7 + 1;
			dp[i].push_back('2');
			dp[i].push_back('0');
			for(int j = 3; j <= len; j++) {
				dp[i].push_back('8');
			}
		} else if(i % 7 == 4) {
			len = i / 7 + 1;
			dp[i].push_back('2');
			dp[i].push_back('0');
			for(int j = 3; j <= len; j++) {
				dp[i].push_back('8');
			}
		} else if(i % 7 == 5) {
			len = i / 7 + 1;
			dp[i].push_back('2');
			for(int j = 2; j <= len; j++) {
				dp[i].push_back('8');
			}
		} else if(i % 7 == 6) {
			len = i / 7 + 1;
			dp[i].push_back('6');
			for(int j = 2; j <= len; j++) {
				dp[i].push_back('8');
			}
		}
		cout << "i:" << i << " dp[i]:" << dp[i] << endl;
	}/*/
	cin >> T;
	while(T--) {
		cin >> n;
		int len;
		if(n == 0) cout << "-1";
		else if(n == 1) cout << "-1";
		else if(n == 2) cout << "1" ;
		else if(n == 3) cout << "7";
		else if(n == 4) cout << "4";
		else if(n == 5) cout << "2";
		else if(n == 6) cout << "6" ;
		else if(n == 10) cout << "22";
		else if(n % 7 == 0) {
			len = n / 7;
			for(int i = 1; i <= len; i++) cout << "8";
		} else if(n % 7 == 1) {
			len = n / 7 + 1;
			cout << "10";
			for(int i = 3; i <= len; i++) cout << "8";
		} else if(n % 7 == 2) {
			len = n / 7 + 1;
			cout << "1";
			for(int i = 2; i <= len; i++) cout << "8";
		} else if(n % 7 == 3) {
			len = n / 7 + 1;
			cout << "200";
			for(int i = 4; i <= len; i++) cout << "8";
		} else if(n % 7 == 4) {
			len = n / 7 + 1;
			cout << "20";
			for(int i = 3; i <= len; i++) cout << "8";
		} else if(n % 7 == 5) {
			len = n / 7 + 1;
			cout << "2";
			for(int i = 2; i <= len; i++) cout << "8";
		} else if(n % 7 == 6) {
			len = n / 7 + 1;
			cout << "6";
			for(int i = 2; i <= len; i++) cout << "8";
		}
		cout << endl;
	}
	return 0;
}