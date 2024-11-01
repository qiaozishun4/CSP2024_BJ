#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int T;
int n;
long long dp[N];

int main(){
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	
	cin >> T;

	dp[1] = 2000000000;
	dp[0] = 0;
	for(int i = 8; i <= 100000; i ++) dp[i] = 2000000000;
	dp[2] = 1;
	dp[3] = 7;
	dp[4] = 4;
	dp[5] = 2;
	dp[6] = 6;
	dp[7] = 8;	
	for(int i = 8; i <= 100000; i ++){
//		cout << dp[i - 1] << endl;
		for(int j = 2; j <= 7; j ++){
			if(dp[i - j] >= 2000000000) continue;
			dp[i] = min(dp[i], dp[i - j] * 10 + dp[j]);
			if(dp[j] == 6 && dp[i - j] != 0) dp[i] -= dp[j]; 
//			if(i == 12) cout << dp[i] << ' ' << i - j << ' ' << j << endl;	
		}
	}	
	

	while(T --){
		cin >> n;
		if(n % 10 == 0){
			for(int i = 0; i < n / 10; i ++) cout << 8;
			puts("");
		}
		else if(dp[n] == 2000000000) cout << -1 << endl;
		else cout << dp[n] << endl;
	}
	return 0;
}