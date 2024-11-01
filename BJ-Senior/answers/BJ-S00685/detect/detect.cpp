#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T, p[N], n, m, L, V, d[N], v[N], a[N], x, ans1, ans2;
int num[N];
struct Tr{int l, r, sum; } tr[N*40];
inline void Reload(int p){
	tr[p].sum=tr[p<<1].sum+tr[(p<<1)+1].sum;
}
void Build(int pp, int l, int r){
	tr[pp].l=l;
	tr[pp].r=r;
	if(l==r){
		tr[pp].sum=p[l];
		return ;
	}
	int mid=(l+r)>>1;
	Build(pp<<1, l, mid);
	Build((pp<<1)+1, mid+1, r);
	Reload(pp);
	return ;
}
int Query(int p, int s, int t){
	int l=tr[p].l, r=tr[p].r;
	if(s<=l && r<=t){
		return tr[p].sum;
	}
	int mid=(l+r)>>1, cnt=0;
	if(s<=mid) cnt+=Query(p<<1, s, t);
	if(r>mid) cnt+=Query((p<<1)+1, s, t);
	return cnt;
}
inline void Check(int l, int r, int i)
{
	num[i]=Query(1, l, r);
	if(num[i]>=1)
		++ans1;
	if(num[i]%2==0&&num[i]>1)
		ans2--;
}
int main()
{
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	cin >> T;
	//cout << 'T' << T << '\n';
	while(T--){
		//cout << 'T' << T << '\n';
		cin >> n >> m >> L >> V;
		ans2 = m;
		ans1=0;
		memset(p, 0, sizeof(p));
		for(int i=1; i<=n; ++i){
			cin >> d[i] >> v[i] >> a[i];
		}
		for(int i=1; i<=m; ++i){
			cin >> x;
			if(p[x]==0) ++p[x];
			else --ans2;
		}
		Build(1, 1, L);
		for(int i=1; i<=n; ++i){
			if(a[i]==0){
				if(v[i]>V)
					Check(d[i], L, i);
				continue;
			}
			if(v[i]==V && a[i]>0){
				if(d[i]!=L)
				Check(d[i+1], L, i);
			}
			else if(v[i]<V && a[i]>0){
				double t=1.0*(V-v[i])/a[i];
				double s=v[i]*t+0.5*a[i]*t*t;
				if(d[i]+floor(s)>L) s=L-d[i];
				Check(d[i]+floor(s), L, i);
				//cout << d[i] << " aa " << s << '\n';
			}
			else if(v[i]>V && a[i]<0){
				double t=1.0*(v[i]-V)/(-a[i]);
				double s=v[i]*t+0.5*a[i]*t*t;
				if(d[i]+floor(s)>L) s=L-d[i];
				Check(d[i], floor(s)+d[i], i);
				//cout << d[i] << " rr " << s << '\n';
			}
			else if(v[i]>V && a[i]>0){
				Check(d[i], L, i);
			}
		}
		cout << ans1 << ' ' << ans2 << '\n';
	}
	return 0;
}