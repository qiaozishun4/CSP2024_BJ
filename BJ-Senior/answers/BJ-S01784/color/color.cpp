#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long a[N],ans;
int T,n,c[N];
void dfs(int x,int C[N])
{
	if(x==n+1)
	{
		int b=0,r=0;//b:1 r:2
		long long s=0;
		for(int i=1;i<=n;i++)
		{
			if(C[i]==1)
			{
				if(a[i]==a[b]) s+=a[i];
				b=i;
			}
			else
			{
				if(a[i]==a[r]) s+=a[i];
				r=i;
			}
		}
		ans=max(ans,s);
		return;
	}
	else
	{
		C[x]=1;
		dfs(x+1,C);
		C[x]=2;
		dfs(x+1,C);
		C[x]=0;
	}
}
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		dfs(1,c);
		cout<<ans<<endl;
		ans=0;
	}
}
