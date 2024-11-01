#include <bits/stdc++.h>
using namespace std;
const int N=100010;
int a[N];
bool vis[N];
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	bool flag=true;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>2)
		{
			flag=false;
		}
	}
	if(flag)
	{
		int cnt1=0,cnt2=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==1)
			{
				cnt1++;
			}
			else
			{
				cnt2++;
			}
		}
		if(cnt2>cnt1)
		{
			cout<<cnt2<<endl;
		}
		else
		{
			cout<<cnt2+(cnt1-cnt2)<<endl;
		}
	}
	else
	{
		sort(a+1,a+n+1);
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<i;j++)
			{
				if(a[i]==a[j])
				{
					break;
				}
				else if(!vis[j])
				{
					vis[j]=true;
					cnt++;
					break;
				}
				else
				{
					continue;
				}
			}
		}
		cout<<n-cnt<<endl;
	}
	return 0;
}