#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
const int N=1e5+5;
int n,r[N],b[N],m=0,cnt=0;
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{	
		cin>>r[i];
		b[r[i]]++;
		m=max(m,r[i]);
	}
	for(int i=1;i<=m;i++)
	{
		if(b[i]==0)	continue;
		if(cnt==0)
		{
			cnt+=b[i];
			continue;
		}
		if(cnt<b[i])
		{
			cnt=b[i];
			continue;
		}
	}
	cout<<cnt;
	return 0;
}
