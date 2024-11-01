#include <cstdio>
#include <algorithm>
using namespace std;

int n , a[100005] , cnt = 1;

int main()
{
    freopen("duel.in" , "r" , stdin);
    freopen("duel.out" , "w" , stdout);
    scanf("%d" , &n);
    for (int i = 1; i <= n; i++) scanf("%d" , &a[i]);
    //int tmp = 0;
    //for (int i = 1; i <= n; i++) if (a[i] == 1) tmp++;
    //printf("%d\n" , tmp);
    sort(a + 1 , a + n + 1);
    int i;
    for (i = 1; i <= n && cnt <= n; i++)
    {
        while (a[i] >= a[cnt] && cnt <= n) cnt++;
        if (cnt > n) break;
        cnt++;
    }
    //printf("%d %d\n", i , cnt);
    printf("%d" , n - i + 1);

    return 0;
}
