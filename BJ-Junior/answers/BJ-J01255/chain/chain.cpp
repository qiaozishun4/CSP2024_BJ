#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
#define MAXL 200005
#define MAXS 200005
#define MAXR 103
int T;
int n,k,q;
int L,S[MAXL],r,c;
vector<int> edge[MAXS];
int vis[MAXS][MAXR];
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>T;
    while(T--)
    {
        cin>>n>>k>>q;
        for(int i=0;i<MAXS;i++) edge[i].clear();
        for(int i=0;i<n;i++)
        {
            cin>>L;
            for(int j=0;j<L;j++)
            {
                cin>>S[j];
                for(int k=0;k<j;k++) edge[S[k]].push_back(S[j]);
            }
        }
        for(int i=0;i<MAXS;i++) for(int j=0;j<MAXR;j++) vis[i][j]=0;
        vis[1][0]=1;
        for(int j=0;j<MAXR;j++)
        {
            for(int i=1;i<MAXS;i++)
            {
                if(vis[i][j])
                {
                    for(int k=0;k<edge[i].size();k++)
                    {
                        vis[edge[i][k]][j+1]=1;
                    }
                }
            }
        }
        for(int qq=0;qq<q;qq++)
        {
            cin>>c>>r;
            cout<<vis[c][r]<<endl;
        }
    }
    return 0;
}
