#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,T,L,num=0;
int v0[N],d[N],V,a[N],ans=0;
int p[N],sum[N],cnt=0,D[N];
pair<int,int>	line[N];
bool rec[N];
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	while(T--)
	{
		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;i++)
		{
			cin>>d[i]>>v0[i]>>a[i];			
		}
		for(int i=1;i<=m;i++)
		{
			cin>>p[i];
			sum[p[i]]++;
		}
		for(int i=0;i<=L;i++)
		{
			sum[i]+=sum[i-1];
			D[i]=sum[i];
		}
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0)
			{
				if(v0[i]>V and sum[d[i]-1]<sum[L])
				{
					num++;
					line[num].first=d[i],line[num].second=L;
				}
			}
			else if(a[i]<0)
			{
				int t=floor((V-v0[i])/a[i]);
				if(v0[i]>V and sum[d[i]-1]<sum[d[i]+t])
				{
					num++;
					line[num].first=d[i],line[num].second=t+d[i];
				}
			}
			else//if(a[i]>0)
			{
				
				int t=ceil((V-v0[i])/a[i]);
				if(v0[i]>V and sum[d[i]-1]<sum[L])
				{
					num++;
					line[num].first=d[i],line[num].second=L;	
				}
				else if(v0[i]<=V and sum[d[i]+t-1]<sum[L])
				{
					
					num++;
					line[num].first=d[i]+t,line[num].second=L;
				}
			}
		}
		sort(p+1,p+1+num);
		cout<<num<<" ";
		for(int i=1;i<=m;i++)
		{
			for(int j=p[i];j<=L;j++)
			{
				D[j]--;
			}
			int count=0;
			for(int j=1;j<=num;j++)
			{
				if(D[line[j].first-1]<D[line[j].second])
				{
					count++;
				}
			}
			if(count==num)
			{
				ans++;
			}
			else
			{
				for(int j=p[i];j<=L;j++)
				{
					D[j]++;
				}
			}
		}
		
		cout<<ans<<endl;
	}

	return 0;
}
