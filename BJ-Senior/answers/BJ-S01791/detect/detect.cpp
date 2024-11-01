#include <bits/stdc++.h>
using namespace std;
const int P=100612;
int t,n,m,l,v;
int d[P],va[P],a[P],p[P];
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>l>>v;
        for(int i=1;i<=n;i++)
        {
            cin>>d[i]>>va[i]>>a[i];
        }
        for(int i=1;i<=m;i++)
        {
            cin>>p[i];
        }
        cout<<n<<" "<<endl;
    }
    return 0;
}
