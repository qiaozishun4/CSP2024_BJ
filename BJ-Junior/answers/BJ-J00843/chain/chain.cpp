#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int NR = 1e5;
const int MR = 100;
vector<int> v[NR + 5], flag[NR + 5], kk[NR + 5];
bool dp[NR + 5][MR + 5];
int c[NR + 5][MR + 5];
int cox[NR + 5], box[NR + 5];

int main()
{
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        memset(v, 0, sizeof(v));
        for (int i = 1; i <= NR; i++)
            for (int j = 1; j <= MR; j++)
                c[i][j] = 0;
        int n, k, q;
        cin >> n >> k >> q;
        for (int i = 1; i <= n; i++)
        {
            int x;
            cin >> x;
            v[i].push_back(x);
            for (int j = 1; j <= x; j++)
            {
                int y;
                cin >> y;
                v[i].push_back(y);
            }
        }
        // 初始化
        for (int i = 1; i <= n; i++)
        {
            kk[i].push_back(1e9);
            kk[i].push_back(1e9);
            int l = v[i][0];
            for (int j = 1; j <= l - 1; j++)
            {
                if (v[i][j] == 1) kk[i].push_back(1);
                else kk[i].push_back(kk[i][j] + 1);
            }
            /*for (int j = 1; j <= l; j++)
            {
                cout << kk[i][j] << " ";
            }
            cout << '\n';*/
            for (int j = 1; j <= l - 1; j++)
            {
                if (kk[i][j + 1] <= k - 1)
                {
                    if (c[v[i][j + 1]][1] != 0 && c[v[i][j + 1]][1] != i) dp[v[i][j + 1]][1] = true;
                    else c[v[i][j + 1]][1] = i;
                }
            }
        }
        /*for (int i = 1; i <= n; i++)
        {
            int l = v[i][0];
            for (int j = 1; j <= l; j++)
                cout << dp[v[i][j]][1] << " ";
            cout << '\n';
        }*/
        for (int u = 2; u <= MR; u++)
        {
            memset(kk, 0, sizeof(kk));
            memset(flag, 0, sizeof(flag));
            for (int i = 1; i <= n; i++)
            {
                flag[i].push_back(0);
                flag[i].push_back(0);
                int l = v[i][0];
                for (int j = 2; j <= l; j++)
                {
                    if (dp[v[i][j]][u - 1]) flag[i].push_back(1);
                    else if (c[v[i][j]][u - 1] != i) flag[i].push_back(1);
                    else flag[i].push_back(0);
                }
                /*for (int j = 2; j <= l; j++) cout << flag[i][j] << " ";
                cout << '\n';*/
                kk[i].push_back(1e9);
                kk[i].push_back(1e9);
                for (int j = 1; j <= l - 1; j++)
                {
                    if (flag[i][j] == 1) kk[i].push_back(1);
                    else kk[i].push_back(kk[i][j] + 1);
                }
                for (int j = 1; j <= l - 1; j++)
                {
                    if (kk[i][j + 1] <= k - 1)
                    {
                        if (c[v[i][j + 1]][u] != 0 && c[v[i][j + 1]][u] != i) dp[v[i][j + 1]][u] = true;
                        else c[v[i][j + 1]][u] = i;
                    }
                }
            }
        }
        /*for (int u = 2; u <= MR; u++)
            cout << c[2][u] << " ";
        cout << '\n';*/
        for (int i = 1; i <= n; i++)
        {
            int l = v[i][0];
            for (int j = 1; j <= l; j++)
            {
                if (cox[v[i][j]] != 0 && cox[v[i][j]] != i) box[v[i][j]] = 1;
                if (cox[v[i][j]] == 0) cox[v[i][j]] = i;
            }
        }
        while (q--)
        {
            int r, t;
            cin >> r >> t;
            if (dp[t][r]) cout << "1\n";
            else if (c[t][r] != 0 && box[t] == 1) cout << "1\n";
            else if (c[t][r] != 0 && cox[t] != 0 && c[t][r] != cox[t]) cout << "1\n";
            else cout << "0\n";
        }
    }
    return 0;
}
