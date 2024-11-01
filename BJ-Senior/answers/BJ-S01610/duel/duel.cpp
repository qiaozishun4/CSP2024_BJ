#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int b[1000000];
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int c=0;
	for(int i=1;i<=n;i++)
	{
		
		if(a[i]!=a[i-1])
		{
			b[++c]++;
		}
		else
		{
			b[c]++;
		}
	}
	int m=b[1];
	for(int i=2;i<=c;i++)
	{
		m=max(m,b[i]);
	}
	cout<<m<<endl;
	return 0;
}
