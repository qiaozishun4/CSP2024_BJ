#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
const int N = 1e5 + 2;
int n, m, vm;
int v[N], a[N], d[N];
int ce[N];
vector<pair<int, int>> vec;
void mian(){
	vec.clear();
	cin >> n >> m >> vm >> vm;
	for(int i = 1; i <= n; i++){
		cin >> d[i] >> v[i] >> a[i];
	}
	for(int i = 1; i <= m; i++){
		cin >> ce[i];
		ce[i] <<= 1;
	}
	ce[0] = 0;
	ce[m + 1] = 0;
	sort(ce + 1, ce + 1 + m);
	for(int i = 1; i <= n; i++){
		int l = 2, r = 0;
		if(v[i] > vm && a[i] >= 0){
			l = lower_bound(ce + 1, ce + m + 1, (d[i] << 1) - 1) - ce;
			r = m;
		}else if(a[i] > 0){
			l = upper_bound(ce + 1, ce + m + 1, (d[i] << 1) + ((vm * vm - v[i] * v[i]) / (a[i] << 1) << 1) + ((vm * vm - v[i] * v[i]) % (a[i] << 1) != 0)) - ce;
			r = m;
		}else if(v[i] > vm && a[i] < 0){
			l = lower_bound(ce + 1, ce + m + 1, (d[i] << 1) + 1) - ce;
			r = lower_bound(ce + 1, ce + m + 1, (d[i] << 1) + ((v[i] * v[i] - vm * vm) / ((-a[i]) << 1) << 1) + ((v[i] * v[i] - vm * vm) % ((-a[i]) << 1) != 0)) - ce - 1;
		}
		if(l <= r){
			vec.push_back({l, r});
		}
	}
	cout << vec.size() << ' ';
	sort(vec.begin(), vec.end());
	int l = 0;
	int ans = n;
	for(int i = 0; i < vec.size(); i++){
		swap(vec[i].first, vec[i].second);
	}
	for(int i = 0; i < vec.size(); i++){
		while(i < vec.size() && vec[i].first <= l){
			i++;
		}
		if(i >= vec.size()){
			break;
		}
		ans--;
		int l2 = vec[i].second;
		const int tmp = i;
		while(i < vec.size() && vec[i].second <= vec[tmp].second){
			if(vec[i].first <= l){
				i++;
				continue;
			}
			l2 = min(vec[i].second, l2);
			i++;
		}
		l = l2;
	}
	cout << ans << endl;
}
int main(){
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	int t;
	cin >> t;
	for(int i = 1; i <= t; i++){
		mian();
	}
}