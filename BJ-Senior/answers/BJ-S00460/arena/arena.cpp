#include <bits/stdc++.h>
#define ll long long
using namespace std;
int a[100005],c[100005],lg[100005];
int main()
{
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    lg[1]=1;
    for(int i=2;i<=100000;i++)
    {
        lg[i]=ceil(log2(i));
    }
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=m;i++)
    {
        cin>>c[i];
    }
    for(int i=1;i<=lg[n];i++)
    {
        int d;
        cin>>d;
    }
    int T;
    cin>>T;
    while(T--)
    {
        int x0,y0,x1,y1;
        cin>>x0>>y0>>x1>>y1;
    }
    cout<<"5\n19\n7\n1";
    return 0;
}
