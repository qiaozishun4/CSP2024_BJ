#include<bits/stdc++.h>
using namespace std;
const int N=1E3+1;
string ls;
bool f[N][N],fl[N][N];
void Init()
{
    memset(f,0,sizeof(f));
    memset(fl,0,sizeof(fl));
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
        Init();
        int n,m,k,ans=0,x,y,d;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++)
        {
            cin>>ls;
            for(int j=1;j<=m;j++)
            {
                if(ls[j-1]=='.')
                    f[i][j]=0;
                if(ls[j-1]=='x')
                    f[i][j]=1;
            }
        }
        for(int i=1;i<=k;i++)
        {
            if(!fl[x][y])
                ans++,fl[x][y]=1;
            if(d==0)
            {
                y++;
                if(!(1<=x && x<=n && 1<=y && y<=m && !f[x][y]))
                    y--,d=(d+1)%4;
            }
            else if(d==1)
            {
                x++;
                if(!(1<=x && x<=n && 1<=y && y<=m && !f[x][y]))
                    x--,d=(d+1)%4;
            }
            else if(d==2)
            {
                y--;
                if(!(1<=x && x<=n && 1<=y && y<=m && !f[x][y]))
                    y++,d=(d+1)%4;
            }
            else if(d==3)
            {
                x--;
                if(!(1<=x && x<=n && 1<=y && y<=m && !f[x][y]))
                    x++,d=(d+1)%4;
            }
        }
        if(!fl[x][y])
            ans++;
        cout<<ans<<endl;
    }
    return 0;
}