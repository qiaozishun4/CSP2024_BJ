#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 7;
int n;
int r[N];

int main(){
	ios::sync_with_stdio(false);
	freopen("duel.in", "r", stdin); freopen("duel.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; ++i) cin >> r[i];
	sort(r + 1, r + n + 1);
	int j = 0;
	for(int i = 1; i <= n; ++i){
		if(j < n && r[i] > r[j + 1]) j++;
	}
	cout << n - j << endl;
	return 0;
}