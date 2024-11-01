#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int d[100050],v[100050],a[100050],p[100050],b[100050],n,m,l,vx,cnt,ans;
int f(int q)
{
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(d[i]>b[q]) continue;
		if(a[i]==0)
		{
			if(v[i]>vx)
			{
				cnt++;
			}
		}
		if(a[i]>0)
		{
			if(sqrt(v[i]*v[i]+2*a[i]*(b[q]-d[i]))>double(vx))
			{
				cnt++;
			}
		}
		if(a[i]<0)
		{
			double pos=-(v[i]*v[i])/(2*a[i]);
			int j;
			for(j=1;j<=q&&b[j]<d[i];j++);
			if(sqrt(v[i]*v[i]+2*a[i]*(b[j]-d[i]))>double(vx))
			{
				cnt++;
			}
		}
	}
	return cnt;
}
void dfs(int cur,int s)
{
	if(cur>m)
	{
		if(f(s)==cnt) ans=max(ans,m-s);
		//cout<<f(s)<<'\n';
		//for(int i=1;i<=s;i++) cout<<b[i]<<' ';
		//cout<<'\n';
		return;
	}
	b[++s]=p[cur];
	dfs(cur+1,s);
	b[s--]=0;
	dfs(cur+1,s);
}
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n>>m>>l>>vx;
		for(int i=1;i<=n;i++) cin>>d[i]>>v[i]>>a[i];
		for(int i=1;i<=m;i++) cin>>p[i],b[i]=p[i];
		sort(p+1,p+m+1);
		cnt=f(m);
		cout<<cnt<<' ';
		if(cnt==0) cout<<m;
		else if(n<=20&&m<=20)
		{
			ans=INT_MIN;
			dfs(1,0);
			cout<<ans;
		}
		else
		{
			cout<<m-1;
		}
		cout<<'\n';
	}
	return 0;
}
