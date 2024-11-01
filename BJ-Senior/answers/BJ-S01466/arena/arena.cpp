#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1005;
ll a[N],st[N],rem[N],ch[5];
char d[20][N];
int c[N],book[N];
int n,m,k,lun;
ll res=0;
deque<int> q;
void dfs(int tar,int r,int g)
{
	if(g==(1<<(lun-r))+1)
		g=1,r++;
	if(r==lun+1)
	{
		int x=q.front();
		if(book[x]==0) book[x]=1,res+=x;
		return;
	}
	int x=q.front();
	q.pop_front();
	int y=q.front();
	q.pop_front();
	if(d[r][g]=='1') swap(x,y);
	if(x<=c[tar])
	{
		if(a[x]>=r) q.push_back(x);
		else q.push_back(y);
		dfs(tar,r,g+1);
		q.pop_back();
	}
	else
	{
		q.push_back(x);
		dfs(tar,r,g+1);
		q.pop_back();
		q.push_back(y);
		dfs(tar,r,g+1);
		q.pop_back();
	}
	if(d[r][g]=='1') swap(x,y);
	q.push_front(y);
	q.push_front(x);
}
int main()
{
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>st[i];
	for(int i=1;i<=m;i++)
		cin>>c[i];
	while((1ll<<k)<n) k++;
	for(int i=1;i<=k;i++)
		for(int j=1;j<=(1<<(k-i));j++)
			cin>>d[i][j];
	int T;
	cin>>T;
	while(T--)
	{
		cin>>ch[0]>>ch[1]>>ch[2]>>ch[3];
		for(int i=1;i<=n;i++)
			a[i]=st[i]^ch[i%4];
		for(int i=1;i<=n;i++)
			rem[i]=0;
		ll ans=0;
		for(ll i=1;i<=m;i++)
		{
			lun=res=0;
			while((1ll<<lun)<c[i]) lun++;
			while(!q.empty()) q.pop_front();
			for(int j=1;j<=(1<<lun);j++)
				q.push_back(j);
			for(int j=1;j<=(1<<lun);j++)
				book[j]=0;
			if(rem[c[i]])
			{
				ans^=(i*rem[c[i]]);
				continue;
			}
			dfs(i,1,1);
			rem[c[i]]=res;
			ans^=(i*res);
		}
		cout<<ans<<'\n';
	}
	return 0;
}
