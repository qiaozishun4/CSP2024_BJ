#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
int T;
ll n, m, l, V, d[100010], v[100010], a[100010], p[100010], ch[100010], bf[100010], cou[100010], becou[100010], ans1;//bf:bool
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin >> T;
    for (int q=1; q<=T; ++q)
    {
        cin >> n >> m >> l >> V;
        for (int i=1; i<=n; ++i)
        {
            cin >> d[i] >> v[i] >> a[i];
        }
        for (int i=1; i<=m; ++i)
        {
            cin >> p[i];
        }
        for (int i=1; i<=n; ++i)
        {
            if(a[i]>0)
            {
                if(v[i]>=V)
                {
                    ch[i]=d[i];
                    bf[i]=1;
                }
                else
                {
                    ch[i]=d[i]+(V-v[i])/a[i]*v[i]+0.5*a[i]*(V-v[i])/a[i]*(V-v[i])/a[i];
                    bf[i]=1;
                }
            }
            else if(a[i]==0)
            {
                if(v[i]>V)
                {
                    ch[i]=d[i];
                    bf[i]=1;
                }
                else
                {
                    ch[i]=-1;
                }
            }
            else
            {
                if(v[i]<=V)
                {
                    ch[i]=-1;
                }
                else
                {
                    ch[i]=d[i]+(V-v[i])/a[i]*v[i]+0.5*a[i]*(V-v[i])/a[i]*(V-v[i])/a[i];
                    bf[i]=-1;
                }
            }
        }
        for (int i=1; i<=m; ++i)
        {
            for (int j=1; j<=n; ++j)
            {
                if(p[i]>ch[j]&&bf[j]==1)
                {
                    cou[i]++;
                    if(!becou[j])
                    {
                        ++ans1;
                    }
                    becou[j]=1;
                }
                if(p[i]<ch[j]&&bf[j]==-1)
                {
                    cou[i]++;
                    if(!becou[j])
                    {
                        ++ans1;
                    }
                    becou[j]=1;
                }
            }
        }
        /*for (int j=1; j<=n; ++j)
        {
            cout << ch[j] << " ";
        }*/
        cout << ans1-1 << " " << ans1-1;
    }
    return 0;
}
