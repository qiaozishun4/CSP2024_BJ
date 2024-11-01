#include <iostream>
using namespace std;
#define ll long long
ll n,m,k,T;
ll x,y,d;
ll num;
char c[3010][3010];
ll ans;
ll a;
ll go[3010][3010];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    while(T--)
    {
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                cin>>c[i][j];
            }
        }
        if(d==0)
        {
            if(c[x][y+1]=='.')
            {
                cout<<"2"<<endl;
                continue;
            }
            cout<<"1"<<endl;
        }
        if(d==1)
        {
            if(c[x-1][y]=='.')
            {
                cout<<"2"<<endl;
                continue;
            }
            cout<<"1"<<endl;
        }
        if(d==2)
        {
            if(c[x][y-1]=='.')
            {
                cout<<"2"<<endl;
                continue;
            }
            cout<<"1"<<endl;
        }
        if(d==3)
        {
            if(c[x-1][y]=='.')
            {
                cout<<"2"<<endl;
                continue;
            }
            cout<<"1"<<endl;
        }
    }

    return 0;
}
