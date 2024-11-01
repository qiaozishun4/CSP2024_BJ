#include <iostream>
#include <cstring>
using namespace std;

const int maxnm=1e3+100;
char maps[maxnm][maxnm];
bool map1[maxnm][maxnm];

struct f{
    int prex;
    int prey;
};

f test(int d,int x,int y)
{
    if(d==0) y++;
    if(d==1) x++;
    if(d==2) y--;
    if(d==3) x--;
    f tmp;
    tmp.prex=x;
    tmp.prey=y;
    return tmp;
}

int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t,n,m,k;
    cin>>t;
    int x,y,d;
    while(t--)
    {
        memset(map1,0,sizeof(map1));
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>maps[i][j];
            }
        }
        map1[x][y]=1;

        while(k--)
        {
            f pre;
            pre=test(d,x,y);
            if(pre.prex>n||pre.prey>m||pre.prex<1||pre.prey<1||maps[pre.prex][pre.prey]=='x')
            {
                d=(d+1)%4;
                continue;
            }
            x=pre.prex;
            y=pre.prey;
            map1[x][y]=1;
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(map1[i][j]) ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
