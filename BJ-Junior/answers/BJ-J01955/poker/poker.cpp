#include <bits/stdc++.h>
using namespace std;
#define int long long
const char hua[] = {'D', 'C', 'H', 'S'};
const char shu[] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
const int N = 1e3 + 10;

int n, ans;
bool k[N][N];

void insert()
{
    cin >> n;
    char a, b;
    for(int i = 1; i <= n; i++)
    {
        cin >> a >> b;
        k[a][b] = 1;
    }
}

void work()
{
    insert();   
    for(int i = 0; i <= 3; i++) 
        for(int j = 0; j <= 12; j++)
            ans += (!k[hua[i]][shu[j]]);
    cout << ans << endl;
}

signed main()
{
    freopen("poker.out", "w", stdout);
    freopen("poker.in", "r", stdin);
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    work();
}