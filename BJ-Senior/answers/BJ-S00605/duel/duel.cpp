#include<bits/stdc++.h>
using namespace std;
int n,a[114514],ans;
priority_queue<int> b;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    scanf("%d",&n);ans=n;
    for(int i=1;i<=n;i++) scanf("%d",a+i);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        if(b.size()&&(-a[i])<b.top()) b.pop(),ans--;
        b.push(-a[i]);
    }
    printf("%d",ans);
    return 0;
}
