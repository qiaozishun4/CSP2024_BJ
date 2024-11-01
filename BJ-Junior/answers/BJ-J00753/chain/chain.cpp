#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e6;
vector<int> a[N + 5];
map<int,vector<int>> b[N + 5];
map<int,int> m;
int n,k,q;
int cnt = 0;

bool dfs(int l,int r,int num,int ban)
{
    //cout << l << ' ' << r << ' ' << num << ' ' << ban << endl;
    if(num == 1)
    {
        for(int i = 1;i <= n;i++)
        {
            if(i == ban)  continue;
            //cout << i << "-----";
            for(int j = 0;j < b[i][l].size();j++)
            {
                //cout << b[i][l][j] << ' ';
                if(b[i][r].size() == 0) continue;
                int ll = 0,rr = b[i][r].size() - 1;
                //cout << ll <<  ' ' << rr << endl;
                int ans2 = 0;
                while(ll <= rr)
                {
                    int mid = (ll + rr) >> 1;
                    if(b[i][r][mid] > b[i][l][j])
                    {
                        rr = mid - 1;
                        ans2 = mid;
                    }
                    else
                    {
                        ll = mid + 1;
                    }
                }
                //cout << b[i][r][ans2] << endl;
                int dis = b[i][r][ans2] - b[i][l][j] + 1;
                if(dis <= 1) continue;
                if(dis <= k) return 1;
            }
        }
        //cout << endl;
        return 0;
    }
    for(int t = 1;t <= cnt;t++)
    {
        for(int len = 1;len < num;len++)
        {
            if(dfs(l,t,len,ban) && dfs(t,r,num - len,ban)) return 1;
       }
    }
    return 0;
}

signed main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> k >> q;
        for(int i = 1;i <= n;i++)
        {
            int t;
            cin >> t;
            a[i].push_back(t);
            for(int j = 1;j <= t;j++)
            {
                int temp;
                cin >> temp;
                a[i].push_back(temp);
            }
        }
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= a[i][0];j++)
            {
                if(!m[a[i][j]]) a[i][j] = m[a[i][j]] = ++cnt;
                else a[i][j] = m[a[i][j]];
                b[i][a[i][j]].push_back(j);
            }
        }/*
        for(int i = 1;i <= n;i++)
        {
            cout << i << "-------";
            for(int j = 1;j <= cnt;j++)
            {
                cout << j << ':';
                for(int k = 0;k < b[i][j].size();k++)
                {
                    cout << b[i][j][k] << ' ';
                }
                cout << endl;
            }
            cout << endl;
        }*/
        for(int i = 1;i <= q;i++)
        {
            int r,c;
            cin >> r >> c;
            c = m[c];
            int s = m[1];
            if(!c || !s) cout << 0 << endl;
            cout << dfs(s,c,r,n + 1) << endl;
        }
    }
    return 0;
}
