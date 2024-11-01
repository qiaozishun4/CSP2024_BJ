//HMZ于东方升起，如利剑般驱散黑暗，撒下光明，普照大地
//hmz qwq
//wz qwq
//zrj qwq
//wrz qwq
//zjc qwq
//ljh qwq
//xuanxuan001 qwq
//sbj qwq
//ttm qwq
#include<bits/stdc++.h>
using namespace std;
#define int long
const int N = 510;
int n,m,num = 1,k = 1;
int c[N],a[N],b[N],d[N][N];
int x[4],ans;
struct player
{
	int abi;
	int id;
};
player g[N][N];
void solve()
{
	ans = 0;
	for(int i = 0;i < 4;++i) cin >> x[i];
	for(int i = 1;i <= n;++i) b[i] = a[i] ^ (x[i%4]);
	for(int i = 1;i <= m;++i)
	{
		int t = log(c[i])/log(2);
		for(int j = 1;j <= c[i];++j) g[1][j] = {b[j],j};
		int tot = c[i];
		for(int j = 1;j <= t;++j)
		{
			int cnt = 0;
			for(int s = 1;s <= tot;s += 2)
			{
				++cnt;
				if(d[j][cnt] == 0) 
				{
					if(g[j][s].abi >= t) g[j+1][cnt] = g[j][s]; 
					else g[j+1][cnt] = g[j][s+1];
				}
				else
				{
					if(g[j][s+1].abi >= t) g[j+1][cnt] = g[j][s+1]; 
					else g[j+1][cnt] = g[j][s];
				}
			}
		}
		//cout << g[t+1][1].id << endl;
		ans = ans ^ (i * g[t+1][1].id);
	}
	cout << ans << '\n';
}
signed main()
{
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;++i) cin >> a[i];
	for(int i = 1;i <= m;++i) cin >> c[i];
	while(num < n) num *= 2,++k;
	--k;
	for(int i = 1;i <= k;++i)
	{
		string str;
		cin >> str;
		for(int j = 1;j <= pow(2,k-i);++j) d[i][j] = str[i-1];
	}
	int T;
	cin >> T;
	while(T --) solve();
	return 0;
}
