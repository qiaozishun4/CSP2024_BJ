#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,r[N],ans;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    scanf("%d",&n);
    ans=n;
    for(int i=1;i<=n;i++) scanf("%d",&r[i]);
    sort(r+1,r+n+1);
    for(int i=1,j=2;i<=n&&j<=n;i++,j++){
        while(j<=n&&r[i]>=r[j]) j++;
        if(r[i]>=r[j]) break;
        ans--;
    }
    printf("%d\n",ans);
    return 0;
}