#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,M=1e5+5,K=20;
int a[N],c[M];
struct player
{
	string s;	
};	
player r[K];
int reala[N];
int ra[N];
int main()
{
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=m;i++)
	{
		cin>>c[i];
	}
	int k=1;
	while(pow(2,k)<n)
	{
		k++;
	}
	k+=1;
	for(int i=1;i<=k;i++)
	{
		cin>>r[i].s;
	}	
	int T;
	cin>>T;
	int tt=1;
	int ans=0;
	while(tt<=T)
	{
		int x[4];
		cin>>x[0]>>x[1]>>x[2]>>x[3];
		for(int i=1;i<=n;i++)
		{
			reala[i]=a[i]*x[i%4];
			ans=reala[i]*4;
		}			
		cout<<ans<<endl;
		tt++;
	}
	return 0;
}