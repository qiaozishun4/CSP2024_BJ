#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
int a[MAXN],b[MAXN];
int main ()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    scanf("%d",&n);
    for (int i = 1;i <= n;i++) scanf("%d",&a[i]);
    sort(a + 1,a + n + 1);
    int tot = 0,cnt = 1;
    for (int i = 2;i <= n;i++)
    {
        if(a[i] != a[i - 1])
        {
            b[++tot] = cnt;
            cnt = 1;
        }
        else
        {
            cnt++;
        }
    }
    b[++tot] = cnt;
    int die = 0,now = 0;
    for (int i = 1;i <= tot;i++)
    {
        if(b[i] >= now)
        {
            die += now;
            now = b[i];
        }
        else
        {
            die += b[i];
        }
    }
    printf("%d",n - die);
    return 0;
}
