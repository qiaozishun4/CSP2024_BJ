#include<iostream>
using namespace std;
char c[1005][1005];
bool flag[1005][1005]={};
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t,cnt=0;
    cin>>t;
    while(t--)
    {
        int n,m,k,x,y,d,ans=1;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>c[i][j];
            }
        }
        flag[x][y]=1;
        while(k--)
        {
            if(flag[x][y]==0)
            {
                flag[x][y]=1;
                ans++;
            }
            int a,b;
            if(d==0)
            {
                a=x;
                b=y+1;
            }
            else if(d==1)
            {
                a=x+1;
                b=y;
            }
            else if(d==2)
            {
                a=x;
                b=y-1;
            }
            else if(d==3)
            {
                a=x-1;
                b=y;
            }
            if(c[a][b]=='.')
            {
                x=a;
                y=b;
            }
            else if(c[a][b]=='x'||a==0||b==0||a>n||b>m)
            {
                d=(d+1)%4;
            }
            if(flag[x][y]==0)
            {
                flag[x][y]=1;
                ans++;
            }
        }
        cout<<ans<<'\n';
    }
}
