#include<bits/stdc++.h>
using namespace std;
const int N=2e3+5;
int a[N],b[N],l[N],d[N];
int main()
{	
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		memset(d,0,sizeof(d));
		int n,k,q,m=0;
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++)
		{
			cin>>l[i];
			b[i]=m+1;
			for(int j=1;j<=l[i];j++)
			{
				cin>>a[++m];
			}
			for(int j=b[i];j<=m;j++)
			{	
				if(a[j]!=1)continue;
				for(int kk=max(b[i],j-k+1);kk<=min(m,j+k-1);kk++)
				{
					if(kk-j<1)continue;
					d[kk]=1;
				}
				//cout<<j<<" "<<max(b[i],j-k+1)<<" "<<min(m,j+k-1)<<endl;
			}
			
		}
		int r,c;
		bool ans;
		for(int i=1;i<=q;i++)
		{
			ans=0;
			cin>>r>>c;
			if(r!=1)
			{
				cout<<"1"<<endl;
				continue;
			}
			for(int j=1;j<=m;j++)
			{
				if(a[j]==c)ans+=d[j];
				//cout<<d[j]<<" ";
			}
			cout<<ans<<endl;
		}
		
	}
	return 0;
}