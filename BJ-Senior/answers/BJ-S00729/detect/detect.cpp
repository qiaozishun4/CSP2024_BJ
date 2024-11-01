#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;

int T;
int n,m,L,V;
int d,v,a;
int p[maxn];
int c[maxn];

int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d%d%d",&n,&m,&L,&V);
		for (int i=1;i<=n;i++){
			scanf("%d%d%d",&d,&v,&a);
			if (v<=V) c[i]=-1;
			else if (v>V) c[i]=d;
		}
		for (int i=1;i<=m;i++) scanf("%d",&p[i]);
		
		sort(c+1,c+n+1);
		int ans1=0;
		for (int i=1;i<=n;i++)
		{
			if (c[i]==-1) continue;
			if (c[i]<=p[m]) ans1++;
			else break;
		}
		int ans2=m-1;
		printf("%d %d",ans1,ans2);
		if (T) printf("\n");
	}
	return 0;
}
