#include<bits/stdc++.h>
using namespace std;
const int Maxn=1e5+10;
const int Maxl=1e6+10;
struct car
{
	bool f;
	int l,r;
}f[Maxn];
int b[Maxl];
bool used[Maxn];
int n,m,L;
int ans1,ans2;
int cnt0,cnt1,cnt2;// <0; =0; >0
int find1(int d,int v,int a,double V)
{
	int l,r,mid,re=L;
	l=d,r=L;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(sqrt(v*v+2*a*(mid-d))>V) re=mid,l=mid+1;
		else r=mid-1; 
	}
	return re;
}
int find2(int d,int v,int a,double V)
{
	int l,r,mid,re=L+1;
	l=d,r=L;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(sqrt(v*v+2*a*(mid-d))>V) re=mid,r=mid-1;
		else l=mid+1; 
	}
	return re;
}
bool check(int l,int r)
{
	for(int i=1;i<=m;i++)
	{
		if(l<=b[i] && r>=b[i] && !used[i]) return 1;
	}
	return 0;
}
void get_ans2(int now,int num)
{
	if(now==m+1)
	{
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(!f[i].f) continue;
			cnt+=check(f[i].l,f[i].r);
		}
		if(cnt==ans1) ans2=max(ans2,num);
		return ;
	}
	used[now]=1;
	get_ans2(now+1,num+1);
	used[now]=0;
	get_ans2(now+1,num);
}
void run()
{
	memset(b,0,sizeof(b));
	cnt0=cnt1=cnt2=0;
	ans1=ans2=0;
	int V;
	cin>>n>>m>>L>>V;
	for(int i=1;i<=n;i++)
	{
		int d,v,a;
		cin>>d>>v>>a;
		if(a<0)
		{
			if(v>V) f[i].f=1,f[i].l=d,f[i].r=find1(d,v,a,V);
			else f[i].f=0;
			cnt0++;
		}
		else if(a==0)
		{
			if(v>V) f[i].f=1,f[i].l=d,f[i].r=L;
			else f[i].f=0;
			cnt1++;
		}
		else
		{
			if(v>V) f[i].f=1,f[i].l=d,f[i].r=L;
			else
			{
				int temp=find2(d,v,a,V);
				if(temp<=L) f[i].f=1,f[i].l=temp,f[i].r=L;
				else f[i].f=0;
			}
			cnt2++;
		}
		// cout<<i<<" "<<f[i].f<<" "<<f[i].l<<"=>"<<f[i].r<<endl;
	}
	if(cnt1==n || cnt2==n)
	{
		for(int i=1;i<=m;i++)
		{
			int temp;
			cin>>temp;
			b[temp]=1;
		}
		for(int i=L-1;i>=0;i--) b[i]|=b[i+1];
		for(int i=1;i<=n;i++)
		{
			if(!f[i].f) continue;
			ans1+=bool(b[f[i].l]);
		}
		ans2=m-bool(ans1);
	}
	else
	{
		for(int i=1;i<=m;i++) cin>>b[i];
		for(int i=1;i<=n;i++)
		{
			if(!f[i].f) continue;
			ans1+=check(f[i].l,f[i].r);
		}
		get_ans2(1,0);
	}
	cout<<ans1<<" "<<ans2<<endl;
	return ;
}
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while(T--) run();
	return 0;
}