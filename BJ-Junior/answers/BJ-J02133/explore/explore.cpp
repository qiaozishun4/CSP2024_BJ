#include<iostream>
#include<cstring>
#include<map>
using namespace std;
#define ll long long
ll dx[4]={0,1,0,-1};
ll dy[4]={1,0,-1,0};
ll T;
ll n,m,k;
char c[1010][1010];
ll ans;
ll maxi;
//n<=1000,m<=1000,k<=1000000
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    while(T--)
    {
        map<pair<ll,ll>,ll> ma;
        memset(c,0,sizeof(c));
        bool is=true;
        ans=1;
        maxi=1;
        ll x,y,d;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        pair<ll,ll> p;
        p.first=x;
        p.second=y;
        ma[p]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>c[i][j];
                if(c[i][j]=='x')
                {
                    is=false;
                }
            }
        }
        if(is)
        {
            ll xxx=2*(n-2)+2*(m-2)+4;
            if(xxx>=k)
            {
                cout<<k<<endl;
            }
            else{
                cout<<xxx<<endl;
            }
            continue;
        }
        for(int i=1;i<=k;)
        {
            ll xx=x+dx[d];
            ll yy=y+dy[d];
            if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&c[xx][yy]=='.')
            {
                x=xx;
                y=yy;
                i++;
                p.first=x;
                p.second=y;
                if(!ma[p])
                {
                    ans++;
                    ma[p]=1;
                }
            }
            else{
                while(!(xx>=1&&xx<=n&&yy>=1&&yy<=m&&c[xx][yy]=='.'))
                {
                    d=(d+1)%4;
                    xx=x+dx[d];
                    yy=y+dy[d];
                    i++;
                    if(i==k+1)
                    {
                        break;
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

/*
2
1 5 4
1 1 2
....x
5 5 20
1 1 0
.....
.xxx.
.x.x.
..xx.
x....
*/
