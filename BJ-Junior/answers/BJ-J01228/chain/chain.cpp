#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int M=2e5+5;
int n,k,q;
int l[N],s[N][N];
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t,r,c;
	cin>>t;
	while(t--)
	{
		cin>>n>>k>>q;//参与游戏的人数,接龙序列长度上限,任务个数
		for(int i=1;i<=n;i++)
		{
			cin>>l[i];
			for(int j=1;j<=l[i];j++)
			{
				cin>>s[i][j];
			}
		}
		while(q--)
		{
            bool f=0;
			cin>>r>>c;//r:轮，c：最后一个
			for(int i=1;i<=n;i++)
            {
                if(s[i][1]!=1) continue;
                for(int j=2;j<=min(l[i],k);j++)
                {
                    if(s[i][j]==c)
                    {
                        cout<<"1\n";
                        f=1;
                        break;
                    } 
                }
                if(f) break;
            }
            if(!f)  cout<<"0\n";
		}
	}
    return 0;
}
