#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
const int MR = 1e5 + 3;
const int NR = 2e5 + 5;
int n, k, q;
vector<int> s[NR];
//int s1[MR][NR];
int l[NR];
// bool flag[NR];
bool dp[2][NR / 20][MR / 10];
void solve1(int r, int c)
{
   for(int i = 1; i <= n; i++)
   {
       int pos = -1;
       for(int j = 1; j <= l[i]; j++)
       {
            if(s[i][j] == 1) pos = j;
            if(s[i][j] == c && pos != -1 && j - pos + 1 <= k && j - pos + 1 >= 2)
            {
                cout << 1 << endl;
                return ;
            }
       }
   }
   cout << 0 << endl;
   return ;
}
void solve2(int r, int c)
{
    memset(dp, false, sizeof(dp));
    for(int i = 1; i <= n; i++)
    {
        int pos = -1;
        for(int j = 1; j <= l[i]; j++)
        {
            if(s[i][j] == 1) pos = j;
            if(pos != -1 && j - pos + 1 <= k && j - pos + 1 >= 2) dp[1][s[i][j]][i] = true;
        }
    }
    for(int cc = 1; cc <= r; cc++) // n ci jie long
        for(int i = 1; i <= n; i++) // ren
        for(int j = 2; j <= l[i]; j++)  // jie wei zhi
        for(int p = max(j - k + 1, 1); p <= max(j - 1, 1); p++)
            for(int ccf = 1; ccf <= n; ccf++)
                if(ccf != i)dp[(cc) & 1][s[i][j]][i] |= dp[(cc-1) & 1][s[i][p]][ccf];
    for(int ccf = 1; ccf <= n; ccf++)
    {
        if(dp[r & 1][c][ccf]) {cout << 1 <<endl;; return ;}
    }
    cout << 0 << endl;
}
void solve()
{
    cin >> n >> k >> q;
    for(int i = 1; i <= n ;i++)
    {
        if(s[i].size()) s[i].clear();
        cin >> l[i]; s[i].push_back(0);
        for(int j = 1; j <= l[i]; j++)
        {
            int x;
            cin >> x;
            s[i].push_back(x);
        }
    }
    while(q--)
    {
        int r, c;
        cin >> r >> c;
        if(r == 1) {solve1(r, c); continue;}
        else solve2(r, c);
    }
    for(int i = 1; i <= n; i++) s[i].clear();
}
int main()
{
    //freopen("//home//csp-j//chain1.in", "r", stdin);
    //freopen("//home//csp-j//chain1.out", "w", stdout);
    //cout << sizeof(dp) / 1024 / 1024 << endl;
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
