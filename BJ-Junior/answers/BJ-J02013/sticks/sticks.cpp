#include <bits/stdc++.h>

using namespace std;

const int mp[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
const int INF = 1e9 + 7;

int T;

int n;
int num = 0;
int ans;
bool flag;

void DFS(int stick){
	if(stick == 0&&num != 0){
		ans = min(ans, num);
		return;
	}
	if(stick < 2)
		return;
	for(int k = 0;k <= 9;k++){
		if(stick < mp[k])
			continue;
		if((k == 0&&num > 0)||(k != 0)){
			num = (num * 10) + k;
			DFS(stick-mp[k]);
		}
		num = (num - k) / 10;
	}
}

int main(){
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	cin >> T;
	while(T--){
		cin >> n;
		ans = INF;
		DFS(n);
		if(ans == INF)
			cout << "-1" << endl;
		else
			cout << ans << endl;
	}

	return 0;
}