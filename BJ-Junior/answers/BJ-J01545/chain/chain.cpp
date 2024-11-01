#include<bits/stdc++.h>
using namespace std;
int a[1010][2010];
int k[2][2010];
void calc()
{
    int n,kt,q;
    cin>>n>>kt>>q;
    k[0][0]=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i][0];
        for(int j=1;j<=a[i][0];j++)
        {
            cin>>a[i][j];
            if(a[i][j]==1)
            {
                k[0][++k[0][0]]=i;
                k[1][k[0][0]]=j;
            }
        }
    }
    for(int i=1;i<=q;i++)
    {
        int r,c;
        cin>>r>>c;
        int f=0;
        for(int j=1;j<=k[0][0];j++)
        {
            int x=k[0][j];
            int y=k[1][j];
            for(int k=y+1;k<=a[x][0]&&k<=y+kt;k++)
            {
                if(a[x][k]==c){
                    cout<<1;
                    f=1;
                    break;
                }
            }
            if(f) break;
        }
        if(!f) cout<<0<<endl;
    }
}
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
        calc();
    }
    return 0;
}