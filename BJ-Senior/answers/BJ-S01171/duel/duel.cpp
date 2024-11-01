#include <bits/stdc++.h>
using namespace std;
int a[100010];
queue<int> q;
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,i;
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++)
	{
		if(!q.empty())
		{
			int x=q.front();
			if(a[i]>x)
				q.pop();
		}
		q.push(a[i]);
	}
	cout<<q.size();
	return 0;
}
