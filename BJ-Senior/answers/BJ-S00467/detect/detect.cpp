#include <bits/stdc++.h>
using namespace std;
struct node{
    int l,r;
}s[100005];
int p[100005],d[100005],v[100005],a[100005];
int cnt;
bool cmp(node a,node b)
{
    if(a.r == b.r) return a.l < b.l;
    return a.r < b.r;
}
int ef(int l,int r,int key)
{
    while(l < r)
    {
        int mid = (l + r + 1) / 2;
        if(p[mid] <= key) l = mid;
        else r = mid - 1;
    }
    return l;
}
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;
    cin >> T;
    while(T--)
    {
        cnt = 0;
        int n,m,L,V;
        cin >> n >> m >> L >> V;
        for(int i = 1;i <= n;i++)
        {
            cin >> d[i] >> v[i] >> a[i];
        }

        for(int i = 1;i <= m;i++)
        {
            cin >> p[i];
        }
        for(int i = 1;i <= n;i++)
        {
            long long tmp1 = (V * V - v[i] * v[i]);
            long long tmp2 = 2 * a[i];
            if(a[i] > 0)
            {
                long long tmp;
                if(tmp1 % tmp2 == 0) tmp = tmp1 / tmp2;
                else tmp = tmp1 / tmp2 + 1;
                if(tmp + d[i] >= L) continue;
                if(p[ef(1,m,L)] <= d[i] + tmp) continue;
                cnt++;
                s[cnt].l = d[i] + tmp;
                s[cnt].r = L;
            }
            else if(a[i] < 0)
            {
                if(v[i] <= V) continue;
                long long tmp;
                if(tmp1 % tmp2 == 0) tmp = tmp1 / tmp2 - 1;
                else tmp = tmp1 / tmp2;
                if(p[ef(1,m,d[i] + tmp)] >= d[i])
                {
                    cnt++,s[cnt].l = d[i],s[cnt].r = d[i] + tmp;
                }
            }
            else{
                if(v[i] > V)
                {
                    if(p[m] < d[i]) continue;
                    cnt++;
                    s[cnt].l = d[i];
                    s[cnt].r = L;
                }
            }
        }
        sort(s + 1,s + cnt + 1,cmp);
        int nex = 0,sxtsum = 0;
        for(int i = 1;i <= cnt;i++)
        {
            if(p[nex] >= s[i].l && p[nex] <= s[i].r) continue;
            sxtsum++;
            while(p[nex] <= s[i].r && nex <= m) nex++;
            nex--;
        }
        cout << cnt << " " << m - sxtsum << endl;
    }
    return 0;
}
