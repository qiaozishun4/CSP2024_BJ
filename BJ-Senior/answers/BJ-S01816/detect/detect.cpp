#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int read()
{
    char ch = getchar_unlocked();
    int f = 1;
    while(!('0' <= ch && ch <= '9'))
    {
        if(ch == '-') f = -1;
        ch = getchar_unlocked();
    }
    int x = 0;
    while ('0' <= ch && ch <= '9')
    {
        x = (x << 1) + (x << 3) + (ch ^ 48);
        ch = getchar_unlocked();
    }
    return x * f;
}
void write(int x)
{
    if (x >= 10)
    {
        write(x / 10);
        putchar(x % 10 + 48);
    }
    else putchar(x + 48);
}
struct car
{
    int d,v,a;
    void read()
    {
        d = ::read();
        v = ::read();
        a = ::read();
    }
}a[100005];
int p[100005];
struct seg{
    int b,e;//[b,e)
};
vector<seg>vec;
bool cmp(seg x,seg y)
{
    return x.b < y.b;
}
void solve()
{
    vec.clear();
    memset(a,0,sizeof a);
    memset(p,0,sizeof p);
    int n = read(),m = read(),l = read(),v = read();
    for (int i = 1;i <= n;i++) a[i].read();
    for (int i = 1;i <= m;i++) p[i] = read();
    int cnt = 0;
    for (int i = 1;i <= n;i++)
    {
        if (a[i].a)
        {
            if (a[i].v > v && a[i].a > 0)
            {
                int pos = lower_bound(p + 1,p + m + 1,a[i].d) - p;
                if (pos > m) continue;
                vec.push_back({a[i].d,l});
                cnt++;
            }
            else if (a[i].v <= v && a[i].a < 0) continue;
            else if (a[i].a > 0)
            {
                int e = (v * v - a[i].v * a[i].v) / (2 * a[i].a);
                if (a[i].d + e > l) continue;
                int pos = lower_bound(p + 1,p + m + 1,a[i].d + e + 1) - p;
                if (pos > m) continue;
                vec.push_back({a[i].d + e + 1,l});
                cnt++;
            }
            else
            {
                int e = (v * v - a[i].v * a[i].v + 2 * a[i].a - 1) / (2 * a[i].a);
                if (a[i].d + e - 1 > l) e = l - a[i].d + 1;
                int pos = lower_bound(p + 1,p + m + 1,a[i].d) - p;
                if (pos > m || p[pos] > a[i].d + e - 1) continue;
                vec.push_back({a[i].d,a[i].d + e - 1});
                cnt++;
            }
        }
        else
        {
            if (a[i].v > v)
            {
                int pos = lower_bound(p + 1,p + m + 1,a[i].d) - p;
                if (pos > m) continue;
                vec.push_back({a[i].d,l});
                cnt++;
            }
        }
    }
    write(cnt);
    printf(" ");
    sort(vec.begin(),vec.end(),cmp);
    vec.push_back({-1000000000,-1000000000});
    int last = 1;
    int cnt2 = 0;
    for (int i = 1;i <= m;i++)
    {
        bool flag = true;
        while (vec[last].b <= p[i] && p[i] <= vec[last].e)
        {
            last++;
            flag = false;
        }
        cnt2 += flag;
    }
    write(cnt2);
    printf("\n");
}
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t = read();
    while(t--) solve();
    return 0;
}
