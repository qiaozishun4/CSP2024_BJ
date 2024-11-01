#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n,l,V,d[N],v[N],a[N],p[N],m;
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","r",stdout);
    cin >> T;
    while(T--)
    {
        cin >> n >> m >> l >> V;
        for(int i=1;i<=n;i++)cin >> d[i] >> v[i] >> a[i];
        for(int i=1;i<=m;i++)cin >> p[i];
        int sum=0;
        int qr=-1e9,dl=1e9;
        for(int i=1;i<=n;i++)dl=min(dl,d[i]);
        for(int i=1;i<=m;i++)qr=max(qr,p[i]);
        for(int i=1;i<=n;i++)if(v[i]>V&&d[i]<qr)sum++;
        cout << sum << " ";
        if(dl<qr)cout << m-1;
        else cout << m;
    }
    return 0;
}
