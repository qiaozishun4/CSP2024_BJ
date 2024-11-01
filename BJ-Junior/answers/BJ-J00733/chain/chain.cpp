#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int> s[N];
vector<pair<pair<int,int>,int> >qry;
vector<pair<int,int> > v;
set<pair<int,int> > nxt;
map<pair<int,int>,bool> mym;
int tot=0;
bool cmp(pair<pair<int,int>,int> a,pair<pair<int,int>,int> b)
{
	return a.second<b.second;
}
int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int t,n,k,q,sz,r,c,maxr;
	cin>>t;
	while(t--)
	{
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++)
		{
			cin>>sz;
			s[i].push_back(sz);
			for(int j=1,t;j<=sz;j++)
			{
				cin>>t;
				s[i].push_back(t);
			}
		}
		int maxr=0;
		for(int i=1;i<=q;i++)
		{
			cin>>r>>c;
			maxr=max(r,maxr);
			qry.push_back({{r,c},i});
		}
		sort(qry.begin(),qry.end());
		v.push_back({1,0});
		int cnt=0;
		for(int i=1;i<=maxr;i++)
		{
			for(int l=0;l<v.size();l++)
			{
				for(int j=1;j<=n;j++)
				{
					cnt=0;
					for(int k=1;k<s[j].size();k++)
					{
						cnt=max(0,cnt-1);
						if(s[j][k]==v[l].first)
						{
							cnt=k;
							if(v[l].second==1)
								continue;
							else
								nxt.insert({s[j][k],1});
						}
						if(cnt)
							nxt.insert({s[j][k],0});
					}
				}
			}
			v.clear();
			int lst1=0,lst2=0;
			for(set<pair<int,int> >::iterator it=nxt.begin();it!=nxt.end();++it)
			{
				if((*it).second==1&&lst1==(*it).first)
					continue;
				v.push_back(*it);
				lst1=(*it).first;
			}
			nxt.clear();
			sort(v.begin(),v.end());
			for(int j=0;j<v.size();j++)
			{
				if(qry[tot].first.first>i)
					break;
				while(qry[tot].first.first<i)
				{
					tot++;
				}
				if(v[j].first==qry[tot].first.second)
				{
					mym[qry[tot].first]=1;
					tot++;
					continue;
				}
				if(v[j].first>qry[tot].first.second)
					tot++;
			}
		}
		sort(qry.begin(),qry.end(),cmp);
		for(int i=0;i<qry.size();i++)
		{
			cout<<mym[qry[i].first]<<'\n';
		}
	}
	return 0;
}