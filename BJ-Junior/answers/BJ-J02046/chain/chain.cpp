#include <bits/stdc++.h>
#include <cstring>
#include <deque>
using namespace std;
typedef long long ll;

int t,n,k,q;

int cnt;
int l[100010];
struct Node
{
	string w;
	int peo;
}s[200010];
vector<int> v[200010];
bool vis[105][200005];
deque<int> dq;
void bfs(int i)
{
	dq.clear();
	dq.push_back(i);
	while (!dq.empty())
	{
		
int main()
{
	//freopen("chain.in","r",stdin);
	//freopen("chain.out","w",stdout);
	
	cin>>t;
	while (t--)
	{
		cin>>n>>k>>q;
		
		memset(vis,0,sizeof(vis));
		memset(v,0,sizeof(v);
		cnt=0;
		
		for (int i=1;i<=n;i++)
		{
			cin>>l[i];
			for (int j=1;j<=l[i];j++)
			{
				cin>>s[++cnt].w;
				s[cnt].peo=1;
				if (j>1)
				{
					v[cnt-1].push_back(cnt);
				}
			}
		}
		for (int i=1;i<=cnt;i++)
		{
			for (int j=1;j<=cnt;j++)
			{
				if (s[i].peo!=s[j].peo && s[i].w[s[i].w.size()-1]==s[j].w[0])
				{
					v[i].push_back[j];
				}
			}
		}
		for (int i=1;i<=cnt;i++)
		{
			if (s[i].w[0]=='1')
			{
				bfs(i);
			}
		}
		
		
	}	
		
					
	return 0;
}
