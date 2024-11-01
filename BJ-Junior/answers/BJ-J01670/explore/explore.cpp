#include<bits/stdc++.h>
using namespace std;
char x[1002][1002];
int v[1002][1002];
int kh[4]={0,1,0,-1};
int kz[4]={1,0,-1,0};
int T,n,m,k,h,z,d;
int dfs()
{
    memset(v,0,sizeof(v));
    v[h][z]=1;
    int c=1;
    for(int i=1;i<=k;i++)
    {
        int nh,nz;
        nh=h+kh[d];
        nz=z+kz[d];
        if(nh<=0||nh>n||nz<=0||nz>m||x[nh][nz]=='x')
        {
            d=(d+1)%4;
        }
        else
        {
            h=nh;
            z=nz;
        }
        if(v[h][z]==0)
        {
            v[h][z]=1;
            c++;
        }
        //cout<<h<<" "<<z<<" "<<d<<" "<<c<<"\n";
    }
    return c;
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    while(T--)
    {
        cin>>n>>m>>k>>h>>z>>d;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>x[i][j];
            }
        }
        cout<<dfs()<<endl;
    }
    return 0;
}
