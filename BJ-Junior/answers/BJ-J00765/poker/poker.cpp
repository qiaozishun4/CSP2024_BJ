#include<bits/stdc++.h>
using namespace std;
int d[30],c[30],h[30],s[30];
char q[4];
int n;
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",q);
		int t=0;
		if(q[1]=='A')t=1;
		if(q[1]=='T')t=10;
		if(q[1]=='J')t=11;
		if(q[1]=='Q')t=12;
		if(q[1]=='K')t=13;
		if(t==0)t=q[1]-'0';
		if(q[0]=='D'&&d[t]==0)d[t]++,ans++;
		if(q[0]=='C'&&c[t]==0)c[t]++,ans++;
		if(q[0]=='H'&&h[t]==0)h[t]++,ans++;
		if(q[0]=='S'&&s[t]==0)s[t]++,ans++;
	}
	printf("%d",52-ans);
	return 0;
	
}
