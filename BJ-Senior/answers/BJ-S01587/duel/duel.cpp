#include <bits/stdc++.h>
using namespace std;
int n,a[100010],ans,idx;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    scanf("%d",&n);
    ans=n;
    for(int i=1; i<=n; i++) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    idx=2;
    for(int i=1; i<=n; i++){
        while(a[idx]<=a[i] && idx<=n) idx++;
        if(idx<=n){ans--;idx++;}
        else break;
    }
    printf("%d",ans);
    return 0;
}