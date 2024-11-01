#include <bits/stdc++.h>
using namespace std;
int T,n,m,L,V,p[100010],d[100010],v[100010],a[100010],ans,ans2;
bool book[100010],flag;
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    scanf("%d",&T);
    while(T--)
    {
		scanf("%d%d%d%d",&n,&m,&L,&V);
		for(int i = 1;i <= n;++i)
		{
			scanf("%d%d%d",&d[i],&v[i],&a[i]);
			if(v[i]>V) book[i]=1;
		}
		for(int i = 1;i <= m;++i)
		{
			scanf("%d",&p[i]);
		}
		sort(p+1,p+m+1);
		ans=0,ans2=0;
		for(int j = 1;j <= m;++j)
		{
			flag=1;
			for(int i = 1;i <= n;++i)
			{
				if(d[i]<j)
				{
					if(book[i])
					{
						flag=0;
						++ans;
					}
				}
			}
			if(flag) ++ans2;
		}
		printf("%d\n%d",ans,ans2);
	}
    return 0;
}
