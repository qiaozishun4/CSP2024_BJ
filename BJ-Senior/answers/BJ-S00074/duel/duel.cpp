#include<bits/stdc++.h>
using namespace std;

const int maxn=1e5+1;
int n,a[maxn],f[maxn],cnt=0;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        f[a[i]]++;
    }
    for(int i=1;i<=maxn;i++){
        cnt=max(cnt,f[i]);
    }

    printf("%d\n",cnt);
    return 0;
}