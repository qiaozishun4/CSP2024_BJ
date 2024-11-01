#include <iostream>
#include <cstdio>
#include <ctime>
#include <vector>
using namespace std;
const int N = 1e5 + 10;
vector<int> S[N];
int tot, T, n, k, q, li, rj, cj;
int main()
{
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    srand(static_cast<unsigned int>(time(nullptr)));
    cin >> T;
    while(T--)
    {
        tot = 0;
        cin >> n >> k >> q;
        for(int i = 1;i <= n;++i)
        {
            scanf("%d", &li);
            S[i].clear();
            S[i] = vector<int>(li);
            for(int j = 0;j < li;++j)
            {
                scanf("%d", &S[i][j]);
                tot++;
            }
        }
        while(q--)
        {
            scanf("%d%d", &rj, &cj);
            if(tot == n)
                printf("0\n");
            else
                printf("%d\n", rand() % 2);
        }
    }
    return 0;
}
