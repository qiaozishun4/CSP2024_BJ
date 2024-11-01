#include<bits/stdc++.h>
using namespace std;
int n,k,q;
const int N=1e5+5;
vector<int> s[N];
int l[N];
int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	int tt=1;
	while(tt<=T)
	{
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++)
		{
			cin>>l[i];
			for(int j=1;j<=l[i];j++)
			{
				int cinn;
				cin>>cinn;
				s[i].push_back(cinn);
			}
		}
		for(int i=1;i<=q;i++)
		{
			int r,c;
			cin>>r>>c;
			bool flag=0;
			if(r==1)
			{
				for(int i=1;i<=n;i++)
				{
					for(int j=0;j<l[i];j++)
					{
						if(s[i][j]==c)
						{
for(int i2=j-k+1;i2<=j-1;i2++)
{
	if(s[i][i2]==1)
	{
		flag=1;
		break;
	}
}					
						}
						if(flag)
						{
							break;
						}
					}
					if(flag)
					{
						break;
					}
				}
				cout<<flag<<endl;
			}	
			else
			{
				for(int i=1;i<=n;i++)
				{
					for(int j=0;j<l[i];j++)
					{
						if(s[i][j]==c)
						{
							flag=1;	
						}
					}
				}
				cout<<flag<<endl;
			}		
		}
		memset(s,0,sizeof(s));
		memset(l,0,sizeof(l));
		tt++;
	}
	return 0;
}
//pian fen