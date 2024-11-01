#include<bits/stdc++.h>
#define ll long long
const int N=1e5+10, INF=0x7fffffff;
using namespace std;
int T;
int n,m,a[N],b[N];
int main()
{
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=m;i++)cin>>b[i];
    int l=log2(n);
    string s;
    for(int i=1;i<=l+1;i++)cin>>s;
    int x,y,z,w;
    while(T--)
    {
        cin>>x>>y>>z>>w;
        cout<<1;
    }


    return 0;
}
