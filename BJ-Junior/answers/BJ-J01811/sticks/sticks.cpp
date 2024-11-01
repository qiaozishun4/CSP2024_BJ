#include <bits/stdc++.h>
using namespace std;
int numbs[10]={6,2,5,5,4,5,6,3,7,6};
string ans="-1";
bool yes=0;
inline string wei(string s,int x)
{
	char c=x+'0';
	return s+c;
}
inline bool small(string x,string y)
{
	if(x.size()!=y.size()) return x.size()<y.size();
	for(int i=0;i<x.size();i++)
	{
		if(x[i]!=y[i]) return x[i]<y[i];
	}
	return 0;
}
void dfs(int sheng,string now)
{
	if(sheng==1) return;
	if(sheng==0)
	{
		if(yes==0||small(now,ans)) ans=now;
		yes=1;
	}
	for(int i=0;i<10;i++)
	{
		if(i==0&&now=="") continue;
		if(sheng<numbs[i]) continue;
		dfs(sheng-numbs[i],wei(now,i));
	}
}
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		ans="-1";
		yes=0;
		dfs(n,"");
		if(ans=="-1"||yes==0)
		{
			cout<<-1<<endl;
		}
		else cout<<ans<<endl;
	}
	return 0;
}