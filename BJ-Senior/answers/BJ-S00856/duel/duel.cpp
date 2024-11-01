#include<bits/stdc++.h>
using namespace std;
int n,r[100005];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&r[i]);
    }
    sort(r+1,r+n+1,greater<int>());
    int l=1,ans=n;
    for(int i=1;i<=n;i++){
        while(l<=n&&r[i]<=r[l])l++;
        if(l<=n){
            l++;
            ans--;
        }
        else break;
    }
    printf("%d",ans);
    return 0;
}
