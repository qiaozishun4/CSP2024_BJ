#include<bits/stdc++.h>
using namespace std;
int t;
int n, k, q;
int l[1005];
int s[1005][1005];
int r[1005];
int c[1005];
vector<int> vec[200005][1005];
int main()
{
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    cin >> t;
    while(t--)
    {
        cin >> n >> k >> q;
        for(int i = 1;i <= n;i++)
        {
            cin >> l[i];
            for(int j = 1;j <= l[i];j++)
            {
                cin >> s[i][j];
                vec[s[i][j]][i].push_back(j);
            }
        }
        for(int i = 1;i <= q;i++)
        {
            cin >> r[i] >> c[i];
            bool x = 0;
            for(int j = 1;j <= n;j++)
            {
                if(x) break;
                for(int l : vec[1][j])
                {
                    if(x) break;
                    for(int m : vec[c[i]][j])
                    {
                        if(m-l+1<=k&&m-l+1>=2)
                        {
                            x=1;
                            break;
                        }
                    }
                }
            }
            if(x) cout << "1\n";
            else cout << "0\n";
        }

    }
    return 0;
}
