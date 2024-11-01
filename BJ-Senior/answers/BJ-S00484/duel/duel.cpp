#include<bits/stdc++.h>
using namespace std;
int n,a[100010],ans[100010],cnt,ma;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        if(a[i-1]<a[i]){
            cnt++;
        }
        ans[cnt]++;
    }
    for(int i=2;i<=cnt;i++){
        ma+=min(ans[i],ans[i-1]);
        ans[i]+=max(ans[i-1]-ans[i],0);
    }
    printf("%d",n-ma);
    return 0;
}
