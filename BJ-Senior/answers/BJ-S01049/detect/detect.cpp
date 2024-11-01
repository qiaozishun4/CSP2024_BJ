#include<bits/stdc++.h>
using namespace std;
double t,n,m,len,lim,d[100005],v[100005],a[100005],s[100005],e[100005];
long long p[100005];
bool visc[100005],visp[100005];
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t;
    for(int i = 1;i <= t;i++)
    {
        cin>>n>>m>>len>>lim;
        bool f = true;
        for(int j = 1;j <= n;j++)
        {
            cin>>d[j]>>v[j]>>a[j];
            double son = lim * lim - (v[j] * v[j]);
            double mother = a[j] * 2.00;
            if(a[j] == 0)
            {
                if(v[j] > lim)
                {
                    s[j] = d[j];
                    e[j] = len;
                }
                else s[j] = e[j] = -1;
                continue;
            }
            if(son / mother < 0)
            {
                s[j] = -1;
                e[j] = -1;
                continue;
            }
            if(a[j] > 0)
            {
                s[j] = d[j] + son / mother;
                e[j] = len;
            }
            if(a[j] < 0)
            {
                s[j] = d[j];
                e[j] = d[j] + son / mother;
            }
        }
        long long cnt = 0,ans = m;
        for(int j = 1;j <= m;j++)
        {
            cin>>p[j];
            for(int k = 1;k <= n;k++)
            {
                if(s[k] < p[j] && e[k] > p[j] || (s[k] == p[j] && a[k] <=  0) || (e[k] == p[j] && a[k] >= 0))
                {
                    if(!visc[k]) cnt++;
                    if(!visp[k]) ans--;
                    visc[k] = true;
                    visp[j] = true;
                }
            }
        }
        cout<<cnt<<" "<<ans<<endl;

    }
    return 0;
}
