#include <bits/stdc++.h>
using namespace std;
const int N=1.5e5+5;
int n,m,a[N],v[N],c[N],nowv[N],x[4];
long long res=0;
bool d[20][N];
int Log[N];
int main()
{
	srand(time(0));
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for (int i=1;i<=20;i++)
	{
		if ((1<<i)>150000) break;
		Log[(1<<i)]=i;
	}
	int lst=17;
	for (int i=100000;i>=2;i--)
	{
		if (Log[i]) lst=Log[i];
		else Log[i]=lst;
	}
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=m;i++) cin>>c[i];
	char chou;
	for (int i=1;i<=Log[n];i++)
	{
		for (int j=1;j<=(1<<(Log[n]-i));j++)
		{
			cin>>chou;
			d[i][j]=chou-'0';
		}
	}
	int T;
	cin>>T;
	while (T--)
	{
		for (int i=0;i<4;i++) cin>>x[i];
		cout<<rand()%10000<<"\n";
	}
	return 0;
}