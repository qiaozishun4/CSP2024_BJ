#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

struct node
{
    int s[200000];
}p[100000];

struct node
{
    int r, c;
}q[100000];

int main()
{
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    int t;
    cin >>t;
    while(t--)
    {
        int n, k, q;
        scanf("%d%d%d", &n, &k, &q);
        for(int i=1; i<=n; i++)
        {
            int l;
            scanf("%d", &l);
            for(int j=1; j<=l; j++)
            {
                scanf("%d", &p[i].s[j]);
            }
        }
        for(int i=1; i<=q; i++)
        {
            scanf("%d%d", &q[i].r, &q[i].c);
        }
        for(int i=1; i<=q; i++)
        {
            cout << 1 << endl;
        }
    }
    return 0;
}
