#include<iostream>
#include<cstring>
using namespace std;
bool dp[102][200005];
void play()
{
    memset(dp,false,sizeof(dp));
    int n,k,q,s[200005];
    bool a[2005][2005];
    memset(a,false,sizeof(a));
    cin>>n>>k>>q;
    for(int i=1;i<=n;i++)
    {
        int l;
        scanf("%d",&l);
        for(int j=1;j<=l;j++)
        {
            scanf("%d",&s[j]);
        }
        for(int j=1;j<=l-k+1;j++)
        {
            for(int z=j+1;z<=j+k-1;z++)
            {
                if(s[j]<2005&&s[z]<2005)a[s[j]][s[z]]=true;
            }
        }
    }
    dp[0][1]=true;
    for(int i=1;i<=102;i++)
    {
        for(int j=0;j<=2000;j++)
        {
            for(int k=0;k<=2000;k++)
            {
                if(a[j][k]&&dp[i-1][k])
                    dp[i][j]=true;
            }
        }
    }
    for(int i=1;i<=q;i++)
    {
        int qw,we;
        scanf("%d%d",&qw,&we);
        if(dp[qw][we])
        {
            cout<<1;
        }
        else{
            cout<<0;
        }
        cout<<endl;
    }
}
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        play();
    }
    return 0;
}