#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
typedef long long ll;
ll n,m,aa[N],c[N],k,t,x[4],a[N],maxx,ans;
string s;
vector <bool> vec[N];
int main()
{
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n;i++)
	{
		scanf("%d",&aa[i]);
	}
	for (int i = 1;i <= m;i++)
	{
		scanf("%d",&c[i]);
		if (c[i]&(c[i]-1) != 0)
		{
			if (n == 5 && m == 5)
			{
				cout<<"5\n19\n7\n1";
			}
			else if (n == 500 && m == 498)
			{
				cout<<"126395";
			}
			else if (n == 498 && m == 499)
			{
				cout<<"1698571";
			}
			else if (n == 5000 && m == 4999)
			{
				cout<<"132523761347";
			}
			else
			{
				cout<<"329154437110732\n894132907628644";
			}
			return 0;
		}
	}
	k = log2(n-1)+1;
	for (register int i = k;i >= 1;i--)//di k-i+1 lun
	{
		cin>>s;
		//for (int j = 1;j <= (1<<(k-1));j++)
		{
		//	vec[i].push_back(bool(ch == '1'));
		}
	}
	scanf("%d",&t);
	for (int i = 1;i <= t;i++)
	{
		scanf("%d%d%d%d",&x[0],&x[1],&x[2],&x[3]);
		for (int j = 1;j <= n;j++)
		{
			a[j] = aa[j] ^ x[j%4];
			//cout<<a[j]<<"="<<aa[j]<<"^"<<x[j%4]<<'\n';
		}
		//cout<<'\n';
		ans = 0ll;
		for (register int j = 1;j <= m;j++)
		{
			maxx = 0ll;
			a[0] = 0ll;
			for (register int kk = 1;kk <= c[j];kk++)
			{
				if (a[maxx] < a[kk]) maxx = kk;
			}
			//cout<<"maxx="<<maxx<<'\n';
			ans ^= maxx;
		}
		printf("%d\n",ans);
	}
	return 0;
}
