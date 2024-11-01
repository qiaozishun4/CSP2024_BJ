#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 10;
int T;
int n,m,L,V;
int d[N];
int v[N];
int a[N];
int ed[N];
bool pt[N];
int pos[N];
void solve1()
{
	int ans = 0;
	int nw[N];
	int tot = 0;
	for(int i = 1;i <= n;i++)
	{
		if(v[i] > V) nw[++tot] = d[i];
	}
	//cout << tot << endl;
	sort(nw + 1,nw + tot + 1);
	sort(pos + 1,pos + m + 1);
	for(int i = tot;i >= 1;i--)
	{
		//cout << nw[i] << endl;
		
		if(pos[m] < nw[i]) ans++;
		else break;
		
	}
	int ans1 = tot - ans;
	cout << ans1 << " ";
	if(ans1 != 0) cout << m - 1 << endl;
	else cout << m << endl;
}
signed main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin >> T;
	while(T--)
	{
		bool flag = 1;
		cin >> n >> m >> L >> V;
		for(int i = 1;i <= n;i++)
		{
			cin >> d[i] >> v[i] >> a[i];
			if(a[i] != 0) flag = 0;
		}
		
		for(int i = 1;i <= m;i++) 
		{
			cin >> pos[i];
	
		}
		if(flag) solve1();
	}
	return 0;
}
