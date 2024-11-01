#include<bits/stdc++.h>
using namespace std;
int n;
int r[100005];
int bin[100005];
struct node
{
	int less;
	int unused;
	int r;
}level[100005];
int mn=100005,mx=0;
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&r[i]);
		bin[r[i]]++;
		mn=min(mn,r[i]);
		mx=max(mx,r[i]);
	}
	int cnt=0;
    for(int i=mn;i<=mx;i++)
    {
		if(!bin[i])continue;
		cnt++;
		level[cnt].unused=bin[i];
		level[cnt].r=i;
		level[cnt].less=level[cnt-1].less+bin[level[cnt-1].r];
	}
	int tmp=0;
	for(int i=1;i<=cnt;i++)
	{
		tmp+=min(level[i].less-tmp,level[i].unused);
		level[i].unused=0;
    }
    int ans=n-tmp;
    printf("%d",ans);
    return 0;
}
