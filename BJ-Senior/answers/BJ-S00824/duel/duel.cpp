#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	cin.tie(0),cout.tie(0);
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n,cnt=0;
	bool p=1;
	cin>>n;
	int a[n+5];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1&&a[i]!=2) p=0;
		if(a[i]==2) cnt++;
	}
	if(p!=0)cout<<cnt;
	if(p==0)
	{
		int num[100009]={0};
		for(int i=1;i<=n;i++)num[a[i]]++;
		sort(num+1,num+100001);
		cout<<num[100000];
	}	
	return 0;
}
