#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
int n, A[MAXN];
int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) scanf("%d", &A[i]);
    sort(A + 1, A + n + 1);
    int cnt = n;
    for(int i = 1, j = 1; i <= n; i ++)
    {
        if(j < i && A[j] < A[i])
        {
            j ++;
            cnt --;
        }
    }
    printf("%d\n", cnt);
    return 0;
}
