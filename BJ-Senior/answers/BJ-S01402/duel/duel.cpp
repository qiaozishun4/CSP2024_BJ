#include <iostream>
#include <cstdio>
const int N=1e5+5;
int n,a[N],h[N],mx,cnt;
using namespace std;
int main() {
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        h[a[i]]++;
        mx=max(mx,a[i]);
    }
    for(int i=1;i<=mx;i++){
        cnt=max(0,cnt-h[i]);
        cnt+=h[i];
    }
    printf("%d",cnt);
    return 0;
}