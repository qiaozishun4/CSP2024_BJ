#include<bits/stdc++.h>

using namespace std;
int T;
int n, k, q;
const int N = 2e5 + 10;
int l[N];
int s[1100][N];
int r[N], c[N];
int nums[N];
bool ch = false;
void dfs(int ci, int u, int sn, int z)
{

    memset(nums, 0, sizeof nums);
    if(ci > r[z]) return ;
    if(ci == r[z] && sn == c[z])
    {
        ch = true;
        return ;
    }
    for(int i = 1; i <= l[u]; i ++ )
    {
        if(s[u][i] == sn)
        {
            for(int j = i + 1; j <= min(i + k - 1, l[u]); j ++ )
            {
                if(nums[s[u][j]] == 0)
                {
                    for(int k = 1; k <= n; k ++ )
                    {
                        if(u != k) dfs(ci + 1, k, s[u][j], z);
                    }
                    nums[s[u][j]] ++ ;
                }
            }
        }
    }
}
int main()
{
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
	cin >> T;
	while(T -- )
    {

        cin >> n >> k >> q;
        for(int i = 1; i <= n; i ++ )
        {
            cin >> l[i];
            for(int j = 1; j <= l[i]; j ++ )
            {
                cin >> s[i][j];
            }
        }
        for(int i = 1; i <= q; i ++ )
        {
            cin >> r[i] >> c[i];
        }
        for(int i = 1; i <= q; i ++ )
        {
            ch = false;
            for(int j = 1; j <= n; j ++ )
            {
                dfs(0, j, 1, i);
            }
            if(ch) puts("1");
            else puts("0");
        }

    }
	return 0;
}
