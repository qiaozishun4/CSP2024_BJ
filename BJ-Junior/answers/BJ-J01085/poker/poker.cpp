#include<bits/stdc++.h>
using namespace std;
char s[1001][1001];
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n,m,cnt=0;
	cin>>n;
	m=n;
	char c,x;
	for(int i=1;i<=n;i++)
	{
		cin>>c>>x;
		for(int j=1;j<=n;j++)
		{
			if(c==s[j][1]&&x==s[j][2])
			{
				m--;
				cnt=1;
				break;
			}
		}
		if(cnt==0)
		{
			s[i][1]=c;
			s[i][2]=x;
		}
		cnt=0;
	}
	cout<<52-m;
	return 0;
}
