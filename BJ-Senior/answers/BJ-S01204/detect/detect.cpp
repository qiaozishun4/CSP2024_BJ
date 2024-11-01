#include<bits/stdc++.h>
using namespace std;
int T;
int n,m,L,V;
int d[100005],v[100005],a[100005],p[100005];
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin >> T;
    while(T)
    {
        cin >> n >> m >> L >> v;
        for(int i = 1; i <= n; i++)
        {
            cin >> d[i] >> v[i] >> a[i];
        }
        for(int i = 1; i <= m; i++)
        {
            cin >> p[1];
        }
        cout << 0 << m;
    }
    return 0;
}