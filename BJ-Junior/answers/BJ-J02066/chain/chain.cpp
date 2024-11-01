#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
using namespace std;
const int N=1e5;
int T,n,k,q,l[N+5],buk[N*2+5],pos[N+5];
vector<int> s[N+5];
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    scanf("%d",&T);
    while(T--)
    {
        memset(buk,0,sizeof(buk));
        memset(pos,0x3f,sizeof(pos));
        scanf("%d%d%d",&n,&k,&q);
        for(int i=1;i<=n;i++)
            s[i].clear();
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&l[i]);
            for(int j=1;j<=l[i];j++)
            {
                int x;scanf("%d",&x);
                s[i].push_back(x);
            }
            if(s[i][0]==1)
            {
                for(int j=0;j<s[i].size();j++)
                    buk[s[i][j]]=1,pos[s[i][j]]=
                    min(pos[s[i][j]],j);
            }
        }
        for(int i=1;i<=q;i++)
        {
            int r,c;scanf("%d%d",&r,&c);
            if(buk[c]==1&&r==1&&pos[c]<=k&&pos[c]>=2) printf("1\n");
            else printf("0\n");
        }
    }
    return 0;
}
