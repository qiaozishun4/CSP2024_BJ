#include<bits/stdc++.h>
using namespace std;
char a[1010][1010];
bool f[1010][1010];
int fx[4]={0,1,0,-1};
int fy[4]={1,0,-1,0};
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        memset(a,0,sizeof(a));
        memset(f,false,sizeof(f));
        int n,m,k,x,y,d,c=0;
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                cin>>a[i][j];
        f[x][y]=true;
        for(int i=1;i<=k;i++)
        {
            int tx=x+fx[d],ty=y+fy[d];
            if(a[tx][ty]=='.')
            {
                f[tx][ty]=true;
                x=tx;
                y=ty;
            }
            else d=(d+1)%4;
            //cout<<x<<" "<<y<<endl;
        }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                if(f[i][j]) c++;
        cout<<c<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
