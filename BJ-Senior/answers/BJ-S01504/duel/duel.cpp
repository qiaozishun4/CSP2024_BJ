#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N],b[N];
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[a[i]]++;
		ans=max(ans,b[a[i]]);
	}
	cout<<ans<<endl;
	return 0;
}