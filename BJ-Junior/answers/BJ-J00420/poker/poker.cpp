#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int n, T;
struct node
{
    char color, pos;
} a[70];

bool cmp(node x, node y)
{
    if(x.color != y.color) return x.color < y.color;
    return x.pos < y.pos;
}

int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i ++)
        cin >> a[i].color >> a[i].pos;

    sort(a + 1, a + n + 1, cmp);

    int cnt = 0;
    for(int i = 1; i <= n; i ++)
        if(a[i].color != a[i - 1].color || a[i].pos != a[i - 1].pos)
            cnt ++;

    cout << 52 - cnt << endl;

    return 0;
}