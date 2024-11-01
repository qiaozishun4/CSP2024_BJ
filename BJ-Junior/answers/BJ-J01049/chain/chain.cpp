#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5+5;
int n,k,q;
vector<int> a[MAXN];
int r,c;
bool f;

void dfs(int p,int last,int lasti)
{
   // cout << p << " " << last << " " << lasti << endl;
    if(f) return;
    if(p > r)
    {
        if(last == c) f = 1;
        return;
    }
    for(int i = 1;i <= n;i++)
    {
        if(i == lasti) continue;
        for(int j = 0;j < a[i].size();j++)
        {
            if(a[i][j] != last) continue;
            if(f) return;
            for(int l = j+1;l-j < k && l < a[i].size();l++)
            {
                //cout << i << " " << j << " " << l << endl;
                dfs(p+1,a[i][l],i);
            }
        }
    }
}

int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> k >> q;
        for(int i = 1;i <= n;i++)
        {
            int n1;
            cin >> n1;
            for(int j = 1;j <= n1;j++)
            {
                int x;
                cin >> x;
                a[i].push_back(x);
            }
        }
        while(q--)
        {
            f = 0;
            cin >> r >> c;
            dfs(1,1,0);
            cout << f << endl;
            /*int last = 1,lasti = 0;;
            for(int x = 1;x <= r;x++)
            {
                for(int i = 1;i <= n;i++)
                {
                    if(i == lasti) continue;
                    for(int j = 0;j < a[i].size();j++)
                    {
                        for(int l = j;l < a[i].size() && l-i <= k;l++)
                        {

                        }
                    }
                }
            }*/
        }
    }
    return 0;
}
