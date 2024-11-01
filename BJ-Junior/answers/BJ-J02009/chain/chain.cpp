#include<bits/stdc++.h>
using namespace std;
int T,n,q,k,ed[200005],s[200005],sum,x,r,c;
bool pf;
int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&k,&q);
		for(int i=1;i<=n;i++) 
		{
			scanf("%d",&x);
			for(int j=1;j<=x;j++) scanf("%d",&s[sum+j]);
			sum+=x,ed[i]=sum;
		}
		while(q--)
		{
			scanf("%d%d",&r,&c);
			if(r==1)
			{
				pf=0;
				for(int i=1;i<=sum;i++)
					if(s[i]==c)
					{
						printf("1\n"),pf=1;
						break;
					}
				if(!pf) printf("0\n");
			}
			else printf("0\n");
		}
	}
	return 0;
}