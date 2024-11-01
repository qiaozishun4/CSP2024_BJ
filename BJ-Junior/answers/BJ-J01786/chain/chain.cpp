#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
int t,n,k,q,l,s[N],r[N],maxr,c[N];
struct node
{
	int id,v;
};
map <int,bool> mp[N];
vector <node> G[N];
struct node2
{
	int id,u,ds;
};
void bfs()
{
	queue <node2> q;
	q.push({-1,1,0});
	while (!q.empty())
	{
		int id = q.front().id;
		int u = q.front().u;
		int ds = q.front().ds;
		q.pop();
		if (ds == maxr) continue;
		for (auto V : G[u])
		{
			int vid = V.id;
			int v = V.v;
			//cout<<"q.front():"<<id<<" "<<u<<" "<<ds<<'\n';
			//cout<<"V:"<<vid<<" "<<v<<'\n';
			if (id != vid)
			{
				//cout<<"mp["<<v<<"]["<<ds+1<<"]=1\n";
				mp[v][ds+1] = 1;
				q.push({vid,v,ds+1});
			}
		}
	}
}
int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	scanf("%d",&t);
	while (t--)
	{
		for (int i = 1;i <= N-5;i++) G[i].clear(),mp[i].clear();
		scanf("%d%d%d",&n,&k,&q);
		for (int i = 1;i <= n;i++)
		{
			scanf("%d",&l);
			for (int j = 1;j <= l;j++)
			{
				scanf("%d",&s[j]);
			}
			for (int j = 1;j <= l;j++)
			{
				for (int m = j+1;m <= min(l,j+k-1);m++)
				{
					G[s[j]].push_back({i,s[m]});
				}
			}
		}
		for (int i = 1;i <= q;i++)
		{
			scanf("%d%d",&r[i],&c[i]);
			maxr = max(maxr,r[i]);
		}
		bfs();
		for (int i = 1;i <= q;i++)
		{
			if (mp[c[i]][r[i]])
			{
				printf("1\n");
			}
			else
			{
				printf("0\n");
			}
		}
	}
	return 0;
}
