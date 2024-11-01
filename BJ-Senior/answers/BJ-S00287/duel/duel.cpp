#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
int n;
int a[MAXN];

int main(){
    #ifndef kevin
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    #endif
    scanf("%d",&n);
    for (int i = 1;i <= n;i ++)scanf("%d",a + i);
    sort(a + 1,a + n + 1);
    int l = 1;
    for (int i = 1;i <= n;i ++)
        if (a[i] != a[l])l ++;
    printf("%d",n - l + 1);
    return 0;
}