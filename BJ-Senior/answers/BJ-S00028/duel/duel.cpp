#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

struct Node
{
    int x, y;
    bool operator < (const Node& b) const
    {
        return y < b.y;
    }
};
int a[100005], cnt[100005];

int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    int n;
    cin >> n;

    cout << n - (n + 1) / 2 << endl;
    return 0;
}