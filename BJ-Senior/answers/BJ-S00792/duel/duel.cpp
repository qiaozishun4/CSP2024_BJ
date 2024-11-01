#include<bits/stdc++.h>
using namespace std;
const int Maxn=1e5+10;
int n,ans;
int a[Maxn];
queue<int>q;
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		if(!q.empty() && q.front()<a[i]) q.pop();
		q.push(a[i]);
	}
	cout<<q.size()<<endl;
	return 0;
}