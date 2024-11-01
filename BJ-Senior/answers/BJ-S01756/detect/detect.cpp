#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e5+10;
const int M = 1e6+10;
int T;
int n, m, l, V, cur;
int ans1, ans2;
int p[N], k[N];

struct node
{
    int st, ed;
}b[N];

bool cmp(node x, node y)
{
    if(x.st!=y.st) return x.st < y.st;
    return x.ed < y.ed;
}

signed main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    cin >> T;
    while(T--)
    {
        cin >> n >> m >> l >> V;
        memset(b, 0, sizeof(b));
        cur = 0;
        ans1 = ans2 = 0;
        bool flag1 = 1;
        for(int i = 1; i <= n; i ++)
        {
            int d, v, a;
            cin >> d >> v >> a;
            if(a == 0)
            {
                if(v > V) b[++cur].st = d, b[cur].ed = l;
            }
            else if(a > 0)
            {
                if(v > V) b[++cur].st = d, b[cur].ed = l;
                else
                {
                    int tmp = (V*V-v*v);
                    if(tmp % (2*a) == 0) tmp = tmp / (2*a) + 1;
                    else tmp = tmp / (2*a)+1;
                    if(d+tmp > l) continue;
                    b[++cur].st = d+tmp, b[cur].ed = l;
                }
            }
            else
            {
                flag1 = 0;
                if(v<=V) continue;
                int tmp = (V*V-v*v);
                if(tmp % (2*a) == 0) tmp = tmp / (2*a) - 1;
                else tmp = tmp / (2*a);
                b[++cur].st = d, b[cur].ed = min(l, d+tmp);
            }
        }
        for(int i = 1; i <= m; i ++)
        {
            cin >> p[i];
        }
        //for(int i = 1; i <= cur; i ++) cout << b[i].st << ' ' << b[i].ed << '\n';
        for(int i = 1; i <= cur; i ++)
        {
            int pos = lower_bound(p+1, p+m+1, b[i].st)-p;
            if(pos == m+1) b[i].st = b[i].ed = 0;
            else if(p[pos] > b[i].ed) b[i].st = b[i].ed = 0;
            else ++ans1;
        }
        //for(int i = 1; i <= cur; i ++) cout << b[i].st << ' ' << b[i].ed << '\n';
        cout << ans1 << ' ';
        if(flag1)
        {
            ans2 = ans1;
            sort(b+1, b+cur+1, cmp);
            for(int i = 1; i < cur; i ++)
            {
                int j = i+1;
                while(b[j].st == 0&&j<=cur) ++j;
                if(b[i].ed >= b[j].ed) b[i].st = b[i].ed = 0, ans2--;
            }
            cout << m-ans2 << '\n';
        }
        else
        {
            ans2 = 0;
            for(int i = 1; i <= cur; i ++)
            {
                if(b[i].st == 0) continue;
                int j = i+1;
                while(b[j].st==0&&j<=cur) j++;
                if(b[i].ed >= b[i+1].st)
                {
                    int pos = lower_bound(p+1, p+m+1, b[j].st)-p;
                    bool flag = (pos!=m+1)&&(pos <= b[i].ed);
                    if(flag)
                    {
                        ans2++;
                        b[i].st=b[i].ed=b[j].st=b[j].ed = 0;
                    }
                    else
                    {
                        ans2++;
                        b[j].st=b[j].ed=0;
                    }
                }
                else ans2++;
            }
            cout << m-ans2 << '\n';
        }
    }
    return 0;
}
