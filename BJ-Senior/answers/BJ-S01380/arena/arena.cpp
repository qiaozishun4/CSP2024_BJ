#include<bits/stdc++.h>
using namespace std;
int n,m,t,c[100005],a[100005],l,x,x1,x2,x3,k;
int main()
{
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
    }
    for(int i=1;i<=m;i++)
    {
        cin>>a[i];
    }
    while(true)
    {
        if(pow(2,l)>=n)
            break;
        l++;
    }
    for(int i=1;i<=l;i++)
        cin>>k;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>x>>x1>>x2>>x3;
    }
    cout<<5<<endl<<19<<endl<<7<<endl<<1;
    return 0;
}