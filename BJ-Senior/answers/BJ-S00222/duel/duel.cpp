#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

const int MAXN=100010;
int a[MAXN],s[MAXN];

int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int rk=0,ps=0;
	for(int i=1;i<=n;i++)
	{
		if(ps==a[i]) s[rk]++;
		else
		{
			s[++rk]++;
			ps=a[i];
		}
	}
	int ls=s[1];
	int el=0;
	for(int i=2;i<=rk;i++)
	{
		if(s[i]>=ls)
		{
			el+=ls;
			ls=s[i];
		}
		else
		{
			el+=s[i];
		}
	}
	cout<<n-el;
	return 0;
}
