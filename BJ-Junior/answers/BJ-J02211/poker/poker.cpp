#include<bits/stdc++.h>
using namespace std;
char se[54],shu[54];
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin>>n;
	int cnt=n;
	for(int i=1;i<=n;i++)
	{
		cin>>se[i]>>shu[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(se[j]==se[i]&&shu[j]==shu[i])
			{
				cnt--;
				break;
			}
		}
	}
	cout<<52-cnt;
	return 0;
}