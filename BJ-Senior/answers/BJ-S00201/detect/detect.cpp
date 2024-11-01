#include <bits/stdc++.h>
using namespace std;

inline int read()
{
    register int x = 0, f = 1;
    register char c = getchar();
    while(c > '9' || c < '0')
    {
        if(c == '-')f = -1;
        c = getchar();
    }
    while(c >= '0' && c <= '9')
    {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * f;
}

//14:50 先解决第一个问题：哪些车超速
//记录每一个车超速的区间，前缀和判断其中有没有测速仪即可。
//15:33解决第二个问题：选择最少的点，使得每一个区间中都有点
//发现按照左端点排序之后，每次若区间中没有点，就选择区间中最靠右的点。
//正确性错了，包含情况会寄
//如果没有包含那没有问题
//那我们尝试干掉包含
//只要让被包含的在包含的前面就好了
//或者说，包含别人的不必选了。
//如何选择最靠右的？在p中二分。
//15:57过了！！！！！！！！！！！！

struct vehicle
{
    int d, v, a, l, r;
    bool chao;
}c[100010];

int p[100010], n ,m, l, v, s[1000010];

int a[1000010];//树桩数组单点加区间查。

inline int lowbit(int x){return (x & (-x));}

void add(int x)
{
    while(x <= l)
    {
        a[x]++;
        x += lowbit(x);
    }
    return;
}

bool haddd[100010];

int query(int x)
{
    int ans = 0;
    while(x)
    {
        ans += a[x];
        x -= lowbit(x);
    }
    return ans;
}

bool cmp(vehicle a, vehicle b)
{
    if(!a.chao || !b.chao)return a.chao > b.chao;
    if(a.l != b.l)return a.l < b.l;
    return a.r < b.r;
}

int getq(int l, int r)
{
    int ans = m, L = 1, R = m;
    while(L <= R)
    {
        int mid = (L + R) / 2;
        if(p[mid] <= r)ans = mid, L = mid + 1;
        else R = mid - 1;
    }
    while(ans < m && p[ans + 1] <= r)ans++;
    haddd[ans] = 1;
    return p[ans];
}

signed main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    int T;
    T = read();
    while(T--)
    {
        memset(c, 0, sizeof(c));
        memset(s, 0, sizeof(s));
        memset(p, 0, sizeof(p));
        memset(a, 0, sizeof(a));
        memset(haddd, 0, sizeof(haddd));
        n = read(), m = read(), l = read(), v = read();
        l++;
        for(int i = 1;i <= n;i++)
        {
            c[i].d = read() + 1, c[i].v = read(), c[i].a = read();
            if(c[i].a > 0)
            {
                if(c[i].v <= v)c[i].l = min((int)(ceil(0.00001 + c[i].d + 1.0 * (-c[i].v * c[i].v + v * v) / c[i].a / 2.0)), l + 1);
                else c[i].l = c[i].d;
                c[i].r = l + 1;
            }
            else if(c[i].a == 0)
            {
                if(c[i].v > v)c[i].l = c[i].d, c[i].r = l + 1;
                else c[i].l = l + 1, c[i].r = l + 1;
            }
            else
            {
                if(c[i].v > v)
                {
                    c[i].l = c[i].d, c[i].r = min(c[i].d + (int)(floor(-0.00001 + 1.0 * ((v * v - c[i].v * c[i].v) / 2.0 / c[i].a))), l + 1);
                }
                else
                {
                    c[i].l = c[i].r = l + 1;
                }
            }
        }
        for(int i = 1;i <= m;i++)
        {
            p[i] = read();
            p[i]++;
        }
        int t = 1;
        for(int i = 1;i <= l + 1;i++)
        {
            s[i] = s[i - 1];
            if(p[t] == i)s[i]++, t++;
        }
        int tot = 0;
        for(int i = 1;i <= n;i++)
        {
            if(s[c[i].r] - s[c[i].l - 1] > 0)c[i].chao = 1, tot++;
            //cout << c[i].d << " " << c[i].v << " " << c[i].a <<  " " << c[i].l << " " << c[i].r << " " << c[i].chao << "\n";
        }
        cout << tot << " ";
        sort(c + 1, c + n + 1, cmp);
        for(int i = tot;i >= 1;i--)
        {
            if(query(c[i].r) - query(c[i].l) != 0)
            {
                c[i].chao = 0;
            }
            else add(c[i].r);
        }
        memset(a, 0, sizeof(a));
        for(int i = 1;i <= tot;i++)
        {
            if(!c[i].chao)continue;
            if(query(c[i].r) == query(c[i].l - 1))
            {
                add(getq(c[i].l, c[i].r));
                //cout << c[i].l << " " << c[i].r << "\n";
            }
        }
        tot = 0;
        for(int i = 1;i <= m;i++)if(haddd[i])tot++;
        cout << m - tot << "\n";
    }
    return 0;
}