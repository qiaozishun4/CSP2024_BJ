#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 100005;
int n;
int a[N];

int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    //14:34
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    sort(a + 1, a + 1 + n);
    int j = 1;
    for (int i = 2; i <= n; i++)
    {
        if (a[i] > a[j])
            j++;
    }
    printf("%d\n", n - j + 1);
    return 0;
}
