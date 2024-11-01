#include<bits/stdc++.h>
using namespace std;

const int maxn = 100;
int n, ans;

string pokers[maxn];

int main(){
	freopen("poker.in", "r", stdin);
	freopen("poker.out","w",stdout);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> pokers[i];
	sort(pokers + 1, pokers + n + 1);
	int tot = 0;
	for(int i = 1; i <= n; i++)
		if(tot == 0 || pokers[i] != pokers[tot])
			pokers[++tot] = pokers[i];
	// for(int i = 1; i <= tot; ++i) cout << pokers[i] << '\n';
	cout << 52 - tot << '\n';
	return 0;
}