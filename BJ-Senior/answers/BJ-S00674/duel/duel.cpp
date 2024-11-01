#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,a[N],c[N],ans;
signed main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    ans=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        c[a[i]]++;
        ans=max(ans,c[a[i]]);
    }
    printf("%d",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}