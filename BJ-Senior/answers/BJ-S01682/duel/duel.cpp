#include<bits/stdc++.h>
using namespace std;
int n,s[100001],ans=0;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int tmp;
        scanf("%d",&tmp);
        s[tmp]++;
        ans=max(ans,s[tmp]);
    }
    printf("%d\n",ans);
    return 0;
}
