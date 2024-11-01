#include <bits/stdc++.h>
using namespace std;
int n,x,a[100005];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    scanf("%d",&n);
    int maxn=0;
    for(int i=1;i<=n;i++) scanf("%d",&x),maxn=max(maxn,(++a[x]));
    printf("%d",maxn);
    return 0;
}
