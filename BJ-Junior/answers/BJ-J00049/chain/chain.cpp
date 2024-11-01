#include<bits/stdc++.h>
using namespace std;

int n,k,q,a[11000][11000],l[11000],x[11000];
//int cnt[11000],f[11000][1100][11000][2];

/*void dfs(int wi,int stp,int c)
{
    if(stp>k)
    {
        ++cnt[wi];
        for(int i=1;i<=n;i++)
            f[wi][cnt[wi]][i][1]=f[wi][cnt[wi]][i][1],f[wi][cnt[wi]][i][0]=f[wi][cnt[wi]][i][0];
    }
    if(stp==1)
    {
        for(int i=1;i<=l[wi];i++)
        {
            if(a[wi][i]==c)
            {
                f[wi][0][1][0]=i;
                f[wi][0][1][0]=a[wi][i];
            }
        }
    }
}*/

bool is(int r,int c,int wi)
{
    //dfs(i,1,(r==1?1:c));
    //if(cnt[i]!=0)return 1;
    for(int i=1;i<=l[wi];i++)
    {
        if(a[wi][i]==(r==1?1:c))
            for(int j=2;j<=k;j++)
            {
                if(l[i]-i>=j)return 1;
            }
    }
    return 0;
}

int main()
{
    freopen("chain1.in","r",stdin);
    freopen("chain.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++)
        {
            cin>>l[i];
            for(int j=1;j<=l[i];j++)
            {
                cin>>a[i][j];
            }
        }
        int r,c;
        for(int i=1;i<=q;i++)
        {
            cin>>r>>c;
            if(is(r,c,i))cout<<1<<endl;
            else cout<<0<<endl;
        }
    }
    return 0;
}
