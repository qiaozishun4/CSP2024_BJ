#include <cstdio>
#include <algorithm>
using namespace std;
int n,a[100010],jian,cnt;
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    scanf("%d",&n);
    for (int i = 1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    for (int i = 1;i<=n;i++)
    {
        if(a[i] == a[i-1]) cnt++;
        else cnt = 0;
        if(i-cnt-1 > jian) jian++;
    }
    printf("%d\n",n-jian);
    return 0;
}
