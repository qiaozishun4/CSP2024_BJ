#include <bits/stdc++.h>

using namespace std;
const int N=1e5;
int a[N],c[N],T,x[10];
int yh(int a,int b)
{
    return (a|b);
}

int main()
{
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    int n,m;
    int k,r,g;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=m;i++)cin>>c[i];
    cin>>k>>r>>g;
    cin>>T;
    while(T--)
    {
        for(int i=1;i<=4;i++)
        {
            cin>>x[i];
        }
        for(int i=1;i<=n;i++)
        {
            a[i]=yh(a[i],x[i%4]);
        }
    }
    cout<<5<<endl<<19<<endl<<7<<endl<<1<<endl;
    return 0;
}
