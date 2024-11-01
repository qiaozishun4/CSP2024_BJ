#include<bits/stdc++.h>
using namespace std;
char a[1010][1010];
bool vis[1010][1010];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,k;
        cin>>n>>m>>k;
        int x,y,d;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>a[i][j];
            }
        }
        memset(vis,false,sizeof(vis));
        int cnt=1;
        vis[x][y]=true;
        k++;
        while(k--)
        {
            //cout<<x<<" "<<y<<" "<<d<<endl;
            if(vis[x][y]==false)
            {
                cnt++;
                vis[x][y]=true;
            }
            int tx=x,ty=y;
            if(d==0)
            {
                ty++;
            }
            else if(d==1)
            {
                tx++;
            }
            else if(d==2)
            {
                ty--;
            }
            else
            {
                tx--;
            }
            if(tx<=n&&tx>=1&&ty<=m&&ty>=1&&a[tx][ty]=='.')
            {
                x=tx,y=ty;
            }
            else
            {
                d=(d+1)%4;
            }
        }
        cout<<cnt<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
