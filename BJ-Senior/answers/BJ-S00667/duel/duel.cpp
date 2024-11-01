#include<bits/stdc++.h>
using namespace std;
int n,r[114514],ans;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        int a;
        scanf("%d",&a);
        ++r[a];
    }
    for(int i=0;i<=1e5;++i){
        ans=max(0,ans-r[i]);
        ans+=r[i];
    }
    printf("%d",ans);
    return 0;
}
