#include<iostream>
using namespace std;
int cnt[100005],n;
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	int tmp;
	for(int i=1;i<=n;i++)
	{
		cin>>tmp;
		cnt[tmp]++;
	}
	int car=0,ans=0;
	for(int i=1;i<=100000;i++)
	{
		ans+=min(car+cnt[i-1],cnt[i]);
		if(car+cnt[i-1]>cnt[i]) car=car+cnt[i-1]-cnt[i];
		else car=0;
	}
	cout<<n-ans<<endl;
	return 0;
}
