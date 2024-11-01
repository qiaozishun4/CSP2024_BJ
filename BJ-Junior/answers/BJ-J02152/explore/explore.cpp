#include <bits/stdc++.h>
using namespace std;

int n,m,k,x,y,d,T;
int i,j,l,ans[6];
char a[1001][1001];
bool b[1001][1001];

int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);

    cin>>T;
    for(i=1;i<=T;i++)
    {
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(j=1;j<=n;j++)
            for(l=1;l<=m;l++)
                cin>>a[l][j];
        for(j=1;j<=n;j++)
            for(l=1;l<=m;l++)
                b[j][l]=false;

        for(j=0;j<=k;j++)
        {
            if(b[x][y]==false)
            {
                b[x][y]=true;
                ans[i]++;
            }

            if(d==0)
            {
                if(x+1>m||a[x+1][y]=='x') d=(d+1)%4;
                else x+=1;
            }
            else if(d==1)
            {
                if(y+1>n||a[x][y+1]=='x') d=(d+1)%4;
                else y+=1;
            }
            else if(d==2)
            {
                if(x-1<1||a[x-1][y]=='x') d=(d+1)%4;
                else x-=1;
            }
            else
            {
                if(y-1<1||a[x][y-1]=='x') d=(d+1)%4;
                else y-=1;
            }
        }
    }

    for(i=1;i<=T;i++)
        cout <<ans[i] <<endl;

    return 0;
}