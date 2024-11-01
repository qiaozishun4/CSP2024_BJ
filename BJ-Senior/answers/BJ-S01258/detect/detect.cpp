#include<bits/stdc++.h>
using namespace std;
int n,m,L,V;
const int N=1e5+5,M=1e5+5;
int d[N],v[N],a[N];
int p[M];
int ans=0;
int used[M];

int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	int tt=1;
	while(tt<=T)
	{
		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;i++)
		{
			cin>>d[i]>>v[i]>>a[i];
		}
		for(int i=1;i<=m;i++)
		{
			cin>>p[i];
		}
		bool A=1,B=1;
		for(int i=1;i<=n;i++)
		{
			if(a[i]!=0)
			{
				A=0;
			}
			if(a[i]<=0)
			{
				B=0;
			}
		}
		if(A)
		{
			for(int i=1;i<=n;i++)
			{
				if(v[i]>V)
				{
					ans++;
				}
			}
			cout<<ans<<" ";
			if(ans==0)
			{
				m+=1;
			}
			cout<<m-1<<endl;
		}
		else if(B)
		{
			for(int i=1;i<=n;i++)
			{
			double s=double(p[m])-double(d[i]);
double vshun=sqrt(double(v[i])*double(v[i])+2*double(a[i])*s);
if(vshun>V)
{
	ans++;
}			
			}	
			if(ans==0)
			{
				m+=1;
			}
			cout<<ans<<" ";
			cout<<m-1<<endl;
		}
		else
		{
			cout<<n<<" ";
			cout<<0<<endl;
		}
		ans=0;
		memset(used,0,sizeof(used));
		tt++;
	}
	return 0;
}