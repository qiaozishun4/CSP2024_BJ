#include<iostream>
#include<algorithm>
using namespace std;
int a[100005];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    scanf("%d",&n);
    int x;
    for(int i=1;i<=100000;i++) a[i]=0;
    for(int i=1;i<=n;i++) scanf("%d",&x),a[x]++;
    int ans;
    ans=0;
    for(int i=1;i<=100000;i++){
        ans=max(ans,a[i]);
    }
    printf("%d\n",ans);
    return 0;
}
