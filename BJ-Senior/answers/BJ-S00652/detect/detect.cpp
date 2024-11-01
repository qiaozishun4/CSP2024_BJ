#include <iostream>
#include <algorithm>
using namespace std;

int d[1000005],a[1000005],v[1000005];
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t;
    cin >> t;
    while (t--)
    {
    	int n,m,l,V;
    	cin >> n >> m >> l >> V;
    	int ans = 0;
        for (int i = 1;i <= n;i++)
        	cin >> d[i] >> a[i] >> v[i];
        int maxn = 0;
        for (int i = 1;i <= m;i++)
        {
        	int p;
        	cin >> p;
            maxn = max(maxn,p);
        }
        for (int i = 1;i <= n;i++)
            if (v[i] > V && d[i] <= maxn) ans++;
        cout << ans << "\n" << m-1 << "\n";
    }
	return 0;
}