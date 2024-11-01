#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
long long n, m, l, vmax, cntz, cntf, pp[maxn], cnttt;
struct node{
	long long st, ed;
}f[maxn], z[maxn];
struct node2{
	int in, v, ad;
}a[maxn];
void init(int in, int v, int ad){
	if(ad > 0){
		if(v > vmax){
			if(in <= pp[m]){
				cntz++;
			}
			return ;
		}
		long long tmp = double(double(vmax) * double(vmax) - double(v) * double(v)) / 2 / double(ad) + 1;
		tmp += in;
		if(tmp <= pp[m]){
			cntz++;
		}
	}else if (ad == 0 && v > vmax && in <= pp[m]){
		cntz++;
	}
}
int main(){
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	int t;
	cin >> t;
	while(t--){
		cntz = cntf = 0;
		for(int i = 0 ; i < maxn ; i++){
			f[i].ed = f[i].st = z[i].ed = z[i].st = pp[i] = a[i].in = a[i].v = a[i].ad = 0;
		}
		cin >> n >> m >> l >> vmax;
		for(int i = 1 ; i <= n ; i++){
			cin >> a[i].in >> a[i].v >> a[i].ad;
		}
		for(int i = 1 ; i <= m ; i++){
			cin >> pp[i];
		}
		sort(pp+1, pp+m+1);
		for(int i = 1 ; i <= n ; i++){
			init(a[i].in, a[i].v, a[i].ad);
		}
		cout << cntz + cntf << ' ';
		if(cntz == 0)cout << m << endl;
		else cout << m - 1 << endl;
		continue;
		
	}
}
