#include <bits/stdc++.h>
using namespace std;
int b[1000010];
void fre(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
}
int main(){
    fre();
    int n,ans=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int a;
        scanf("%d",&a);
        b[a]++;
    }
    for(int i=1;i<=1000005;i++){
        ans=max(ans,b[i]);
    }
    printf("%d",ans);
    return 0;
}
