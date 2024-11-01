#include<bits/stdc++.h>
using namespace std;
set<int> s;
int h[100005];
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int r;
		cin>>r;
		s.insert(r);
		h[r]++;
	}
	int ans=0;
	int c=0;
	for(auto i=s.begin();i!=s.end();i++)
	{
		for(int x=1;x<=h[*i];x++)
		{
			auto j=s.begin();
			for(int k=1;k<=c;k++)
			{
				j++;
			}
			for(;j!=i;j++)
			{
				int t=*j;
				if(h[t]==0)
				{
					c++;
				}
				else if(*i>*j)
				{
					h[t]--;
					ans++;
					break;
				}
			}
		}
	}
	cout<<n-ans;
	return 0;
}
