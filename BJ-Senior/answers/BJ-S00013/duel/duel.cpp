#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node
{
	int v,s;
};
int a[100050];
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n;
	cin>>n;
	map<int,int> m;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		m[x]++;
		a[x]++;
	}
	vector<node> v,v2;
	for(auto i:m) v.push_back({i.first,i.second});
	int ans=n;
	bool flag=0;
	node z;
	for(;;)
	{
		for(int i=0;i<v.size()-1;i++)
		{
			int j=i+1;
			int x=v[i].s,y=v[j].s;
			if(y>x) ans-=v[i].s,a[v[i].v]-=v[i].s,v[j].s-=v[i].s,v[i].s=0;
			else ans-=v[j].s,a[v[i].v]-=v[j].s,v[i].s-=v[j].s,v[j].s=0;
			//cout<<'*'<<v[i].v<<' '<<v[i].s<<' '<<v[j].v<<' '<<v[j].s<<'\n';
			//for(int j=1;j<=3;j++) cout<<'*'<<a[j]<<'\n';
		}
		
		v2.clear();
		for(int i=0;i<v.size();i++) if(v[i].s) v2.push_back(v[i]);
		if(!v2.size()) break;
		if(v2.size()==1)
		{
			flag=1;
			z=v2[0];
			break;
		}
		for(int i=0;i<v2.size()-1;i++)
		{
			int j=i+1;
			int x=v2[i].s,y=v2[j].s;
			if(y>x) ans-=v2[i].s,a[v2[i].v]-=v2[i].s,v2[j].s-=v2[i].s,v2[i].s=0;
			else ans-=v2[j].s,a[v2[i].v]-=v2[j].s,v2[i].s-=v2[j].s,v2[j].s=0;
			//for(int j=1;j<=3;j++) cout<<'*'<<a[j]<<'\n';
		}
		v.clear();
		for(int i=0;i<v2.size();i++) if(v2[i].s) v.push_back(v[i]);
		if(!v.size()) break;
		if(v.size()==1)
		{
			flag=1;
			z=v[0];
			break;
		}
	}
	//cout<<'*'<<z.v<<'\n';
	if(flag)
	{
		for(int i=0;i<z.v;i++)
		{
			if(a[i])
			{
				//cout<<'*'<<a[i]<<'\n';
				if(a[i]>z.s)
				{
					ans-=z.s;
					a[i]-=z.s;
					z.s=0;
					break;
				}
				else
				{
					ans-=a[i];
					z.s-=a[i];
					a[i]=0;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
