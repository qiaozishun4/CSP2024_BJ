#include<bits/stdc++.h>
#define int long long
#define faster; ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int book[100005],book1[100005],t,n,m,L,V,flag=0,d[100005],v[100005],a[100005],p[100005],ans1,ans2,minn[100005];
using namespace std;
signed main()
{
	faster;
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	while(t--)
	{
		ans1=ans2=flag=0;
		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;i++)cin>>d[i]>>v[i]>>a[i];
		for(int i=1;i<=m;i++)cin>>p[i];
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0)flag=1;
			else 
			{
				flag=0;
				break;
			}
		}
		if(flag==1)//a=0
		{
			for(int i=1;i<=n;i++)if(v[i]>V)ans1++;
			if(ans1!=0)ans2=m-1;
			else ans2=m;
			cout<<ans1<<" "<<ans2<<'\n';
			continue;
		}
		if(flag==0)
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i]<0)flag=2;
				else 
				{
					flag=0;
					break;
				}
			}
			if(flag==2)//a<0
			{
				int lt=0,cnt=0;
				for(int i=1;i<=n;i++)
				{
					for(int j=1;j<=m;j++)
					{
						if(p[j]>=d[i])
						{
							minn[i]=p[j];
							break;
						}
					}
				}
				for(int i=1;i<=n;i++)
				{
					if(v[i]-abs(a[i])*(minn[i]-d[i])>V)
					{
						ans1++;
						book[++cnt]=minn[i];
					}
				}
				for(int i=1;i<=cnt;i++)
				{
					if(book1[book[i]]==0)lt++;
					else continue;
					book1[book[i]]=1;
				}
				ans2=m-lt;
				cout<<ans1<<" "<<ans2<<'\n';
				continue;
			}
			if(flag==0)
			{
				for(int i=1;i<=n;i++)
				{
					if(a[i]>0)flag=3;
					else 
					{
						flag=0;
						break;
					}
				}
				if(flag==3)//a>0
				{
					for(int i=1;i<=n;i++)if(v[i]+a[i]*(p[m]-d[i])>V)ans1++;
					if(ans1!=0)ans2=m-1;
					else ans2=m;
					cout<<ans1<<" "<<ans2<<'\n';
					continue;
				}
				if(flag==0)//无特殊情况
				{
					cout<<n<<" "<<m<<'\n';
					continue;
				}
			}
		}
	}
	return 0;
}