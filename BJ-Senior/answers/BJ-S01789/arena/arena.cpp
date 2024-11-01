#include<bits/stdc++.h>
#define ll long long
using namespace std;
int t,x0[100005],x1[100005],x2[100005],x3[100005],n,m,k,a[100005],c[100005];
string s[100005];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++) cin>>c[i];
    for(int i=2,cnt=1;;i*=2,cnt++)
    {
        if(i>=n)
        {
            k=cnt;
            break;
        }
    }
    for(int i=1;i<=k;i++) cin>>s[i];
    cin>>t;
    for(int i=1;i<=t;i++) cin>>x0[i]>>x1[i]>>x2[i]>>x3[i];
    srand(time(0));
    for(int i=1;i<=t;i++) cout<<rand()%100000000<<"\n";
    return 0;
}
