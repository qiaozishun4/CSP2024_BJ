#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Node{
	ll d,v,n;
};
vector<Node> va;
const int M=1e5+5;
ll v,p[M];
bool Check(ll mid,ll v2,ll na,ll d)
{
	if(v2*v2+2*na*(p[mid]-d)>v*v)
		return 0;
	else
		return 1;
}
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	ios::sync_with_stdio(0);
	ll t,n,m,l,d,v2,na,mid,ans1=0,ans2=0;
	cin>>t;
	while(t--)
	{
		cin>>n>>m>>l>>v;
		ans1=0;
		ans2=0;
		for(int i=1;i<=n;i++)
		{
			cin>>d>>v2>>na;
			va.push_back({d,v2,na});
		}
		for(int i=1;i<=m;i++)
			cin>>p[i];
		for(int i=0;i<va.size();i++)
		{
			if(va[i].d>p[m]||Check(m,va[i].v,va[i].n,va[i].d))
				ans1++;
		}
		va.clear();
		if(n-ans1==0)
			m++;
		cout<<n-ans1<<' '<<m-1<<'\n';
	}
	return 0;
}