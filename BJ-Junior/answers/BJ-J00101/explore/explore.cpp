#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,k,x,y,d;
char c[1005][1005];
char book[1005][1005];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        memset(book,0,sizeof book);
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        book[x][y]=1;
        int ans=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++) cin>>c[i][j];
        }
        while(k--)
        {

            if(d==0&&y+1<=m&&c[x][y+1]=='.')
            {
                y=y+1;
                if(!book[x][y]) ans++;
                book[x][y]=1;
            }
            else if(d==1&&x+1<=n&&c[x+1][y]=='.')
            {
                x=x+1;
                if(!book[x][y]) ans++;
                book[x][y]=1;
            }
            else if(d==2&&y-1>0&&c[x][y-1]=='.')
            {
                y=y-1;
                if(!book[x][y]) ans++;
                book[x][y]=1;
            }
            else if(d==3&&x-1>0&&c[x-1][y]=='.')
            {
                x=x-1;
                if(!book[x][y]) ans++;
                book[x][y]=1;
            }
            else
            {
                d=(d+1)%4;
            }
            //cout<<x<<" "<<y<<" "<<d<<" "<<ans<<endl;
        }
        cout<<ans<<'\n';
    }
    return 0;
}
