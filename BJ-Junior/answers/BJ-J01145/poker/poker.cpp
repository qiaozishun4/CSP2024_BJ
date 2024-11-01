#include <bits/stdc++.h>
using namespace std;
int n,p[1005][1005];

int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin >> n;
    for(int i=1;i<=1000;i++)
    {
        for(int j=1;j<=1000;j++)
        {
            p[i][j]=0;
        }
    }
    for(int i=0;i<n;i++)
    {
        char hs,sz;
        cin >> hs >> sz;
        int x=hs,y=sz;
        p[hs][sz]=1;
    }
    int ans=52;
    for(int i=1;i<=1000;i++)
    {
        for(int j=1;j<=1000;j++)
        {
            ans-=p[i][j];
        }
    }
    cout << ans;
    return 0;
}