#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,a[100010],maxn;


int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		a[x]++;
		if(a[x]>maxn) maxn=a[x];
	}
	printf("%d",maxn);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
