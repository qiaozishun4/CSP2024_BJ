#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int N=1e5+10;
int a[N];
queue<int>q;
signed main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
	int n,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		if(q.empty()||q.front()>=a[i])
		{
			q.push(a[i]);
			ans++;
		}
		else
		{
			q.pop();
			q.push(a[i]);
		}
	}
	cout<<ans;
	return 0;
}