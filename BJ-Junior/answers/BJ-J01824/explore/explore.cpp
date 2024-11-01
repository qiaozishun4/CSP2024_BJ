#include<bits/stdc++.h>
using namespace std;
int yon[1005][1005];
//0:keyizou 1:zou guo de -1:zhang ai wu
int ab,fx,sx,sy;
int n,m,k;
void xingdong(int tx,int ty)
{
    if(fx==0)
    {
        tx++;
    }
    else if(fx==1)
    {
        ty--;
    }
    else if(fx==2)
    {
        tx--;
    }
    else if(fx==3)
    {
        ty++;
    }

    if(tx<0||tx>=n||ty<0||ty>=m)
    {
        fx++;
        fx=fx%4;
    }
    else if(yon[tx][ty]==-1)
    {
        fx++;
        fx=fx%4;
    }
    else
    {
        yon[tx][ty]=1;
        sx=tx;
        sy=ty;
    }
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    //da kai wen jian
    cin>>ab;
    for(int abc=1;abc<=ab;abc++)
    {

        int ans=0;
        string temp;
        cin>>n>>m>>k;
        cin>>sx>>sy>>fx;
        for(int i=0;i<n;i++)
        {
            cin>>temp;
            for(int j=0;j<m;j++)
            {
                if(temp[j]=='.')yon[i][j]=0;
                else yon[i][j]=-1;
            }
        }
        yon[sx][sy]=1;
        for(int i=1;i<=k;i++)
        {

            xingdong(sx,sy);
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(yon[i][j]==1)ans++;
            }
        }
        cout<<ans<<endl;

    }

    return 0;
}