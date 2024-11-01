#include<iostream>
#include<cstring>
using namespace std;
int t,n,m,k,x,y,d,nx,ny,s;
char g[1005][1005];
bool v[1005][1005];
void turn()
{
    d++;
    if(d>3)
    {
        d=0;
    }
    return;
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>t;
    while(t--)
    {
        memset(g,'x',sizeof(g));
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>g[i][j];
            }
        }
        memset(v,0,sizeof(v));
        v[x][y]=1;
        while(k--)
        {
            nx=x;
            ny=y;
            if(!d)
            {
                ny++;
            }
            else if(d<2)
            {
                nx++;
            }
            else if(d<3)
            {
                ny--;
            }
            else
            {
                nx--;
            }
            if(g[nx][ny]=='x')
            {
                turn();
                continue;
            }
            x=nx;
            y=ny;
            v[nx][ny]=1;
        }
        s=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                s+=v[i][j];
            }
        }
        cout<<s<<"\n";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}