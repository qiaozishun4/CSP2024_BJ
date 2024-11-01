#include<bits/stdc++.h>
using namespace std;
int n;
int a[100010];
int b[100010];
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	int ans=n;
	for(int i=n;i>1;i--)
		for(int j=i-1;j>=1;j--)
			if((a[i]>a[j])&&(b[j]==0))
			{
				ans--;
				b[j]=1;
				break;
			}
	cout<<ans;
	return 0;
}
