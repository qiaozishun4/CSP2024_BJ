#include <iostream>
using namespace std;
const int MAXN = 105;
char c1[MAXN], c2[MAXN];
int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> c1[i] >> c2[i];
        bool f = true;
        for (int j = 0; j < i; j++)
            if (c1[j] == c1[i] && c2[j] == c2[i])
            {
                f = false;
                break;
            }
        if (f)
            cnt++;
    }
    cout << 52 - cnt << '\n';
    return 0;
}
