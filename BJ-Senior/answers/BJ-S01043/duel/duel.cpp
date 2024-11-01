#include <iostream>
using namespace std;
const int maxn = 1e5;

int a,n,cnt[maxn + 5];

int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n; i++){
		cin >> a;
		cnt[a]++;
	}
	int ans = 0;
	for(int i = 1;i <= maxn; i++) ans = max(ans,cnt[a]);
	cout << ans << endl;
	
	return 0;
}
/*

*/