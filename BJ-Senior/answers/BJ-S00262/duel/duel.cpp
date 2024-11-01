#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int a[maxn], n, cnt, pre = 1;
long long ans;
pair<int, int>x[maxn];
int main(){
	freopen("duel.in", "r" , stdin);
	freopen("duel.out", "w", stdout);
	cin >> n;
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i];
	}
	sort(a + 1, a+n+1);
	for(int i = 1 ; i <= n ; i++){
		if(a[i] != a[i - 1]){
			cnt++;
			x[cnt].first = a[i];
			x[cnt].second = 1;
		}else{
			x[cnt].second++;
		}
	}
	for(int i = 2 ; i <= cnt ; i++){
		if(x[pre].second > x[i].second){
			x[pre].second -= x[i].second;
		}else{
			int cntt = x[pre].second;
			while(pre < i && x[i].second >= cntt){
				x[pre].second = 0;
				pre++;
				cntt += x[pre].second;
			}
			if(pre == i)continue;
			x[pre].second = cntt - x[i].second;
		}
	}
	for(int i = 1 ; i <= cnt ; i++){
		ans += x[i].second;
	}
	cout << ans << endl;
	return 0;
}
