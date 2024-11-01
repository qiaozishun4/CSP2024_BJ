#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MX = 1e5 + 7;
ll d[MX],v[MX],a[MX];
ll p[MX];bool mark[MX];
int id[MX],nxt[MX];
ll read(){
	ll x = 0,ch = getchar(),f = 1;
	while(!(ch >= 48 && ch <= 57)){
		if(ch == '-')f = -1;
		ch = getchar();
	}
	while(ch >= 48 && ch <= 57)x = x * 10 + ch - 48,ch = getchar();
	return x * f;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T = read();
	while(T--){
		int n,m;ll L,V;n = read();m = read();L = read();V = read();
		for(int i = 1;i <= n;i++){d[i] = read();v[i] = read();a[i] = read();}
		for(int i = 1;i <= n;i++)id[i] = i;sort(id + 1,id + 1 + n,[&](int x,int y){return d[x] < d[y];});
		for(int i = 1;i <= m;i++)p[i] = read();
		int ans1 = 0,ans2 = 0;
		int t = 1;
		for(int it = 1;it <= n;it++){
			int i = id[it];
			while(t <= m && p[t] < d[i])t++;
			nxt[i] = t;
			if(a[i] >= 0){
				if(d[i] > p[m])continue;
				if(v[i] * v[i] + 2 * a[i] * (p[m] - d[i]) > V * V){mark[i] = true;ans1++;}
			}
			else{
				if(t > m)continue;
				ll Y = p[t];
				if(v[i] * v[i] + 2 * a[i] * (Y - d[i]) > V * V){mark[i] = true;ans1++;}
			}
		}
		int posa = 0;
		for(int it = n;it >= 1;it--){
			int i = id[it];
			if(mark[i] && a[i] >= 0)
				while(posa <= m && (posa == 0 || p[posa] < d[i] || v[i] * v[i] + 2 * a[i] * (p[posa] - d[i]) <= V * V))posa++;
		}
		if(ans1){
			int las = posa;ans2 = 1;
			for(int it = n;it >= 1;it--){
				int i = id[it];
				if(!mark[i] || a[i] >= 0)continue;
				if(p[las] < d[i] || v[i] * v[i] + 2 * a[i] * (p[las] - d[i]) <= V * V){
					if(p[las] >= d[i]){las = nxt[i];ans2++;}
					else las = nxt[i];
				}
			}
		}
		cout << ans1 << ' ' << m - ans2 << '\n';
		memset(d,0,sizeof(d));memset(v,0,sizeof(v));memset(a,0,sizeof(a));
		memset(mark,0,sizeof(mark));
		memset(p,0,sizeof(p));memset(id,0,sizeof(id));memset(nxt,0,sizeof(nxt));
	}
}