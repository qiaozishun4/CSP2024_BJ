#include<bits/stdc++.h>
using namespace std;
int h[100005];
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		h[x]++;
	}
	int maxi=0;
	for(int i=1;i<=100000;i++)
	{
		maxi=max(maxi,h[i]);
	}
	cout<<maxi;
	return 0;
}
