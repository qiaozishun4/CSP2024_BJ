#include <iostream>
#include <cstdio>
using namespace std;

int T;
int n,m,l,v,d[100005],sp[100005],a[100005],p[100005];

int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin >> T;
    while(T--)
    {
        int chk0[1000005];
        for(int i = 0;i <= 1000004;i++)
            chk0[i] = 0;
        cin >> n >> m >> l >> v;
        for(int i = 1;i <= n;i++)
            cin >> d[i] >> sp[i] >> a[i];
        for(int i = 1;i <= m;i++)
            cin >> p[i];

        bool isa0 = 1;
        for(int i = 1;i <= n;i++)
            if(a[i] != 0)
            {
                isa0 = 0;
                break;
            }
        if(isa0)
        {
            int highspeed = 0;
            for(int i = 0;i <= n;i++)
                if(sp[i] > v && d[i] <= p[m]) chk0[d[i]] = 1,highspeed++;

            if(highspeed == 0)
            {
                cout << 0 << " " << m << endl;
                continue;
            }
            else
                cout << highspeed << " " << m - 1 << endl;

        }
    }
    return 0;
}