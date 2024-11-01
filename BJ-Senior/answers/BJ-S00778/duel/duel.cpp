#include<bits/stdc++.h>
using namespace std;
int n,a[100010],ans,l,r;
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin >> n;
	ans=n;
	for(int i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	l=1,r=0;
	for(int i=2;i<=n;i++)
	{
		if(a[i]!=a[i-1])r=i-1;
		if(l<=r)
		{
			ans--;
			l++;
		}
	}
	cout<< ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}