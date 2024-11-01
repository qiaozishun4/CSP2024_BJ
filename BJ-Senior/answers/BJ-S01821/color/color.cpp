//FORCE!!
#include <iostream>
#include <cstring>
typedef long long LL;

using namespace std;

const int N = 2e5+5;

int T;
int n;
LL a[N], c[N];
LL ans;

void dfs(LL lastr, LL lastb, LL now, LL sum){   //lastr, lastb and now stores the num(bian hao) of number
    //printf("%d:%d %d, %d\n",now,lastr,lastb,sum);
    ans = max(ans,sum);
    if(now > n) return;
    //make it red
    if(lastr && a[now] == a[lastr]) dfs(now, lastb, now+1, sum+a[now]);
    else dfs(now, lastb, now+1 ,sum);
    //make it blue
    if(lastb && a[now] == a[lastb]) dfs(lastr, now, now+1, sum + a[now]);
    else dfs(lastr, now, now+1, sum);
}

int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        //puts("");
        ans = 0;
        memset(c,0,sizeof(c));
        memset(a,0,sizeof(a));
        scanf("%d",&n);
        for(int i = 1;i <= n;i++){
            scanf("%d",&a[i]);
        }
        dfs(0,0,1,0);
        printf("%lld\n",ans);
    }
    return 0;
}
