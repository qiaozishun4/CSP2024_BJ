#include<iostream>
#include<vector>
#include<cstring>
#include<map>
using namespace std;
#define maxn (int)1e3
#define maxq (int)1e3
#define maxc 2000
#define maxr (int)1e2
int t,n,k,q;
int l[maxn+10],r[maxq+10],c[maxq+10];
vector<int>s[maxn+10],val[maxn+10][maxc+10],f[maxr+5][maxn+10];
map<int,int>mp;
int main()
{
    //freopen("chain.in","r",stdin);
    //freopen("chain.out","w",stdout);
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    scanf("%d",&t);
    while(t--)
    {
        mp.clear();
        scanf("%d%d%d",&n,&k,&q);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&l[i]);
            s[i].clear();
            for(int p=0;p<=maxr;p++)f[p][i].clear();
            for(int p=0;p<=maxc;p++)val[i][p].clear();
            for(int j=0;j<l[i];j++)
            {
                scanf("%d",&c[0]);
                s[i].push_back(c[0]);
                for(int p=0;p<=maxr;p++)f[p][i].push_back(false);
                mp[c[0]];
            }
        }
        int rmx=0;
        for(int i=0;i<q;i++)
        {
            scanf("%d%d",&r[i],&c[i]);
            rmx=max(rmx,r[i]);
        }
        int cnt=0;
        for(auto i=mp.begin();i!=mp.end();i++)mp[i->first]=++cnt;
        for(int i=1;i<=n;i++)
            for(int j=0;j<l[i];j++)
            {
                s[i][j]=mp[s[i][j]];
                if(s[i][j]==1)f[0][i][j]=true;
                for(int p=1;p<=cnt;p++)val[i][p].push_back(false);
                for(int p=1;p<k;p++)
                {
                    if(j-p<0||val[i][s[i][j]][j-p])break;
                    val[i][s[i][j]][j-p]=true;
                }
            }
        for(int i=1;i<=rmx;i++)
            for(int j=1;j<=n;j++)
                for(int d=0;d<l[j];d++)
                    for(int p=1;p<=n;p++)
                        if(p!=j)
                            for(int q=0;q<l[p];q++)
                                if(val[p][s[j][d]][q])f[i][j][d]=f[i][j][d]||f[i-1][p][q];
        for(int i=0;i<q;i++)
        {
            if(!mp[c[i]])
            {
                printf("0\n");
                continue;
            }
            bool ans=false;
            for(int j=1;j<=n;j++)
                for(int p=0;p<l[j];p++)
                    if(val[j][mp[c[i]]][p])ans=ans||f[r[i]-1][j][p];
            printf("%d\n",ans);
        }
    }
    return 0;
}
//多给点分吧，救救我这个蒟蒻～谢谢
