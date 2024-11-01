#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,d,x,y,ans=0;
char a[1005][1005];
bool go(int d2)
{
    if(d2==0&&(y+1>m||a[x][y+1]=='x'))
        return false;
    if(d2==1&&(x+1>n||a[x+1][y]=='x'))
        return false;
    if(d2==2&&(y-1<1||a[x][y-1]=='x'))
        return false;
    if(d2==3&&(x-1<1||a[x-1][y]=='x'))
        return false;
    return true;
}
void explore()
{
    int d1=d;
    for(int i=1;i<=k;i++)
    {
        //printf("%d %d %d\n",x,y,d);
        if(d==0&&a[x][y+1]=='x')
            d1=(d+1)%4;
        else
        {
            if(d==1&&a[x+1][y]=='x')
                d1=(d+1)%4;
            else
            {
                if(d==2&&a[x][y-1]=='x')
                    d1=(d+1)%4;
                else
                {
                    if(d==3&&a[x-1][y]=='x')
                        d1=(d+1)%4;
                }
            }

        }
        if(go(d1))
        {
            ans++;
        }
        switch(d)
        {
            case 0:y++;break;
            case 1:x++;break;
            case 2:y--;break;
            case 3:x--;break;
        }
        d=d1;
    }
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                cin>>a[i][j];
        explore();
        printf("%d\n",ans);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
