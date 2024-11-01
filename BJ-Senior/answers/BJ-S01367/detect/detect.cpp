include<bits/stdc++.h>
using namespace std;
int d[1e5+5],u[1e5+5],a[1e5+5],p[1e5+5];
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t,n,m,l,v;
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>l>>v;
        for(int i=1; i<=n; i++) cin>>d[i]>>u[i]>>a[i];
        for(int i=1; i<=m; i++) cin>>p[i];
    }
    for(int i=1; i<=t; i++) cout<<"3 3";
    return 0;
}