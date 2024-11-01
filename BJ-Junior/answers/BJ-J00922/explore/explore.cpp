#include<bits/stdc++.h>
using namespace std;
int n,m,k,x,y,d,sum=1,t;
char a[1005][1005];
bool b[1005][1005];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        sum=1;
        cin>>n>>m>>k>>x>>y>>d;
        for(int j=1;j<=n;j++)
        {
            for(int p=1;p<=m;p++)
            {
                cin>>a[j][p];
            }
        }
        for(int j=1;j<=k;j++)
        {
             if(d==0){
                if(y+1>0&&x>0&&a[x][y+1]=='.'&&y+1<=m&&x<=n)
                {
                    y++;
                    if(b[x][y]==0)
                    sum++;
                    b[x][y]=1;
                }
                else{
                    d=(d+1)%4;
                }
            }
            else if(d==1)
            {
                if(y>0&&x+1>0&&a[x+1][y]=='.'&&x+1<=n&&y<=m)
                {
                    x++;
                    if(b[x][y]==0)
                    sum++;
                    b[x][y]=1;
                }
                else{
                    d=(d+1)%4;
                }
            }
            else if(d==2)
            {
                if(x>0&&y-1>0&&a[x][y-1]=='.'&&x<=n&&y-1<=m)
                {
                    y--;
                     if(b[x][y]==0)
                    sum++;
                    b[x][y]=1;
                }
                else{
                    d=(d+1)%4;
                }
            }
            else
            {
                if(y>0&&x-1>0&&a[x-1][y]=='.'&&x-1<=n&&y<=m)
                {
                    x--;
                    if(b[x][y]==0)
                    sum++;
                    b[x][y]=1;
                }
                else{
                    d=(d+1)%4;
                }
            }
        }
        cout<<sum<<endl;
        for(int j=1;j<=n;j++)
        {
            for(int p=1;p<=m;p++)
            {
                b[j][p]=0;
            }
        }
    }
    return 0;
}
