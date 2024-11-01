#include <bits/stdc++.h>
using namespace std;

const int NR = 1e5 + 10, MR = 1e6 + 10, NLIM = 1e5, MLIM = 1e6;
int n, m, L, V, T, d[NR], v[NR], a[NR], st[21][MR], p[NR], logg[MR], anscnt, lst[NR], finans;
bool flag[NR], vis[NR];
priority_queue <pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pqpst;
priority_queue <pair<int, int> > pqpre;

struct Edge
{
    int l, r, id;
    Edge(){}
    Edge(int tl, int tr, int tid)
    {
        l = tl, r = tr, id = tid;
    }
    bool operator <(const Edge &p) const
    {
        if(l != p.l)
        {
            return l < p.l;
        }
        if(r != p.r) return r < p.r;
        return id < p.id;
    }
} q[NR];

int query(int l, int r)
{
    //int len = r - l + 1;
    if(r < l) return 0;
    return max(st[logg[r - l + 1]][l], st[logg[r - l + 1]][r - (1 << logg[r - l + 1]) + 1]);
}

int gcd(int a, int b)
{
    if(b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

void getanscnt()
{
    anscnt = 0;
    for(int i = 1; i <= n; i++)
    {
        if(a[i] == 0)
        {
            if(v[i] > V)
            {
                if(query(d[i], L))
                {
                    anscnt++;
                    q[anscnt] = Edge(d[i], L, i);
                    lst[anscnt] = -p[lower_bound(p + 1, p + m + 1, -L) - p];
                }
                else
                {
                    flag[i] = 1;
                }
            }
            else
            {
                flag[i] = 1;
            }
        }
        else if(a[i] < 0)
        {
            if(v[i] <= V)
            {
                flag[i] = 1;
            }
            else
            {
                if(gcd(v[i] * v[i] - V * V, -2 * a[i]) == -2 * a[i])
                {
                    int r = d[i] + (V * V - v[i] * v[i]) / (2 * a[i]) - 1;
                    r = min(L, r);
                    if(query(d[i], r))
                    {
                        anscnt++;
                        q[anscnt] = Edge(d[i], r, i);
                        lst[anscnt] = -p[lower_bound(p + 1, p + m + 1, -r) - p];
                    }
                    else
                    {
                        flag[i] = 1;
                    }
                }
                else
                {
                    int r = d[i] + (V * V - v[i] * v[i]) / (2 * a[i]);
                    r = min(L, r);
                    if(query(d[i], r))
                    {
                        anscnt++;
                        q[anscnt] = Edge(d[i], r, i);
                        lst[anscnt] = -p[lower_bound(p + 1, p + m + 1, -r) - p];
                    }
                    else
                    {
                        flag[i] = 1;
                    }
                }
            }
        }
        else
        {
            if(v[i] > V)
            {
                if(query(d[i], L))
                {
                    anscnt++;
                    q[anscnt] = Edge(d[i], L, i);
                    lst[anscnt] = -p[lower_bound(p + 1, p + m + 1, -L) - p];
                }
                else
                {
                    flag[i] = 1;
                }
            }
            else if(v[i] == V)
            {
                if(query(d[i] + 1, L))
                {
                    anscnt++;
                    q[anscnt] = Edge(d[i] + 1, L, i);
                    lst[anscnt] = -p[lower_bound(p + 1, p + m + 1, -L) - p];
                }
                else
                {
                    flag[i] = 1;
                }
            }
            else //v[i] < V
            {
                int l = d[i] + (V * V - v[i] * v[i]) / (2 * a[i]) + 1;
                if(query(l, L))
                {
                    anscnt++;
                    q[anscnt] = Edge(d[i] + 1, L, i);
                    lst[anscnt] = -p[lower_bound(p + 1, p + m + 1, -L) - p];
                }
                else
                {
                    flag[i] = 1;
                }
            }
        }
    }
}

int main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //double sss = clock();
    for(int i = 1; i <= MLIM; i++)
    {
        logg[i] = logg[i - 1] + ((1 << (logg[i - 1] + 1)) == i);
    }
    cin >> T;
    while(T--)
    {
        //init()!!!!!!!!! REMEMBER TO RESET
        //core
        cin >> n >> m >> L >> V;
        for(int i = 1; i <= n; i++)
        {
            flag[i] = 0;
            cin >> d[i] >> v[i] >> a[i];
        }
        for(int i = 1; i <= L; i++)
        {
            st[0][i] = 0;
        }
        for(int i = 1; i <= m; i++)
        {
            cin >> p[i];
            st[0][p[i]] = 1;
            p[i] = -p[i];
        }
        sort(p + 1, p + m + 1);
        for(int sit = 1; sit <= logg[L]; sit++)
        {
            for(int i = 1; i + (1 << sit) - 1 <= L; i++)
            {
                st[sit][i] = max(st[sit - 1][i], st[sit - 1][i + (1 << (sit - 1))]);
            }
        }

        //getanscnt
        getanscnt();
        sort(q + 1, q + anscnt + 1);
        /*cout << "------\n";
        for(int i = 1; i <= anscnt; i++)
        {
            cout << q[i].l << " " << q[i].r << " " << q[i].id << " " << lst[i] << "\n";
        }
        cout << "=======\n";*/

        cout << anscnt << " ";
        while(!pqpre.empty()) pqpre.pop();
        while(!pqpst.empty()) pqpst.pop();
        for(int i = 1; i <= anscnt; i++) vis[i] = 0;
        finans = 0;
        for(int i = 1; i <= anscnt; i++)
        {
            while(!pqpst.empty() && vis[pqpst.top().second]) pqpst.pop();
            if(pqpst.empty() || query(q[i].l, pqpst.top().first)) //push
            {
                //cout << "tst " << i << "\n";
                pqpst.push(make_pair(q[i].r, i));
                pqpre.push(make_pair(q[i].l, i));
            }
            else //checkout then push
            {
                //checkout
                finans++;
                while(!pqpre.empty() && vis[pqpre.top().second]) pqpre.pop();
                while(!pqpre.empty())
                {
                    vis[pqpre.top().second] = 1;
                    pqpre.pop();
                }
                //push
                pqpst.push(make_pair(q[i].r, i));
                pqpre.push(make_pair(q[i].l, i));
            }
        }
        while(!pqpre.empty() && vis[pqpre.top().second]) pqpre.pop();
        if(!pqpre.empty()) finans++;
        cout << m - finans << "\n";
    }
    //double ttt = clock();
    //cerr << (ttt - sss) / CLOCKS_PER_SEC << "\n";
    return 0;
}