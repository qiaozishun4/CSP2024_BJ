#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N=1e6+10;
struct node
{
	int l,r;
}car[N];
int top=0;
int id[N],book[200010];
void init()
{
	top=0;
	memset(book,0,sizeof(book));
}
int find(int x,int m)
{
	int l=1,r=m,re=1e9;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(id[mid]>=x)
		{
			re=id[mid];
			r=mid-1;
		}
		else l=mid+1;
	}
	return re;
}
int find1(int x,int m)
{
	int l=1,r=m,re=0;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(id[mid]<=x)
		{
			re=id[mid];
			l=mid+1;
		}
		else r=mid-1;
	}
	return re;
}
bool cmp1(node x,node y)
{
	return x.l<y.l;
}
void run()
{
	int n,m,L,V,flag=0,ans=0;
	cin>>n>>m>>L>>V;
	for(int i=1;i<=n;i++)
	{
		int d,v,a;
		cin>>d>>v>>a;
		if(a>0)
		{
			if(v>V)
			{
				car[++top]={d,L};
				continue;
			}
			int l=max(d,d+(int)(((double)(V*V-v*v))/(2*a))+1),r=L;
			if(l<=r)
			{
				car[++top]={l,r};
			}
		}
		else if(a==0)
		{
			if(v>V)
			{
				car[++top]={d,L};
			}
		}
		else if(a<0)
		{
			if(v<=V)continue;
			flag=1;
			int l=d,r=min(L,d+(int)ceil(((double)(V*V-v*v))/(double)(2*a))-1);
			if(l<=r)
			{
				// cout<<endl<<l<<' '<<r;
				car[++top]={l,r};
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cin>>id[i];
	}
	sort(id+1,id+m+1);
	for(int i=1;i<=top;i++)
	{
		// cout<<endl<<find(car[i].l,m);
		if(find(car[i].l,m)<=car[i].r)
		{
			car[++ans]={car[i].l,car[i].r};
		}
	}
	cout<<ans<<' ';
	top=ans;
	if(!ans)cout<<m<<endl;
	else if(!flag)
	{
		cout<<m-1<<endl;
	}
	else
	{
		sort(car+1,car+top+1,cmp1);
		int minm=1e9;
		for(int i=top;i;i--)
		{
			if(car[i].r>=minm)
			{
				book[i]=1;
			}
			else minm=car[i].r;
		}
		int maxn=-1,ans=0;
		for(int i=1;i<=top;i++)
		{
			if(book[i])continue;
			// cout<<car[i].l<<' '<<car[i].r<<endl;
			if(car[i].l<=maxn&&maxn<=car[i].r)continue;
			maxn=find1(car[i].r,m);
			ans++;
		}
		cout<<m-ans<<endl;
	}
	init();
}
signed main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
	int t;
	cin>>t;
	while(t--)run();
	return 0;
}