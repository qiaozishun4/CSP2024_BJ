#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool work[105][105];
ll n,m,k;
char ch[105][105];
int main()
{
   freopen("explore.in","r",stdin);
   freopen("explore.out","w",stdout);
    ll t;cin>>t;
    while(t--)
    {
        memset(work,0,sizeof(work));
        memset(ch,0,sizeof(ch));
        cin>>n>>m>>k;
        ll x,y,d;cin>>x>>y>>d;
        work[x][y]=true;
        for(ll i=1;i<=n;i++)
        {
            for(ll j=1;j<=m;j++)
            {
                cin>>ch[i][j];
            }
        }
        for(ll i=1;i<=k;i++)
        {
            if(d==0)
            {
                if(ch[x][y+1]=='x'||y+1>m) d=(d+1)%4;
                else y++;
            }
            else if(d==1)
            {
                if(ch[x+1][y]=='x'||x+1>n) d=(d+1)%4;
                else x++;
            }
            else if(d==2)
            {
                if(ch[x][y-1]=='x'||y-1<1) d=(d+1)%4;
                else y--;
            }
            else if(d==3)
            {
                if(ch[x-1][y]=='x'||x-1<1) d=(d+1)%4;
                else x--;
            }
            work[x][y]=true;
//            cout<<x<<" "<<y<<' '<<d<<endl;
        }
        ll ans=0;
        for(ll i=1;i<=n;i++)
        {
            for(ll j=1;j<=m;j++)
            {
                if(work[i][j]) ans++;
 //              cout<<work[i][j]<<" ";
            }
 //           cout<<endl;
        }
        cout<<ans<<'\n';
    }
    return 0;
}
