#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int T,n,m,a2[N],c[N],a[N],K,r[25][N],x[5],ans[N];
int main()
{
    freopen("arena.in","r",stdin);
    freopen("arena.out","r",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++)cin >> a2[i];
    for(int i=1;i<=m;i++)cin >> c[i];
    for(int i=1;i<n;i*=2)
    {
        K++;
    }
    for(int i=1;i<=K;i++)
    {
        cin >> r[i][0];
        int num=1;
        for(int j=1;j<=K-i;j++)
        {
            num*=2;
        }
        for(int j=num;j>=1;j--)
        {
            r[i][j]=r[i][0]%10;
            r[i][0]/=10;
        }
    }
    cin >> T;
    while(T--)
    {
        cin >> x[0] >> x[1] >> x[2] >> x[3];
        for(int b=1;b<=m;b++)
        {

            int num=1;
            for(int j=1;j<=K;j++)
            {
                num*=2;
            }
                for(int i=1;i<=num;i++)
            {
                a[i]=a2[i]^x[i%4];
            }
            for(int i=1;i<=K;i++)
            {
                for(int j=1;j<=num;j+=2*i)
                {
                    int pvp1,pvp2;
                    for(int k=1;k<=2*i;i++)if(a[k]!=-1){pvp1=i;break;}
                    for(int k=pvp1;k<=2*i;i++)if(a[k]!=-1){pvp2=i;}
                    if(r[i][j/(2*i)+1]==0)if(a[pvp1]>=i)a[pvp2]=-1;else a[pvp1]=-1;
                    if(r[i][j/(2*i)+1]==0)if(a[pvp2]>=i)a[pvp1]=-1;else a[pvp2]=-1;
                }
            }
            for(int i=1;i<=num;i++)
            {
                if(a[i]!=-1)
                {
                    ans[b]=a[i];
                    break;
                }
            }
        }
        int reallans=0;
        for(int i=1;i<=m;i++)
        {
            reallans^=(i*ans[i]);
        }
        cout << reallans << endl;
    }
    return 0;
}
