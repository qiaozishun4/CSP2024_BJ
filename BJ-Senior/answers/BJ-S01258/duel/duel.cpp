#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n;
int r[N];
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>r[i];
	}
	sort(r,r+n+1);
	for(int i=1;i<=n;i++)
	{
		if(r[i]==r[n+1-i])
		{
			cout<<n-(i-1)<<endl;
			return 0;
		}
	}
	cout<<n-(n/2)<<endl;
	return 0;
}