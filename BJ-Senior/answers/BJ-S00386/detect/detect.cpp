#include<bits/stdc++.h>
using namespace std;
const int N = 100010,M = 1000010;
int n,m,s,l,cnt1,cnt2,tot,ans1,ans2;
bool st[M][23];
int Lg[M];
int p[N];
int d[N],v[N],a[N];
struct segment
{
	int l,r;
};
segment seg[N];
inline int lg(int l,int r)
{
	//int k = log(r-l+1)/log(2);
	return Lg[r-l+1];
	//return k;
}
inline bool query(int l,int r)
{
	int k = lg(l,r);
	bool res = st[l][k] |st[r-(1<<k)+1][k];
	return res;
}
inline void solve1(int x)
{
	if(v[x] <= s) return ;
	if(d[x] > p[m]) return ;
	//cout << "ok1 " << x << endl;
	++ans1;
	int ls = 1,rs = m;
	while(ls < rs)
	{
		int mid = ls + rs >> 1;
		if(p[mid] >= int(d[x])) rs = mid;
		else ls = mid + 1;
	}
	cnt1 = max(cnt1,ls);
}
inline void solve2(int x)
{
	int k;
	if(v[x] > s) k = d[x];
	else k = d[x] + int((s*s - v[x]*v[x])/(2*a[x])) + 1;
	if(k > p[m]) return ;
	//cout << "ok2 " << x << endl;
	++ans1;
	int ls = 1,rs = m;
	while(ls < rs)
	{
		int mid = ls + rs >> 1;
		if(p[mid] >= k) rs = mid;
		else ls = mid + 1;
	}
	cnt1 = max(cnt1,ls);
}
inline void solve3(int x)
{
	if(v[x] <= s) return ;
	int k = d[x] + int((s*s - v[x]*v[x])/(2*a[x]));
	if((abs(int(s*s - v[x]*v[x])))%(abs(int(2*a[x]))) == 0) k --;
	k = min(k,int(p[m]));
	//cout << "ok3 " << x << ' ' << k << endl;
	if(!query(d[x],k)) return ;
	++ans1;
	int ls1 = 1,rs1 = m;
	while(ls1 < rs1)
	{
		int mid = ls1 + rs1 >> 1;
		if(p[mid] >= d[x]) rs1 = mid;
		else ls1 = mid + 1;
	}
	int ls2 = 1,rs2 = m;
	while(ls2 < rs2)
	{
		int mid = ls2 + rs2 + 1 >> 1;
		if(p[mid] <= k) ls2 = mid;
		else rs2 = mid - 1;
	}
	seg[++tot] = {ls1,ls2};
}
bool cmp(segment x,segment y)
{
	return x.l < y.l;
}
void solve()
{
	cnt1 = cnt2 = -1;
	tot = 0;
	ans1 = ans2  = 0;
	cin >> n >> m >> l >> s;
	for(int i = 1;i <= n;++i) cin >> d[i] >> v[i] >> a[i];
	for(int i = 1;i <= m;++i) cin >> p[i];
	for(int i = 1;i <= m;++i) st[int(p[i])][0] = true;
	for(int i = 1;i <= 21;++i) 
		for(int j = 1;j + (1<<i) - 1 <= l;++j)
			st[j][i] = st[j][i-1] | st[j+(1<<(i-1))][i-1];
	for(int i = 1;i <= n;++i) 
	{
		if(a[i] == 0) solve1(i);
		else if(a[i] > 0) solve2(i);
		else solve3(i);
	}
	cout << ans1 << ' '; 
	if(ans1 == 0)
	{
		cout << m << '\n';
		return ;
	}
	if(cnt1 != -1) seg[++tot] = {cnt1,m};
	sort(seg+1,seg+tot+1,cmp);
	ans2 = 1;
	int tail = seg[1].r;
	for(int i = 2;i <= tot;++i)
	{
		if(seg[i].l <= tail) tail = min(seg[i].r,tail);
		else
		{
			tail = seg[i].r;
			++ans2;
		}
	}
	//for(int i = 1;i <= tot;++i) cout << seg[i].l << ' ' << seg[i].r << endl;
	cout << m - ans2 << '\n';
	for(int i = 0;i <= 21;++i) 
		for(int j = 1;j + (1<<i) - 1 <= l;++j)
			st[j][i] = 0;
}
int main()
{	
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	for(int i = 0;i <= 1000000;++i) Lg[i] = log(i)/log(2);
	while(T --)
	{
		//memset(st,0,sizeof(st));
		solve();
	}
	return 0;
}
