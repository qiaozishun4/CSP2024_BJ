#include<bits/stdc++.h>
using namespace std;
string a[60];
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n,i;
	cin>>n;
	for(i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int gs=n;
	for(i=2;i<=n;i++)
	{
		if(a[i]==a[i-1]) gs--;
	}
	cout<<52-gs;
	return 0;
}
