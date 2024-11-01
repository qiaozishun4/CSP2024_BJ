#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    int n,m,k,ans=0,x,y,z;
    char c[1005][1005];
    int v[1005][1005];
    cin>>T;
    while(T--)
    {
        ans=0;
        memset(c,' ',sizeof c);
        memset(v,0,sizeof v);
        scanf("%d%d%d%d%d%d",&n,&m,&k,&x,&y,&z);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>c[i][j];
            }
        }
        v[x][y]=1;
        ans++;
        int nx,ny;
        for(int step=1;step<=k;step++)
        {
            if(z==0)
            {
                nx=x;
                ny=y+1;
                y++;
                if(c[nx][ny]=='.' && nx>=1 && nx<=n && ny>=1 && ny<=m)
                {
                    if(v[nx][ny]==0)
                        ans++;
                    v[nx][ny]=1;
                }
                else
                    y--;
            }
            if(z==1)
            {
                nx=x+1;
                ny=y;
                x++;
                if(c[nx][ny]=='.' && nx>=1 && nx<=n && ny>=1 && ny<=m)
                {
                    if(v[nx][ny]==0)
                        ans++;
                    v[nx][ny]=1;
                }
                else
                    x--;
            }
            if(z==2)
            {
                nx=x;
                ny=y-1;
                y--;
                if(c[nx][ny]=='.' && nx>=1 && nx<=n && ny>=1 && ny<=m)
                {
                    if(v[nx][ny]==0)
                        ans++;
                    v[nx][ny]=1;
                }
                else
                    y++;
            }
            if(z==3)
            {
                nx=x-1;
                ny=y;
                x--;
                if(c[nx][ny]=='.' && nx>=1 && nx<=n && ny>=1 && ny<=m)
                {
                    if(v[nx][ny]==0)
                        ans++;
                    v[nx][ny]=1;
                }
                else
                    x++;
            }
            if(!(c[nx][ny]=='.' && nx>=1 && nx<=n && ny>=1 && ny<=m))
                z=(z+1)%4;
            //cout<<x<<" "<<y<<" "<<z<<" "<<ans<<endl;
        }
        printf("%d\n",ans);
    }
    return 0;
}
