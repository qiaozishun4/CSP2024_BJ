#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int N=1e5+5;

int t,n,k,q,l,s[N],r,c;
vector<pii> g[N];
struct node
{
    pii data;
    int step;
};
bool bfs()
{
    queue<node> q;
    for(auto i:g[1])
    {
        if(r==1&&i.fi==c) return 1;
        q.push((node){i,1});
    }
    while(!q.empty())
    {
        node fr=q.front();
        q.pop();
        if(fr.step==r) return 0;
        for(auto i:g[fr.data.fi])
        {
            if(i.se!=fr.data.se)
            {
                if(fr.step+1==r&&i.fi==c) return 1;
                q.push((node){i,fr.step+1});
            }
        }
    }
    return 0;
}
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    scanf("%d",&t);
    while(t--)
    {
        for(int i=1;i<=N-5;i++)
            g[i].clear();
        scanf("%d%d%d",&n,&k,&q);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&l);
            //create_graph
            for(int j=1;j<=l;j++)
                scanf("%d",&s[j]);
            for(int j=1;j<=l-1;j++)
                for(int o=j+1;o<=min(l,j+k-1);o++)
                    g[s[j]].push_back(make_pair(s[o],i));
        }
        while(q--)
        {
            scanf("%d%d",&r,&c);
            printf("%d\n",bfs());
        }
    }
    return 0;
}