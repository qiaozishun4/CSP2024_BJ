#include<bits/stdc++.h>
using namespace std;
int n,b[1010][1010],t,m,k,a[1010][1010],ans,T;
bool in(int x,int y)
{
    if(x<1||x>n||y<1||y>m||a[x][y]==1) return 0;
    return 1;
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    while(T--)
    {
        memset(b,0,sizeof(b));
        cin>>n>>m>>k;
        int x,y,chao;
        cin>>x>>y>>chao;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                char p;
                cin>>p;
                if(p=='.') a[i][j]=0;
                if(p=='x') a[i][j]=1;
            }
        }
       // cout<<11213;

        ans=1;
        b[x][y]=1;
        while(k--)
        {
            if(chao==0)
            {
                if(!in(x,y+1)) chao++;
                else y++,ans+=(1-b[x][y]),b[x][y]=1;
            }
            else if(chao==1)
            {
                if(!in(x+1,y)) chao++;
                else x++,ans+=(1-b[x][y]),b[x][y]=1;
            }
            else if(chao==2)
            {
                if(!in(x,y-1)) chao++;
                else y--,ans+=(1-b[x][y]),b[x][y]=1;
            }
            else if(chao==3)
            {
                if(!in(x-1,y)) chao=0;
                else x--,ans+=(1-b[x][y]),b[x][y]=1;
            }
         //   cout<<x<<" "<<y<<endl;
        }
        cout<<ans<<endl;
    }
    return 0;
}
