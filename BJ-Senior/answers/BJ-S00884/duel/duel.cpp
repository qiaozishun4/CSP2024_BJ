#include<iostream>
#include<algorithm>
using namespace std;
int n,a[100010],ans=0;
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1,num=0;i<=n;i++)
	{
		num++;
		if(a[i]==a[i+1])
		{
			continue;
		}
		ans=max(0,ans-num);
		ans+=num,num=0;
	}
	cout<<ans<<endl;
	return 0;
}