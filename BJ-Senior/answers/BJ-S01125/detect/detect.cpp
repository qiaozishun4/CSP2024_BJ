#include <bits/stdc++.h>
using namespace std;
int n,m,L,V;
struct Car{
	int d,v,a;
}c[100005];
bool vis[100005];
int p[100005],dk[100005];
int mink[100005],maxk[100005];
void solve()
{
	int cnt = 0;
	bool flag = 0,cA=1,cC=1;
	cin >> n >> m >> L >> V ;
	for(int i=1;i<=n;i++)
	{
		cin >> c[i].d >> c[i].v >> c[i].a;
		if(c[i].a < 0 ) cA = 0;
		else cC = 0;
	}
	for(int i=1;i<=m;i++) 
	{
		cin >> p[i];
		dk[i] = 0;
	}
	for(int i=1;i<=n;i++)
	{
		bool flag = 0;
		int l = 1,r = m,ans = m +1,mik,mxk;
		int lx = 1, rx = m,ax = 0;
		while(lx <= rx)
		{
			int mid = lx + rx >> 1 ;
			if(p[mid] < c[i].d) ax = mid,lx = mid + 1;
			else rx = mid - 1;
		}
		l = ax+1;
		//cout << l << "~" << r << ":";
		if(c[i].a < 0)
		{
			while(l <= r)
			{
				int mid = l + r >> 1,s = p[mid] - c[i].d;
				int num = c[i].v * c[i].v + 2 * c[i].a * s;
				if(num < 0 ||num >= 0 && sqrt(1.00*num) <= 1.00*V) r = mid - 1;
				else {flag = 1;mxk = mid,l = mid + 1;}
			}
			mik = ax + 1;
		}
		else
		{
			while(l <= r)
			{
				int mid = l + r >> 1,s = p[mid] - c[i].d ;
				int num = c[i].v * c[i].v + 2 * c[i].a * s ;
				if(sqrt(1.00*num) <= 1.00*V) l = mid + 1;
				else {
					flag = 1;mik = mid;r = mid - 1;
				}
			}
			mxk = m;
		}
		if(flag)
		{
			//cout << i << " ";
			cnt ++;
			//cout << mik << " " << mxk << "\n";
			mink[cnt] = mik,maxk[cnt] = mxk;
			dk[mink[cnt]] ++,dk[maxk[cnt]+1] --;
			vis[cnt] = 0;
		}
		//cout << "\n";
	}
	cout << cnt << " ";
	if(cA)
	{
		if(cnt != 0)cout << m-1 << "\n";
		else cout << m << "\n";	
	}
	else
	{
		int res = 0;
		// for(int i=1;i<=m;i++)
		// {
		// 	cout << dk[i] << " ";
		// }
		for(int i=1;i<=m;i++)
		{
			int wzy = 0,maxdel = 0,maxns = -1;
			for(int j=1;j<=m;j++)
			{
				wzy += dk[j];
				if(wzy > maxns)
				{
					wzy = maxns;
					maxdel = j;
				}
			}
			res ++;
			for(int j=1;j<=cnt;j++)
			{
				if(mink[j] <= maxdel && maxdel <= maxk[j] && !vis[j]) {
					dk[mink[j]] --,dk[maxk[j]+1] ++;
					vis[j] = 1;
				}
			}
			bool flag = 1;
			for(int j=1;j<=m;j++)
			{
				if(dk[j] != 0) flag = 0;
			}
			//for(int j=1;j<=m;j++) cout << dk[j] << " ";
			//cout << "\n";
			if(flag) break;
		}
		cout << m - res << "\n";
	}
	
	return;
}
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T;
	cin >> T ;
	while(T--) solve();
}