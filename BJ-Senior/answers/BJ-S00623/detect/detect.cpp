#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e5;
struct Node{
    int l,r,mx,lt,pos;
} tree[N * 4 + 5];
int a[N + 5],v[N + 5],d[N + 5],p[N + 5];
pair<int,int> car[N + 5];
bool vis[N + 5];
int n,m,l,vv,len;

int read()
{
    int x = 0,f = 1;
    char ch = getchar();
    while(ch < '0' || '9' < ch)
    {
        if(ch == '-')
        {
            f = -1;
        }
        ch = getchar();
    }
    while('0' <= ch && ch <= '9')
    {
        x = (x << 3) + (x << 1) + (ch - 48);
        ch = getchar();
    }
    return x * f;
}
void build(int p,int l,int r)
{
    //cout << p << ' ' << l << ' ' << r << endl;
    tree[p].l = l,tree[p].r = r;
    tree[p].pos = l;
    if(l == r) return;
    int mid = (l + r) >> 1;
    build(p * 2,l,mid);
    build(p * 2 + 1,mid + 1,r);
}
void add(int p,int l,int r,int k)
{
    //cout << l << ' ' << r << ' ' << p << ' ' << tree[p].l << ' ' << tree[p].r << endl;
    if(tree[p].l == tree[p].r)
    {
        tree[p].mx += k;
        return ;
    }
    int mid = (tree[p].l + tree[p].r) >> 1;
    //cout << mid << endl;
    if(l <= mid) add(p * 2,l,r,k);
    if(mid + 1 <= r) add(p * 2 + 1,l,r,k);
    if(tree[p * 2].mx <= tree[p * 2 + 1].mx)
    {
        tree[p].mx = tree[p * 2 + 1].mx;
        tree[p].pos = tree[p * 2 + 1].pos;
    }
    else
    {
        tree[p].mx = tree[p * 2].mx;
        tree[p].pos = tree[p * 2].pos;
    }
}

signed main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = read();
    while(t--)
    {
        len = 0;
        memset(tree,0,sizeof(tree));
        n = read();
        m = read();
        l = read();
        vv = read();
        for(int i = 1;i <= n;i++)
        {
            d[i] = read();
            v[i] = read();
            a[i] = read();
        }
        for(int i = 1;i <= m;i++)
        {
            p[i] = read();
        }
        sort(p + 1,p + 1 + m);
        for(int i = 1;i <= n;i++)
        {
            if(a[i] == 0)
            {
                if(p[m] >= d[i] && v[i] > vv)
                {
                    int l = 0,r = m,ans = 0;
                    while(l <= r)
                    {
                        int mid = (l + r) >> 1;
                        if(p[mid] >= d[i])
                        {
                            r = mid - 1;
                            ans = mid;
                        }
                        else
                        {
                            l = mid + 1;
                        }
                    }
                    car[++len] = {ans,m};
                }
            }
            else if(a[i] > 0)
            {
                int t = (vv * vv - v[i] * v[i]) / (2 * a[i]) + 1;
                if(t <= p[m] - d[i] + 1)
                {
                    int l = 0,r = m,ans = 0;
                    while(l <= r)
                    {
                        int mid = (l + r) >> 1;
                        if(p[mid] - d[i] >= t)
                        {
                            r = mid - 1;
                            ans = mid;
                        }
                        else
                        {
                            l = mid + 1;
                        }
                    }
                    car[++len] = {ans,m};
                }
            }
            else
            {
                int t = (vv * vv - v[i] * v[i]) % (2 * a[i]) ? (vv * vv - v[i] * v[i]) / (2 * a[i]) : (vv * vv - v[i] * v[i]) / (2 * a[i]) - 1;
                if(p[m] < d[i]) continue;
                int l = 0,r = m,ans = m;
                while(l <= r)
                {
                    int mid = (l + r) >> 1;
                    if(p[mid] >= d[i])
                    {
                        r = mid - 1;
                        ans = mid;
                    }
                    else
                    {
                        l = mid + 1;
                    }
                }
                if(t >= 0 && p[ans] - d[i] <= t)
                {
                    int temp = ans;
                    l = ans,r = m,ans = m;
                    while(l <= r)
                    {
                        int mid = (l + r) >> 1;
                        if(p[mid] - d[i] <= t)
                        {
                            l = mid + 1;
                            ans = mid;
                        }
                        else
                        {
                            r = mid - 1;
                        }
                    }
                    car[++len] = {temp,ans};
                }
            }
        }
        cout << len << endl;
        build(1,1,n);
        for(int i = 1;i <= len;i++)
        {
            //cout << car[i].first << ' ' << car[i].second << endl;
            add(1,car[i].first,car[i].second,1);
        }
        memset(vis,0,sizeof(vis));
        int sum = 0,cnt = 0;
        while(sum < len)
        {
            if(sum <= -100) break;
            //cout << tree[1].mx << ' ' << tree[1].pos << ' ';
            pair<int,int> temp = {tree[1].mx,tree[1].pos};
            sum += temp.first;
            //cout << sum << endl;
            cnt++;
            for(int i = 1;i <= len;i++)
            {
                if(!vis[i] && car[i].first <= temp.second && temp.second <= car[i].second)
                {
                    vis[i] = 1;
                    add(1,car[i].first,car[i].second,-1);
                }
            }
        }
        cout << m - cnt << endl;
    }
    return 0;
}
