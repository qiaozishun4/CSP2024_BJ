#include <bits/stdc++.h>
using namespace std;
struct www
{
    int d,v,a,z;
};

int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);

    int t,b[100001];
    cin >> t;
    while (t > 0)
    {
        t--;
        www a[100001] = {};
        int n,m,l,v,sc = 0,sg = 0;
        cin >> n >> m >> l >> v;
        for (int i = 1;i <= n;i++)
        {
            cin >> a[i].d >> a[i].v >> a[i].a;
            a[i].z = 0;
        }
        for (int i = 1;i <= m;i++)
        {
            cin >> b[i];
            for (int j = 1;j <= n;j++)
            {
                if (a[j].d <= b[i])
                {
                    if (a[j].v > v && a[j].z == 0)
                    {
                        sc++;
                        a[j].z = 1;
                    }
                }
            }
        }
        cout << sc << ' ' << 1 << endl;
    }


    return 0;
}


