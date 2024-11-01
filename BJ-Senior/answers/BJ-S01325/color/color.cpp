#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    int t;
    cin >> t;
    while(t--)
    {
        map<int, int> m;
        int n;
        long long sum = 0;
        cin >> n;
        for(int i = 1;i <= n;i++)
        {
            int a;
            cin >> a;
            m[a]++;
            if(m[a] > 1) sum += a;
        }
        cout << sum << "\n";
    }
    return 0;
}
