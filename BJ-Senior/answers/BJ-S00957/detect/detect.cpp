#include <iostream>
using namespace std;

int T;
int n,m,L,V;
int d[100010],v[100010],a[100010];
int p[100010];
int ans;

int main()
{
    freopen("duel.in","r",stdin);
    cin >> T;
    cin >> n >> m >> L >> V;
    for(int i = 1; i <= n; i++)
    {
        cin >> d >> v >> a;
    }
    for(int i = 1; i <= m; i++)
    {
        cin >> p[i];
    }
    for(int i = 1; i <= n; i++)
    {
        if(v[i] > L) ans += 1;
    }
    freopen("duel.out","w",stdout);
    cout << ans << " " << 1;
    return 0;
}
