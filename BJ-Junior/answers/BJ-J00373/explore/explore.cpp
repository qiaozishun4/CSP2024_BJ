#include<iostream>
#include<bits/stdc++.h>
#include<cstring>
using namespace std;
string c[1050];
bool b[1050][1050];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    long long t;
    cin >> t;
    for (int ii=1;ii<=t;ii++)
    {
        long long x,y,n,m,k,d,ans=0;
        memset(b,0,sizeof(b));
        cin >>n >>m >> k >>x >>y >> d;
        y--;
        for (int i=1;i<=n;i++)
        {
            cin >> c[i];
        }
        b[x][y]=1;
        ans++;
        for (int i=1;i<=k;i++)
        {
            if (d==0)
            {
                if (c[x][y+1]=='x' || y+1>=m)d=(d+1)%4;
                else{
                    y++;
                    if (b[x][y]==0)ans++;
                    b[x][y]=1;
                }
            }
            else if (d==1)
            {
                if (c[x+1][y]=='x' || x+1>n)d=(d+1)%4;
                else{
                    x++;
                    if (b[x][y]==0)ans++;
                    b[x][y]=1;
                }
            }
            else if (d==2)
            {
                if (c[x][y-1]=='x' || y-1<0)d=(d+1)%4;
                else{
                    y--;
                    if (b[x][y]==0)ans++;
                    b[x][y]=1;
                }
            }
            else if (d==3)
            {
                if (c[x-1][y]=='x' || x-1<1)d=(d+1)%4;
                else{
                    x--;
                    if (b[x][y]==0)ans++;
                    b[x][y]=1;
                }
            }
        }
        cout << ans <<endl;
    }
    return 0;
}
