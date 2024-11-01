#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int che[100001];

int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    int n, temp;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        che[temp]++;
    }
    for (int i = 0; i < 100001; i++)
    {
        ans = max(ans, che[i]);
    }
    cout << ans;
    return 0;
}
