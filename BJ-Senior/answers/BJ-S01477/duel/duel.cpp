#include<bits/stdc++.h>
using namespace std;
int n,a[100010];
queue<int>q;
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++)
	{
		q.push(a[i]);
		if (a[i]>q.front()) q.pop();
	}
	cout<<(int)q.size();
	return 0;
}
