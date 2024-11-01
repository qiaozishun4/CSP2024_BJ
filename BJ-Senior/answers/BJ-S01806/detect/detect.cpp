#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

struct Car{
    long long d,v,a;
}car[100005];

long long p[100005];

struct Line{
    long long l,r;
}line[100005];

bool cmp(Line a,Line b)
{
    if(a.l == b.l)return a.r < b.r;
    return a.l < b.l;
}

int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;
    cin >> T;
    while(T--)
    {
        long long n,m,L,V;
        cin >> n >> m >> L >> V;
        for(int i = 1;i <= n;i++)
        {
            cin >> car[i].d >> car[i].v >> car[i].a;
        }
        for(int i = 1;i <= m;i++)
        {
            cin >> p[i];
        }
        int cnt = 0,id = 0;
        for(int i = 1;i <= n;i++)
        {
            bool flag = false;
            bool last_flag = false;
            for(int j = 1;j <= m;j++)
            {
                long long s = p[j] - car[i].d;
                long long a = car[i].a,v0 = car[i].v;
                if(s < 0) continue;
                long long v = v0 * v0 + 2 * a * s;
                if(v > V * V)
                {
                    if(!flag)cnt++;
                    flag = true;
                    if(last_flag == false)
                    {
                        line[++id].l = j;
                    }
                    last_flag = true;
                }
                else
                {
                    if(last_flag == true)
                    {
                        line[id].r = j - 1;
                    }
                    last_flag = false;
                }
            }
            if(last_flag == true)
            {
                line[id].r = m;
            }
            last_flag = false;
        }
        cout << cnt << " ";
        sort(line + 1,line + cnt + 1,cmp);

        int ans = 1;
        if(cnt == 0)
        {
            ans = 0;
        }
        for(int i = 1;i <= cnt;i++)
        {
            long long ml = line[i].l,mr = line[i].r;
            for(int j = i + 1;j <= cnt;j++)
            {
                if(line[j].l >= ml && line[j].l <= mr)
                {
                    ml = max(ml,line[j].l);
                    mr = min(mr,line[j].r);
                }
                else
                {
                    ans++;
                    i = j - 1;
                    break;
                }
            }
        }
        cout << m - ans << endl;
    }
    return 0;
}

