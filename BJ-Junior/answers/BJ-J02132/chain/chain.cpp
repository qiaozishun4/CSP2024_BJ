#include<bits/stdc++.h>
using namespace std;
string s[1010];
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
		int n,k,q;
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++)
		{
			int l;
			cin>>l;
			cin>>s[i];
		}
		bool flag=false;
		for(int i=1;i<=q;i++)
		{
			char r;
			int c;
			cin>>r>>c;
			
			int len=s[i].size();
			for(int j=0;j<len;j++)
			{
				if(s[i][j]==r)
				{
					flag=true;
					break;
				}
			}
		}
		if(!flag)
		{
			cout<<0<<endl;
		}
		else
		{
			cout<<1<<endl;
		}
    }
    return 0;
}
