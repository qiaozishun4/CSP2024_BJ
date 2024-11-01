#include <bits/stdc++.h>

using namespace std;
const int MAXN = 200002;

struct Edge
{
    int v,w;
    bool operator< (const Edge &t) const
    {
        if(w != t.w)
            return w < t.w;
        return v < t.v;
    }
};

int t,n,k,q;
int len[MAXN];
vector <int> a[MAXN];

bool ans;
void Init()
{
    ans = false;
    for(int i = 1;i <= n;i++)
        a[i].clear();
    memset(len,0,sizeof(len));

    int cnt = 0;
    cin >> n >> k >> q;
    for(int i = 1;i <= n;i++)
    {
        cin >> len[i];
        a[i].push_back(0);
        for(int j = 1;j <= len[i];j++)
        {
            int x;
            cin >> x;
            cnt++;
            a[i].push_back(x);
        }
    }
}

void Dfs(int step,int id1,int id2,int maxstep,int endd)
{
    if(ans)
        return;
    if(step == maxstep)
    {
        for(int i = id2 + 1;i <= id2 + k - 1 && !ans;i++)
            if(a[id1][i] == endd)
                ans = true;
        return;
    }
    
    for(int i = id2 + 1;i <= len[id1] && !ans && i <= id2 + k - 1;i++)
    {
        for(int j = 1;j <= n && !ans;j++)
        {
            if(j == id1)
                continue;
            for(int kk = 1;kk <= len[j] && !ans;kk++)
            {
                if(a[j][kk] != a[id1][i])
                    continue;
                
                //cout << step + 1 << " " << i << " " << j << " (" << id1 << "," << id2 << ") -> (" << j << "," << kk << ") " << a[j][kk] << endl;
                Dfs(step + 1,j,kk,maxstep,endd);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);

    cin >> t;
    while(t--)
    {
        Init();
        /*
        cout << "-----\n";
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= len[i];j++)
                cout << a[i][j] << " ";
            cout << endl;
        }
        cout << endl;
        */

        while(q--)
        {
            ans = false;
            int r,c;
            cin >> r >> c;

            for(int i = 1;i <= n && !ans;i++)
            {
                for(int j = 1;j <= len[i] && !ans;j++)
                {
                    if(a[i][j] == 1)
                    {
                        Dfs(1,i,j,r,c);
                    }
                }
            }

            if(ans)
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        }
    }

    return 0;
}
