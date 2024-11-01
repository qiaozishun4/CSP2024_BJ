#include <bits/stdc++.h>
using namespace std;

const int NR = 2e5 + 5;
const int MR = 1e6 + 5;
int n, a[NR], box[MR];
bool debug = false;

vector <int> g;

int main()
{
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);

    int T;
    cin >> T;
    while (T--)
    {
        cin >> n;
        memset(box, 0, sizeof(box));
        g.clear();
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            if (box[a[i]] == 0) g.push_back(a[i]);
            box[a[i]]++;
        }

        if (debug)
        {
            for (auto i: g)
                cout << i << ": " << box[i] << endl;
        }

        int ans = 0;
        for (auto i: g) if (box[i] >= 2) ans += (box[i] / 2) * i;
        cout << ans << endl;
    }
    return 0;
}