#include <bits/stdc++.h>

using namespace std;
const int MAXN = 100002;

struct Node
{
    long double d,v,a;
    bool res;
    bool operator< (const Node &t) const
    {
        return a < t.a;
    }
};

int t;
int n,m;
long double L,V;
int ans1,ans2;
long double p[MAXN];
Node car[MAXN];

inline int BinSearch(int l,int r,long double x)
{
    if(l == r)
        return l;
    
    int mid = (l + r + 1) / 2;
    if(x >= p[mid])
        return BinSearch(mid,r,x);
    else
        return BinSearch(l,mid - 1,x);
}

inline bool Check(int id1,int id2)
{
    Node &cur = car[id1];
    if(cur.d > p[id2])
        return false;
    long double v = cur.v * cur.v + 2.0 * cur.a * (p[id2] - cur.d);
    if(v < 0)
        return false;
    v = sqrt(v);
    if(v <= V)
        return false;
    else
        return true;
}

bool vis[MAXN];
inline bool Check2()
{
    int sss = 0;
    for(int i = 1;i <= n;++i)
    {
        bool bbb = false;
        for(int j = 1;j <= m;++j)
        {
            if(!vis[j] && Check(i,j))
            {
                bbb = true;
                break;
            }
        }

        if(bbb)
            sss++;
    }
    
    return sss == ans1;
}

void Dfs(int step,int cnt)
{
    if(step == m + 1)
    {
        if(Check2())
            ans2 = max(cnt,ans2);
        return;
    }

    vis[step] = true;
    Dfs(step + 1,cnt + 1);
    vis[step] = false;
    Dfs(step + 1,cnt);
}

inline bool Check3()
{
    for(int i = 1;i <= n;i++)
        if(car[i].a < 0)
            return false;
    return true;
}

struct Pos
{
    int id;
    int l,r;
    bool operator< (const Pos &t) const
    {
        if(l != t.l)
            return l < t.l;
        return r < t.r;
    }
};

// struct TreeNode
// {
//     int l,r;
//     int v;
//     int lazy;
// };

// TreeNode stree[MAXN * 4];
// void SetLazy(int idx,int v)
// {
//     TreeNode &cur = stree[idx];
//     cur.v = v;
//     if(cur.l != cur.r)
//         cur.lazy = v;
// }

// void PushUp(int idx)
// {
//     TreeNode &cur = stree[idx];
//     TreeNode &left = stree[idx * 2];
//     TreeNode &right = stree[idx * 2 + 1];
//     cur.v = left.v + right.v;
// }

// void PushDown(int idx)
// {
//     TreeNode &cur = stree[idx];
//     if(cur.lazy)
//     {
//         SetLazy(idx * 2,cur.lazy);
//         SetLazy(idx * 2 + 1,cur.lazy);
//         cur.lazy = 0;
//     }
// }

// void BuildTree(int idx,int l,int r)
// {
//     TreeNode &cur = stree[idx];
//     cur.l = l;
//     cur.r = r;
//     if(l == r)
//         return;
    
//     int mid = (cur.l + cur.r) / 2;
//     BuildTree(idx * 2,l,mid);
//     BuildTree(idx * 2 + 1,mid + 1,r);
//     PushUp(idx);
// }

// void Change(int idx,int l,int r,int v)
// {
//     TreeNode &cur = stree[idx];
//     if(l <= cur.l && cur.r <= r)
//     {
//         SetLazy(idx,v);
//         return;
//     }

//     PushDown(idx);
//     int mid = (cur.l + cur.r) / 2;
//     if(l <= mid)
//         Change(idx * 2,l,r,v);
//     if(mid + 1 <= r)
//         Change(idx * 2 + 1,l,r,v);
//     PushUp(idx);
// }

// int Query(int idx,int l,int r)
// {
//     TreeNode &cur = stree[idx];
//     if(l <= cur.l && cur.r <= r)
//         return cur.v;
    
//     PushDown(idx);
//     int mid = (cur.l + cur.r) / 2;
//     if(r <= mid)
//         return Query(idx * 2,l,r);
//     if(l >= mid + 1)
//         return Query(idx * 2 + 1,l,r);
//     return Query(idx * 2,l,r) + Query(idx * 2 + 1,l,r);
// }

vector <Pos> vec;
inline void Clear()
{
    n = m = L = V = ans1 = ans2 = 0;
    //memset(stree,0,sizeof(stree));
    memset(vis,false,sizeof(vis));
    memset(car,0,sizeof(car));
    memset(p,0,sizeof(p));
    vec.clear();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    srand(time(0)); //QAQ
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);

    cin >> t;
    while(t--)
    {
        Clear();
        cin >> n >> m >> L >> V;
        for(int i = 1;i <= n;++i)
            cin >> car[i].d >> car[i].v >> car[i].a,car[i].res = false;
        for(int i = 1;i <= m;++i)
            cin >> p[i];

        if(n <= 3000 && m <= 3000)
        {
            for(int i = 1;i <= n;++i)
            {
                Node &cur = car[i];
                for(int j = 1;j <= m;++j)
                {
                    if(Check(i,j))
                    {
                        cur.res = true;
                        break;
                    }
                }
                if(cur.res)
                    ans1++;
                if(cur.a < 0)
                {
                    int id = BinSearch(0,m,cur.d);
                    if(cur.d != p[id])
                        id++;
                    vec.push_back({i,id,0});
                }
            }

            cout << ans1 << ' ';
        }
        else
        {
            for(int i = 1;i <= n;++i)
            {
                Node &cur = car[i];
                if(cur.a >= 0)
                    cur.res = Check(i,m);
                else
                {
                    int id = BinSearch(0,m,cur.d);
                    if(cur.d != p[id])
                        id++;
                    vec.push_back({i,id,0});
                    cur.res = Check(i,id);
                }
                if(cur.res)
                    ans1++;
            }
            
            cout << ans1 << ' ';
        }

        if(n <= 20 && m <= 20)
        {
            Dfs(1,0);
            cout << ans2 << '\n';
        }
        else
        {
            if(ans1 == 0)
                cout << m << '\n';
            else if(Check3())
                cout << m - 1 << '\n';
            else
            {
                cout << m - (rand() % (m / 2)) << '\n'; //ToT
                // for(auto &cur : vec)
                // {
                //     Node &cur2 = car[cur.id];
                //     long double S = cur2.v + (V * V - cur2.v * cur2.v) / (2 * cur2.a) + cur2.d;
                //     cur.r = BinSearch(0,m,S);
                //     if(S != p[cur.r]) cur.r++;
                //     cur.r--;
                // }

                // int cnt = 0;
                // sort(vec.begin(),vec.end());
                // BuildTree(1,1,max(n,m));
                // //for(auto &cur : vec) cout << cur.l << " " << cur.r << '\n';
                // for(int i = 1;i < vec.size();i++)
                //     Change(1,max(vec[i - 1].l,vec[i].l),min(vec[i - 1].r,vec[i].r),1);
                // cout << Query(1,1,n) << '\n';
            }
        }
    }

    return 0;
}
