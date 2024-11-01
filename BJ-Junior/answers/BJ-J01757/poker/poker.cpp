#pragma GCCoptimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
using namespace std;
vector<string> a;
int n, pos = 1;
string b;
int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1 ; i <= n ; i++)
    {
        cin >> b;
        bool f = 0;
        for (int j = 0 ; j < a.size() ; j++)
        {
            if (a[j] == b)
            {
                f = 1;
            }
        }
        if (f == 0)
        {
            a.push_back(b);
        }
    }
    cout << 52-a.size() << endl;

    fclose(stdin);
    fclose(stdout);

    return 0;
}
