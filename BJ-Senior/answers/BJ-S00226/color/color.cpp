#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const int NR = 1e6 + 10;
int A[NR], B[NR];
int n;
ll dp[2][NR];
bool has[NR];

struct Node
{
    ll v, st, ed;
    Node(){
        v = st = ed =0;
    }
    Node(ll v_, ll st_, ll ed_){
        v = v_;
        st = st_;
        ed = ed_;
    }
};
struct ST{
    ll v[NR << 2], tag[NR << 2];
    bool has[NR << 2];
    void build(int x, int s, int t)
    {
        tag[x] = 0;
        has[x] = false;
        if (s == t)
        {
            v[x] = 0;
            return ;
        }
        int mid = (s +t) >> 1;
        build(x << 1, s, mid);
        build(x <<1 |1, mid+1, t);
        pushup(x);
    }
    void pushup(int x)
    {
        v[x] = max(v[x<<1], v[x<<1|1]);
        has[x] = has[x<<1] | has[x<<1|1];
    }
    void pushdown(int x)
    {
        if (tag[x] > 0)
        {
            v[x<<1] += tag[x];
            tag[x<<1] += tag[x];

            v[x<<1|1] += tag[x];
            tag[x<<1|1] += tag[x];

            tag[x] = 0;
        }
    }
    ll query(int x, int l, int r, int s ,int t)
    {
        if (l <= s && r >= t)
        {
            return v[x];
        }
        pushdown(x);
        int mid = (s + t) >> 1;
        ll ans = 0;
        if (l <= mid)
        {
            ans = query(x<<1, l, r, s, mid);
        }
        if (r > mid)
        {
            ans = max(ans, query(x<<1|1, l, r, mid+1, t));

        }
        return ans;
    }
    void add(int x, int l, int r, ll val, int s, int t)
    {
        if (l <= s && r >= t)
        {
            tag[x] += val;
            v[x] += val;
            return;
        }
        pushdown(x);
        int mid = (s + t) >>1;
        if (l <= mid) add(x<<1, l, r, val, s, mid);
        if (r > mid) add(x<<1|1, l, r, val, mid+1, t);
        pushup(x);
    }

    void pushdown2(int x)
    {
        if (has[x])
        {
            if (has[x<<1])
            {
                v[x<<1] += tag[x];
                tag[x<<1] += tag[x];
            }

            if (has[x<<1|1])
            {
                v[x<<1|1] += tag[x];
                tag[x<<1|1] += tag[x];
            }
            tag[x] = 0;
        }
    }
    void add2(int x, int l, int r, ll val, int s, int t)
    {
        if (l <= s && r >= t)
        {
            if (has[x])
            {
                tag[x] += val;
                v[x] += val;
            }
            return;
        }
        pushdown2(x);
        int mid = (s + t) >>1;
        if (l <= mid) add2(x<<1, l, r, val, s, mid);
        if (r > mid) add2(x<<1|1, l, r, val, mid+1, t);
        pushup(x);
    }
    void sethas(int x, int l, int s, int t)
    {
        if (s == t)
        {
            has[x] = true;
            return;
        }
        pushdown2(x);
        int mid = (s + t) >>1;
        if (l <= mid) sethas(x<<1,l,s,mid);
        else sethas(x<<1|1,l,mid+1,t);
        pushup(x);
    }
}st1, st2;

void solve1()
{
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j < i - 1; j++)
        {
            dp[1][i-1] = max(dp[1][i-1], dp[0][j] + (A[i] == A[j] ? A[i]: 0));
            dp[1][j] = max(dp[1][j], dp[0][j] + (A[i] == A[i-1]?A[i]:0));
        }
        for (int j = 0; j < i; j++)
        {
            dp[0][j] = dp[1][j];
            dp[1][j] = 0;
        }
    }
    ll ans = 0;
    for (int j = 0; j < n; j++)
        ans = max(ans, dp[0][j]);
    cout << ans << endl;
}

void solve2()
{
    memset(B, 0, sizeof(B));
    memset(has, 0, sizeof(has));
    int N = 0;
    for (int i = 1; i <= n; i++)
        N = max(N, A[i]);

    has[0] = true;
    st1.build(1, 0, n);
    st2.build(1, 0, N);
    for (int i = 2; i <= n; i++)
    {
        ll tmp = st2.query(1, 0, N, 0, N);
        if (has[A[i]])
        {
            ll old = st2.query(1, A[i], A[i], 0, N);
            tmp = max(tmp, old + A[i]);
        }
        if (A[i] == A[i-1])
        {
            st1.add(1, 0, i-2, A[i], 0, n);
            st2.add2(1, 0, N, A[i], 0, N);
        }
        st1.add(1,i-1,i-1,tmp,0,n);
        ll nval = st2.query(1, A[i-1], A[i-1], 0, N);
        has[A[i-1]] = true;
        st2.sethas(1,A[i-1],0,N);
        if (tmp > nval)
        {
            st2.add(1, A[i-1], A[i-1], tmp - nval, 0, N);
        }
    }
    cout << st1.query(1,0,n-1,0,n) << endl;
}

int main()
{
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> A[i];
        if (n <= 3000)
        {
            solve1();
        } else
        {
            solve2();
        }
    }

    return 0;
}


