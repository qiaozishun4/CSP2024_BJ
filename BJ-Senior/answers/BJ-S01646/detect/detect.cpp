#include <cstdio>
#include <algorithm>
#include <cstring>
#define int long long
using namespace std;
const int N = 1e5 + 5;
int n, m, L, V;
int pos[N];
int pho[N * 10];
bool will_ex[N];
struct car{
	int d, v, a;
	bool we;
	int st, en;
	int fi, se;
} t[N];
void deal1(){
	int ans = 0;
	for(int i = 1; i <= n; i++){
		t[i].we = 0;
		if(t[i].a < 0){
			if(t[i].v > V){
				int z = (t[i].v * t[i].v - V * V) / (-2 * t[i].a) - (int)(bool)(!((t[i].v * t[i].v - V * V) % (-2 * t[i].a)));
				t[i].we = 1;
				if(z + t[i].d <= L) t[i].st = t[i].d, t[i].en = z + t[i].d;
				else t[i].st = t[i].d, t[i].en = L;
			}
		}
		
		if(!t[i].a) if(t[i].v > V) t[i].st = t[i].d, t[i].en = L, t[i].we = 1;
		if(t[i].a > 0){
			if(t[i].v > V) t[i].st = t[i].d, t[i].en = L, t[i].we = 1;
			else{
				int z = (V * V - t[i].v * t[i].v) / (2 * t[i].a) + 1;
				if(z + t[i].d <= L) t[i].st = z + t[i].d, t[i].en = L, t[i].we = 1;
			}
		}
	}
	for(int i = 1; i <= n; i++) if(t[i].we){
		if(t[i].en == t[i].st && pho[t[i].en] == pho[t[i].en - 1]) t[i].we = 0;
		else if(!(pho[t[i].en] - pho[t[i].st]) && !(pho[t[i].st] - pho[t[i].st - 1])) t[i].we = 0;
		else ans++;// printf("%d %d %d\n", i, t[i].st, t[i].en);
	}
	/*
	printf("\n");
	for(int i = 1; i <= n; i++) if(t[i].we) printf("%d ", i);
	printf("\n");
	*/
	printf("%lld ", ans);
	return;
}
bool cmp(car x, car y){
	return x.se < y.se;
}
void deal2(){
	car tmp[N];
	int num = 0, ans = 0, maxx = 0;
	for(int i = 1; i <= n; i++){
		if(!t[i].we) continue;
		t[i].fi = pho[t[i].st];
		if(!(pho[t[i].st] - pho[t[i].st - 1])) t[i].fi++;
		t[i].se = pho[t[i].en];
		tmp[++num].fi = t[i].fi, tmp[num].se = t[i].se;
		//printf("i=%d fi=%d se=%d\n", i, t[i].fi, t[i].se);
	}
	sort(tmp + 1, tmp + num + 1, cmp);
	for(int i = 1; i <= num; i++){
		if(maxx < tmp[i].fi) ans++, maxx = tmp[i].se;
	}
	printf("%lld", m - ans);
	return;
}
void solve(){
	scanf("%lld%lld%lld%lld", &n, &m, &L, &V);
	memset(pho, 0, sizeof(pho));
	for(int i = 1; i <= n; i++) scanf("%lld%lld%lld", &t[i].d, &t[i].v, &t[i].a);
	for(int i = 1; i <= m; i++) scanf("%lld", &pos[i]), pho[pos[i]] = 1;
	for(int i = 1; i <= 1e6; i++) pho[i] += pho[i - 1];
	deal1();
	deal2();
	return;
}
void open(){
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	return;
}
void close(){
	fclose(stdin);
	fclose(stdout);
	return;
}
signed main(){
	open();
	int t;
	scanf("%lld", &t);
	while(t--) solve(), printf("\n");
	close();
	return 0;
}
/*
9 
1 1
4 4
3 4
4 5
4 5
5 6
4 6
6 6
6 8
7

9 
1 1
4 4
3 4
4 5
4 5
5 6
4 6
6 6
6 8
6
*/