#include <bits/stdc++.h>
using namespace std;
#define int long long
struct car{int v,a,d;} a[100005];
int t,n,m,l,v,c[100005],cnt;
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int i,j,k,x;
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>l>>v;
        for (cnt=0,i=1;i<=n;i++)
        {
            cin>>a[i].d>>a[i].v>>a[i].a;
            if (a[i].v>v)
                cnt++;
        }
        for (i=1;i<=n;i++)
            cin>>c[i];
        cout<<cnt<<endl;
    }

    return 0;
}
